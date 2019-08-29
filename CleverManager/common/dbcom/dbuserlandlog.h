#ifndef DBUSERLANDLOG_H
#define DBUSERLANDLOG_H
#include "db_user.h"

struct sLandLogItem : public DbBasicItem{
    sLandLogItem(){}
    QString name,remarks;
};

class DbLandLog : public SqlBasic<sLandLogItem>
{
    DbLandLog();
public:
    static DbLandLog* get();
    QString tableName(){return "landlogs";}
    bool insertItem(sLandLogItem& item);

protected:
    void createTable();
    bool modifyItem(const sLandLogItem &item, const QString &cmd);
};

#endif // DBUSERLANDLOG_H
