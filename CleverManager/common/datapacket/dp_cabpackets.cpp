#include "dp_cabpackets.h"

Dp_CabPackets::Dp_CabPackets(QObject *parent) : QThread(parent)
{
    isRun = true;
    mDb = DbCabinetList::get();
    mPdus = Dp_PduPackets::bulid(this);
    mCabHrs = Dp_CabHrsSave::bulid(this);
    connect(mDb,SIGNAL(itemChanged(int,int)),SLOT(cabinetItemChange(int,int)));
    start();
}

Dp_CabPackets::~Dp_CabPackets()
{
    isRun = false;
    wait();
}

Dp_CabPackets *Dp_CabPackets::bulid(QObject *parent)
{
    static Dp_CabPackets* sington = NULL;
    if(sington == NULL) {
        sington = new Dp_CabPackets(parent);
    }
    return sington;
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
        cab->en = 1;
        cab->count = 0;
        cab->room_id = it.room_id;
        cab->cab_id = it.id;

        if(!it.main_ip.isEmpty()) {
            cab->m = mPdus->get(it.main_ip, it.main_num);
            cab->m->en = 1;
        } else {
            cab->m = nullptr;
        }

        if(!it.spare_ip.isEmpty()) {
            cab->s = mPdus->get(it.spare_ip, it.spare_num);
            cab->s->en = 1;
        } else {
            cab->s = nullptr;
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
        delCab(id);
    }
}

void Dp_CabPackets::initFun()
{
    QVector<int> ids = mDb->selectIds();
    for(int i=0; i<ids.size(); ++i) {
        cabinetItemChange(ids.at(i), 1);
    }
}

sCabPacket *Dp_CabPackets::getByCab(uint id)
{
    sCabPacket *pack = nullptr;
    QHashIterator<QString, sCabPacket *> iter(mHash);
    while(iter.hasNext()) {
        pack = iter.next().value();
        if(pack) {
            if(pack->cab_id == id) {
                break;
            }
        }
    }

    return pack;
}

QVector<sCabPacket *> Dp_CabPackets::getByRoom(uint id)
{
    sCabPacket *pack = nullptr;
    QVector<sCabPacket *> packs;
    QHashIterator<QString, sCabPacket *> iter(mHash);

    while(iter.hasNext()) {
        pack = iter.next().value();
        if(pack) {
            if(pack->room_id == id) {
                packs.append(pack);
            }
        }
    }

    return packs;
}

void Dp_CabPackets::dels(QVector<sCabPacket *> &packs)
{
    sCabPacket *pack = nullptr;
    for(int i=0; i<packs.size(); ++i) {
        pack = packs.at(i);
        pack->en = 0;
    }
}

void Dp_CabPackets::delCab(uint id)
{
    sCabPacket *pack = getByCab(id);
    if(pack) {
        pack->en = 0;
    }
    mPdus->delCab(id);
}

void Dp_CabPackets::delRoom(uint id)
{
    QVector<sCabPacket *> packs = getByRoom(id);
    dels(packs);
    mPdus->delRoom(id);
}

int Dp_CabPackets::getStatus(sDataPacket *pack)
{
    int ret = -1;
    if(pack) {
        if((pack->offLine > 0) && pack->en){
            ret = pack->alarm;
        }
    }

    return ret;
}





void Dp_CabPackets::tgCabData(sCabPacket *cab)
{
    sTgObjData *tg = &(cab->tg);
    QVector<sDataPacket *> packs;
    packs << cab->m << cab->s;
    mPdus->tgDataPackts(tg, packs);

    cab->status = getStatus(cab->m);
    cab->status += getStatus(cab->s);
}

void Dp_CabPackets::workDown()
{
    QHashIterator<QString, sCabPacket *> iter(mHash);
    while(iter.hasNext())
    {
        iter.next();
        if(iter.value()) {
            sCabPacket *pack = iter.value();
            if(pack->en) {
                pack->count++;
                tgCabData(pack);
                mCabHrs->save(pack);
            }
        }
        msleep(15 + rand()%15);
    }
}

void Dp_CabPackets::run()
{
    initFun();
    while (isRun) {
        sleep(1);
        workDown();
    }
}
