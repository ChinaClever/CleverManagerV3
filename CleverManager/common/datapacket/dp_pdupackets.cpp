#include "dp_pdupackets.h"

Dp_PduPackets::Dp_PduPackets(QObject *parent) : DataPackets(parent)
{
    mDb = DbPduDevices::get();
    mHrs = Dp_PduHrsSave::bulid(this);
    mAlarm = Dp_PduAlarm::bulid(this);
    connect(mDb,SIGNAL(itemChanged(int,int)),SLOT(pduItemChange(int,int)));
}


Dp_PduPackets *Dp_PduPackets::bulid(QObject *parent)
{
    static Dp_PduPackets* sington = NULL;
    if(sington == NULL) {
        sington = new Dp_PduPackets(parent);
    }
    return sington;
}


sDataPacket *Dp_PduPackets::newDataPacket()
{
    sDataPacket *pack = new sDataPacket;
    if(pack) {
        for(int i=0; i<LINE_NUM; ++i) {
            pack->data.line.name[i] = QString("Line %1").arg(i+1);
        }

        for(int i=0; i<LOOP_NUM; ++i) {
            pack->data.loop.name[i] = QString("Loop %1").arg(i+1);
        }

        for(int i=0; i<OUTPUT_NUM; ++i) {
            pack->data.output.name[i] = QString("Output %1").arg(i+1);
        }
    } else {
        qDebug() << "Dp_PduPackets new err";
    }


    return pack;
}

void Dp_PduPackets::initPacket(PduDeviceItem &it)
{
    sDataPacket *pack = get(it.ip, it.dev_num);
    if(pack) {
        pack->en = 1;
        pack->count = 0;
        pack->pdu_id = it.id;
        pack->room_id = it.room_id;
        pack->cab_id = it.cab_id;

        pack->room = it.room;
        pack->cab = it.cab;
        pack->road = it.road;
        pack->ip.ip = it.ip;
        pack->dev_num = it.dev_num;
        pack->dev_type = it.dev_type;
    }
    QCoreApplication::processEvents(QEventLoop::AllEvents,1);
}

void Dp_PduPackets::initFun()
{
    QVector<int> ids = mDb->selectIds();
    for(int i=0; i<ids.size(); ++i) {
        pduItemChange(ids.at(i), 1);
    }
}

void Dp_PduPackets::pduItemChange(int id,int type)
{
    if(type) {
        PduDeviceItem it = mDb->findById(id);
        initPacket(it);
    } else {
        delPdu(id);
    }
}

void Dp_PduPackets::workDown(sDataPacket *pack)
{
    if(pack->offLine > 0) {
        pack->offLine--;

        mAlarm->alarm(pack);
        mHrs->save(pack);
        tgDevData(pack->data);
    }
}
