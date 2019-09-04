#include "datapackets.h"

DataPackets::DataPackets(QObject *parent) : QObject(parent)
{

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
    sObjData *tg = &(dev.tg);
    sObjData *obj = &(dev.line);
    int size = obj->size;

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

