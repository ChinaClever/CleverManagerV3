/*
 * 配置文件公共基类
 *
 *  Created on: 2018年1月1日
 *      Author: Lzy
 */
#include "configbase.h"

ConfigBase::ConfigBase()
{
    item = new sConfigItem();
    item->sound = getSound();
    item->logTimes = getLogTime();
    item->elePrice = getElePrice();
}


/**
 * @brief 获取日志存储时间隔
 * @return
 */
int ConfigBase::getLogTime()
{
    QString prefix = getPrefix();
    QString str = QString("%1_log_time").arg(prefix);
    int ret = com_cfg_readInt(str, prefix);
    if(ret <= 0)  ret = 24;
    return ret;
}

/**
 * @brief 设置日志存储时间间隔
 * @param num
 */
void ConfigBase::setLogTime(int num)
{
    QString prefix = getPrefix();
    QString str = QString("%1_log_time").arg(prefix);
    com_cfg_writeParam(str, QString::number(num), prefix);
}



/**
 * @brief 获取单价
 * @return
 */
double ConfigBase::getElePrice()
{
    QString prefix = getPrefix();
    QString str = QString("%1_ele_price").arg(prefix);
    double ret = com_cfg_readDouble(str, prefix);
    if(ret < 0)  ret = 1;
    return ret;
}

/**
 * @brief 设置单价
 * @param num
 */
void ConfigBase::setElePrice(double p)
{
    QString prefix = getPrefix();
    QString str = QString("%1_ele_price").arg(prefix);
    com_cfg_writeParam(str, QString::number(p), prefix);
}


/**
 * @brief 获取日志存储时间隔
 * @return
 */
int ConfigBase::getSound()
{
    QString prefix = getPrefix();
    QString str = QString("%1_sound_sw").arg(prefix);
    int ret = com_cfg_readInt(str, prefix);
    if(ret <= 0)  ret = 1;
    return ret;
}

/**
 * @brief 设置日志存储时间间隔
 * @param num
 */
void ConfigBase::setSound(int s)
{
    QString prefix = getPrefix();
    QString str = QString("%1_sound_sw").arg(prefix);
    com_cfg_writeParam(str, QString::number(s), prefix);
}
