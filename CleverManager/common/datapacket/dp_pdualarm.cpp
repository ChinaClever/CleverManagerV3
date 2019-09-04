#include "dp_pdualarm.h"
#include "sound.h"
#include "dbpdualarm.h"

Dp_PduAlarm::Dp_PduAlarm(QObject *parent) : QObject(parent)
{

}


Dp_PduAlarm *Dp_PduAlarm::bulid(QObject *parent)
{
    static Dp_PduAlarm* sington = NULL;
    if(sington == NULL) {
        sington = new Dp_PduAlarm(parent);
    }
    return sington;
}

bool Dp_PduAlarm::alarmSalve(const QString&str, uchar value)
{
    sDbAlarmItem item;
    item.room = mPack->room;
    item.modular = mPack->modular;
    item.cab = mPack->cab;
    item.road = mPack->road;
    item.dev_type = mPack->dev_type;
    item.ip = mPack->ip.ip;
    item.dev_num = mPack->dev_num;

    item.item = str;
    item.msg = tr("报警值 %1").arg(value/10.0);
    return DbPduAlarm::bulid()->insertItem(item);
}

bool Dp_PduAlarm::alarmDataUnit(sDataUnit &unit, int size)
{
    bool ret = false;
    for(int i=0; i<size; ++i) {
        if((unit.value[i] > unit.max[i]) || (unit.value[i] < unit.min[i])) {
            if( 0 == unit.alarm[i]) {
                QString str = mItemStr.arg(i+1);
                ret = alarmSalve(str, unit.value[i]);
                if(ret) Sound::bulid()->play();
            }

            unit.alarm[i] = 1;
            ret = true;
            continue;
        }

        unit.alarm[i] = 0;
        if((unit.value[i] > unit.crMax[i]) || (unit.value[i] < unit.crMin[i])){
            unit.crAlarm[i] = 1;
        } else {
            unit.crAlarm[i] = 0;
        }
    }

    return ret;
}


bool Dp_PduAlarm::alarmObjDataUnit(sObjData &obj)
{
    QString str = mItemStr;

    mItemStr = str + tr("电压");
    bool ret = alarmDataUnit(obj.vol, obj.size);

    mItemStr =str + tr("电压");
    ret = ret || alarmDataUnit(obj.cur, obj.size);

    return ret;
}

bool Dp_PduAlarm::alarmEnvData(sEnvData &env)
{
    mItemStr = tr("温度") + " %1 ";
    bool ret = alarmDataUnit(env.tem, env.size);

    mItemStr = tr("湿度") + " %1 ";
    ret = ret || alarmDataUnit(env.hum, env.size);

    return ret;
}

bool Dp_PduAlarm::alarmDevData(sDevData &dev)
{
    mItemStr = "line %1 ";
    bool ret = alarmObjDataUnit(dev.line);

    mItemStr = tr("回路") + " %1 ";
    ret = ret || alarmObjDataUnit(dev.loop);

    mItemStr = tr("输出位") + " %1 ";
    ret = ret || alarmObjDataUnit(dev.output);
    ret = ret || alarmEnvData(dev.env);

    return ret;
}

bool Dp_PduAlarm::alarm(sDataPacket *pack)
{
    bool ret = alarmDevData(pack->data);
    if(ret) {
        pack->alarm = 1;
    }

    return ret;
}
