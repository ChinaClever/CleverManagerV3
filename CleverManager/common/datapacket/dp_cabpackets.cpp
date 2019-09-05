#include "dp_cabpackets.h"

Dp_CabPackets::Dp_CabPackets(QObject *parent) : QThread(parent)
{
    mDb = DbCabinetList::get();
    mPdus = Dp_PduPackets::bulid(this);
    connect(mDb,SIGNAL(itemChanged(int,int)),SLOT(cabinetItemChange(int,int)));
}

sCabPacket *Dp_CabPackets::find(const QString &key)
{
    sCabPacket * node = nullptr;
    bool ret = contains(key);
    if(ret) {
        auto index = mHash.find(key);
        if(index != mHash.end()) {
            node = index.value();
        }
    }

    return node;
}

void Dp_CabPackets::remove(const QString &key)
{
    sCabPacket * node = find(key);
    if(node) {
        mHash.remove(key);
        delete node;
    }
}

sCabPacket *Dp_CabPackets::insert(const QString &key)
{
    sCabPacket *node = find(key);
    if(!node) {
        node = new sCabPacket;
        mHash.insert(key, node);
    }

    return node;
}

sCabPacket *Dp_CabPackets::get(const QString &room, const QString &cab)
{
    QString key = room +";"+ cab;
    return insert(key);
}

void Dp_CabPackets::initPacket(CabinetItem &it)
{
    sCabPacket *cab = get(it.room, it.cab);
    if(cab) {
        cab->room_id = it.room_id;
        cab->cab_id = it.id;

        if(!it.main_ip.isEmpty()) {
            cab->m = mPdus->get(it.main_ip, it.main_num);
            cab->m->en = 1;
        }

        if(!it.spare_ip.isEmpty()) {
            cab->s = mPdus->get(it.spare_ip, it.spare_num);
            cab->s->en = 1;
        }
    }
    QCoreApplication::processEvents(QEventLoop::AllEvents,1);
}

void Dp_CabPackets::cabinetItemChange(int id, int type)
{
    if(type > 0) {
        CabinetItem item = mDb->findById(id);
        initPacket(item);
    } else {
        mPdus->delCab(id);
    }
}

void Dp_CabPackets::initFun()
{
    QVector<int> ids = mDb->selectIds();
    for(int i=0; i<ids.size(); ++i) {
        cabinetItemChange(ids.at(i), 1);
    }
}
