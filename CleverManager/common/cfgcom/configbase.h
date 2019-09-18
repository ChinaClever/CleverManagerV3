#ifndef CONFIGBASH
#define CONFIGBASH
#include "sysconfigfile.h"

struct sConfigItem
{
    int sound;
    double elePrice;
    int logTimes; // 日志间隔时间分钟
};

class ConfigBase
{
    ConfigBase();
public:
    static ConfigBase *bulid();

    sConfigItem *item;

    int getLogTime();
    void setLogTime(int num);

    double getElePrice();
    void setElePrice(double p);

    int getSound();
    void setSound(int s);

    virtual QString getPrefix(){return "con";}
};

#endif // CONFIGBASH
