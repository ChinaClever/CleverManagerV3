#include "datapackets.h"
#include <QtSql>

DataPackets::DataPackets(QObject *parent) : QThread(parent)
{
    isRun = true;
    start();
}

DataPackets::~DataPackets()
{
    isRun = false;
    wait();
}


sDataPacket *DataPackets::find(const QString &key)
{
    sDataPacket * node = nullptr;
    bool ret = contains(key);
    if(ret) {
        auto index = mHash.find(key);
        if(index != mHash.end()) {
            node = index.value();
        }
    }

    return node;
}

sDataPacket *DataPackets::insert(const QString &key)
{
    sDataPacket *node = find(key);
    if(!node) {
        node = newDataPacket();
        mHash.insert(key, node);
    }

    return node;
}

sDataPacket *DataPackets::get(const QString &ip, const QString &dev_num)
{
    QString key = ip +";"+ dev_num;
    return insert(key);
}

sDataPacket *DataPackets::get(const QString &ip, int devNum)
{
    QString dev_num = tr("主机");
    if(devNum) dev_num = tr("副机%1").arg(devNum);

    return get(ip, dev_num);
}



/**
 * @brief 获取平均数据 0视无效数据
 * @param data
 */
int DataPackets::averData(ushort *data, int len)
{
    int size=0, value=0,temp;

    for(int i=0; i< len; ++i)
    {
        temp = data[i];
        if(temp > 0) {
            size++;
            value += temp;
        } else
            temp = 0;
    }

    if(size > 0)
        value /= size;

    return value;
}


void DataPackets::tgDevData(sDevData &dev)
{
    sTgObjData *tg = &(dev.tg);
    sObjData *obj = &(dev.line);
    int size = obj->size;

    memset(tg, 0, sizeof(sTgObjData));
    for(int i=0; i<size; ++i)
    {
        tg->cur += obj->cur.value[i];
        tg->pow += obj->pow[i];
        tg->ele += obj->ele[i];
        tg->activePow += obj->activePow[i];
    }
    tg->vol = averData(obj->vol.value, size);
    if(tg->activePow > 0)
        tg->pf = (tg->pow * 100.0 / tg->activePow);
    else
        tg->pf = 0;
    if(tg->pf>99) tg->pf = 99;
    //    tg->pf = averData(obj->pf);
}

void DataPackets::delPdu(uint id)
{
    sDataPacket *pack = nullptr;
    QHashIterator<QString, sDataPacket *> iter(mHash);
    while(iter.hasNext()) {
        pack = iter.next().value();
        if(pack) {
            if(pack->pdu_id == id) {
                pack->en = 0;
                pack->offLine = -1;
            }
        }
    }
}

void DataPackets::delCab(uint id)
{
    sDataPacket *pack = nullptr;
    QHashIterator<QString, sDataPacket *> iter(mHash);

    while(iter.hasNext()) {
        pack = iter.next().value();
        if(pack) {
            if(pack->cab_id == id) {
                pack->en = 0;
                pack->offLine = -1;
            }
        }
    }
}

void DataPackets::delRoom(uint id)
{
    sDataPacket *pack = nullptr;
    QHashIterator<QString, sDataPacket *> iter(mHash);

    while(iter.hasNext())
    {
        pack = iter.next().value();
        if(pack) {
            if(pack->room_id == id) {
                pack->en = 0;
                pack->offLine = -1;
            }
        }
    }
}





void DataPackets::workDown()
{
    QHashIterator<QString, sDataPacket *> iter(mHash);
    while(iter.hasNext())
    {
        iter.next();
        if(iter.value()) {
            sDataPacket *pack = iter.value();
            if((pack->offLine > 0) && (pack->en)) {
                pack->offLine--;
                pack->count++;

                QSqlDatabase::database().transaction();
                workDown(pack);
                QSqlDatabase::database().commit();
            }
        }
        msleep(15 + rand()%15);
    }
}

void DataPackets::run()
{
    initFun();
    while (isRun) {
        sleep(1);
        workDown();
    }
}
