#include "dbuserlandlog.h"

DbUserLandLog::DbUserLandLog()
{
    createTable();
    tableTile = tr("用户登陆日志");
//    hiddens << 1 << 2 << 5 << 9;
    headList << tr("用户名") << tr("描述");
}


void DbUserLandLog::createTable()
{
    QString cmd =
            "create table if not exists %1("
            "id             INTEGER primary key autoincrement not null,"
            "date           VCHAR,"
            "time           VCHAR,"
            "name           VCHAR,"
            "remarks        VCHAR);";
    QSqlQuery query;
    if(!query.exec(cmd.arg(tableName()))) {
        throwError(query.lastError());
    }
}


DbUserLandLog *DbUserLandLog::get()
{
    static DbUserLandLog* sington = nullptr;
    if(sington == nullptr)
        sington = new DbUserLandLog();
    return sington;
}


bool DbUserLandLog::insertItem(sLandLogItem &item)
{
    item.id = maxId()+1;
    QString cmd = "insert into %1 (date,time,name,remarks) "
                  "values(:date,:time,:name,:remarks)";
    return modifyItem(item,cmd.arg(tableName()));
}


bool DbUserLandLog::modifyItem(const sLandLogItem &item, const QString &cmd)
{
    QSqlQuery query;
    query.prepare(cmd);
    query.bindValue(":date",item.date);
    query.bindValue(":time",item.time);
    query.bindValue(":name",item.name);
    query.bindValue(":remarks",item.remarks);
    bool ret = query.exec();
    if(!ret)  throwError(query.lastError());
    return ret;
}
