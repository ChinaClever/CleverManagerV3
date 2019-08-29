#ifndef DBDEVALARM_H
#define DBDEVALARM_H
#include "basicsql.h"

struct sDbAlarmItem : public DbBasicItem
{
    sDbAlarmItem():devnum(0){}
    QString room, modular, cab, road;
    QString devtype, ip;
    int devnum;
    QString item, msg;
};

class DbPduAlarm : public SqlBasic<sDbAlarmItem>
{
    DbPduAlarm();
public:
    static DbPduAlarm* get();
    QString tableName(){return "pdualarmlogs";}
    bool insertItem(sDbAlarmItem& item);

protected:
    void createTable();
    bool modifyItem(const sDbAlarmItem &item, const QString &cmd);
};

#endif // DBDEVALARM_H
