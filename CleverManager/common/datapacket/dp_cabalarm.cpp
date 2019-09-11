#include "dp_cabalarm.h"

Dp_CabAlarm::Dp_CabAlarm(QObject *parent) : QObject(parent)
{

}


Dp_CabAlarm *Dp_CabAlarm::bulid(QObject *parent)
{
    static Dp_CabAlarm* sington = NULL;
    if(sington == NULL) {
        sington = new Dp_CabAlarm(parent);
    }
    return sington;
}

void Dp_CabAlarm::alarm(sCabPacket *cab)
{
    mCab = cab;

    if(cab->tg.pow > cab->pow) {
        if(cab->powAlarm == 0) {
            cab->powAlarm = 1;

            sDbCabAlarmItem item;
            item.room = cab->room;
            item.cab = cab->cab;
            item.modular = cab->modular;
            item.item = tr("功率过大");
            item.msg = tr("机柜最大功率 %1 实际功率 %2").arg(cab->pow).arg(cab->tg.pow);
        }
    } else {
         cab->powAlarm = 0;
    }
}