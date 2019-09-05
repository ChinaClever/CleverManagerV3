#ifndef DATAPACKET_H
#define DATAPACKET_H
#include <QtCore>

#define LINE_NUM  3
#define LOOP_NUM  6
#define OUTPUT_NUM 42
#define SENOR_NUM 4
#define NAME_SIZE 32
#define DEV_NUM 33
#define ARRAY_SIZE 255 //一包数据最长
#define PACK_ARRAY_SIZE 42

// 倍率定义
#define COM_RATE_VOL	1.0    // 电压
#define COM_RATE_CUR	10.0    // 电流
#define COM_RATE_POW	1000.0  // 功率
#define COM_RATE_ELE	10.0    // 电能
#define COM_RATE_PF     100.0   // 功率因素
#define COM_RATE_TEM	1.0    // 温度
#define COM_RATE_HUM	1.0    // 湿度

/**
 * 数据单元：包括当前值，阈值，临界值，告警状态等
 */
struct sDataUnit
{
    ushort value[PACK_ARRAY_SIZE]; // 值
    ushort min[PACK_ARRAY_SIZE]; // 最小值
    ushort max[PACK_ARRAY_SIZE]; // 最大值
    uchar alarm[PACK_ARRAY_SIZE]; // 报警值 0表示未报警  1表示已报警 2表示已纪录

    ushort crMin[PACK_ARRAY_SIZE]; // 最小值
    ushort crMax[PACK_ARRAY_SIZE]; // 最大值
    uchar crAlarm[PACK_ARRAY_SIZE]; // 报警值 0表示未报警  1表示已报警 2表示已纪录
};

/**
 * 数据对象：包括电流，电压，功率，电能，开关状态，插接位名称
 */
struct sObjData
{
    sObjData() {size=0;}
    int size;
    sDataUnit vol; // 电压
    sDataUnit cur; // 电流

    QString name[PACK_ARRAY_SIZE];
    ushort pow[PACK_ARRAY_SIZE]; // 功率
    uint ele[PACK_ARRAY_SIZE]; // 电能

    uchar pf[PACK_ARRAY_SIZE]; // 功率因素
    uchar sw[PACK_ARRAY_SIZE]; // 开关状态 0 表示未启用

    uchar hz[PACK_ARRAY_SIZE]; // 电压频率
    ushort activePow[PACK_ARRAY_SIZE]; // 有功功率值

    uint ratedCur[PACK_ARRAY_SIZE]; // 额定电流
    uint wave[PACK_ARRAY_SIZE]; // 谐波值
    uint tem[PACK_ARRAY_SIZE];
    uchar delay[PACK_ARRAY_SIZE];

    ushort pl[PACK_ARRAY_SIZE]; // 负载百分比
    ushort curThd[PACK_ARRAY_SIZE]; // 电流谐波含量
    ushort volThd[PACK_ARRAY_SIZE]; // 电压谐波含量
};

struct sTgObjData
{
    int vol; // 电压
    int cur;  // 电流
    int pow; // 功率

    int ele; // 电能
    int pf; // 功率因素
    int activePow; // 袖在功率
    int tem;
    uchar status;
};

/**
 * 环境数据结构体
 */
struct sEnvData
{
    sEnvData() {size=0;}
    uchar size;

    QString name[SENOR_NUM];
    sDataUnit tem; // 温度
    sDataUnit hum; // 湿度

    uchar door[SENOR_NUM]; // 门禁
    uchar water[SENOR_NUM]; // 水浸
    uchar smoke[SENOR_NUM]; // 烟雾
};

/**
 * 设备数据结构体：
 */
struct sDevData
{
    sObjData line; // 相数据
    sObjData loop; // 回路数据
    sObjData output; //位数据
    sTgObjData tg; // 回路数据
    sEnvData env; // 环境数据
};

/**
 * RTU传输统计结构体
 */
struct sRtuCount
{
    uint count;
    uint okCount;
    uint errCount;

    uint longCount; // 连续丢命令
    uint longFlag;
};


struct sIpAddr
{
    QString ip;
    QString mask;
    QString gw;
    QString dns;
    QString mac;
};

/**
 * 数据包
 */
struct sDataPacket
{
    sDataPacket() {offLine=0; alarm=0; count=0; en=1;}

    uchar id, en;  // 设备号
    uint devType; //设备类型
    uchar devSpec; // 设备规格 A\B\C\D
    uchar txType; // 通讯类型 0  1:SNMP  2：Zebra

    uchar alarm; // 工作状态 ==0 正常
    char offLine; //离线标志 > 0在线

    QString name; // 设备名称
    QString user, pwd;
    QString dev_num, dev_type;
    QString room,modular,cab, road;
    QString versionStr;

    sIpAddr ip; //设备IP
    sDevData data; //设备数据
    sRtuCount rtuCount; // 传输情况

    uchar lps; // 防雷开关
    uchar dc; // 交直流标志位
    uchar hz; // 电压频率
    ushort br;  // 00	表示波特率9600(00默认9600，01为4800，02为9600，03为19200，04为38400)

    ushort version;
    ushort reserve;
    uint count;

    uint room_id;
    uint cab_id;
    uint pdu_id;
};

struct sThdData {
    ushort curThd[35]; // 电流谐波含量
    ushort volThd[35]; // 电压谐波含量
};

struct sBusPacket : public sDataPacket
{
    sThdData thd;  // 谐波含量
};

struct sCabPacket
{
    sCabPacket() {m=s=nullptr; count=0;}

    uint room_id, cab_id, count;
    QString room,modular,cab;
    sDataPacket *m, *s;
    sTgObjData tg;
};
#endif // DATAPACKET_H
