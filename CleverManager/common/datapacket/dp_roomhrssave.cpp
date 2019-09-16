#include "dp_roomhrssave.h"

Dp_RoomHrsSave::Dp_RoomHrsSave(QObject *parent) : QObject(parent)
{

}

Dp_RoomHrsSave *Dp_RoomHrsSave::bulid(QObject *parent)
{
    static Dp_RoomHrsSave* sington = NULL;
    if(sington == NULL) {
        sington = new Dp_RoomHrsSave(parent);
    }
    return sington;
}

bool Dp_RoomHrsSave::saveItem(sDbRoomHrsItem &item)
{
    return DbRoomHrs::bulid()->insertItem(item);
}

sDbRoomHrsItem Dp_RoomHrsSave::initItem()
{
    sDbRoomHrsItem item;
    item.room = mRoom->room;
    return item;
}

bool Dp_RoomHrsSave::tgObjData(sTgObjData &obj)
{
    bool ret = false;
    sDbRoomHrsItem item = initItem();

    item.vol = obj.vol / COM_RATE_VOL;
    item.cur = obj.cur/ COM_RATE_CUR;
    item.pow = obj.pow/ COM_RATE_POW;
    item.pf = obj.pf/ COM_RATE_PF;
    item.ele = obj.ele/ COM_RATE_ELE;
    if(obj.vol > 0)
        ret = saveItem(item);

    return ret;
}


bool Dp_RoomHrsSave::checkCount(int count)
{
    bool ret = false;
    if(count > 6) { // 数据纪录间隔时间
        ret =  true;
    }

    return ret;
}


void Dp_RoomHrsSave::save(sRoomPacket *room)
{
    mRoom = room;
    bool ret = checkCount(room->count);
    if(ret) {
        room->count = 0;
        tgObjData(room->tg);
    }
}
