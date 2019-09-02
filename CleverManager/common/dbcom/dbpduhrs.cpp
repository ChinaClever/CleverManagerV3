#include "dbpduhrs.h"

DbPduHrs::DbPduHrs()
{
    createTable();
    tableTile = tr("PDU数据纪录");
    hiddens  << 4;
    headList << tr("机房") << tr("模块") << tr("机柜")  << tr("主备路") << tr("设备类型")
             << tr("设备IP") << tr("级联编号") << tr("项目") << tr("开关")
             << tr("电压") << tr("电流") << tr("功率") << tr("功率因素") << tr("电能");
}


void DbPduHrs::createTable()
{
    QString cmd =
            "create table if not exists %1("
            "id             INTEGER primary key autoincrement not null,"
            "date           VCHAR,"
            "time           VCHAR,"
            "room           VCHAR,"
            "modular        VCHAR,"
            "cab            VCHAR,"
            "road           VCHAR,"
            "devtype        VCHAR,"
            "ip             VCHAR,"
            "devnum         VCHAR,"
            "item           VCHAR,"
            "sw             VCHAR,"
            "vol            DOUBLE,"
            "cur            DOUBLE,"
            "pow            DOUBLE,"
            "pf             DOUBLE,"
            "ele            DOUBLE);";
    QSqlQuery query;
    if(!query.exec(cmd.arg(tableName()))) {
        throwError(query.lastError());
    }
}


DbPduHrs *DbPduHrs::bulid()
{
    static DbPduHrs* sington = nullptr;
    if(sington == nullptr)
        sington = new DbPduHrs();
    return sington;
}


bool DbPduHrs::insertItem(sDbPduHrsItem &item)
{
    QString cmd = "insert into %1 (date,time,room,modular,cab,road,devtype,ip,devnum,item,sw,vol,cur,pow,pf,ele) "
                  "values(:date,:time,:room,:modular,:cab,:road,:devtype,:ip,:devnum,:item,:sw,:vol,:cur,:pow,:pf,:ele)";
    return modifyItem(item,cmd.arg(tableName()));
}


bool DbPduHrs::modifyItem(const sDbPduHrsItem &item, const QString &cmd)
{
    QSqlQuery query;
    query.prepare(cmd);
    query.bindValue(":date",item.date);
    query.bindValue(":time",item.time);
    query.bindValue(":room",item.room);
    query.bindValue(":modular",item.modular);
    query.bindValue(":cab",item.cab);
    query.bindValue(":road",item.road);
    query.bindValue(":devtype",item.devtype);
    query.bindValue(":ip",item.ip);
    query.bindValue(":devnum",item.devnum);
    query.bindValue(":item",item.item);
    query.bindValue(":sw",item.sw);
    if(item.vol > 10) {
        query.bindValue(":vol",item.vol);
    } else {
        query.bindValue(":vol","");
    }
    query.bindValue(":cur",item.cur);
    query.bindValue(":pow",item.pow);
    query.bindValue(":pf",item.pf);
    query.bindValue(":ele",item.ele);
    bool ret = query.exec();
    if(!ret)  throwError(query.lastError());
    return ret;
}


void DbPduHrs::selectItem(QSqlQuery &query,sDbPduHrsItem &item)
{
    item.id = query.value("id").toInt();
    item.date = query.value("date").toString();
    item.time = query.value("time").toString();
    item.room = query.value("room").toString();
    item.modular = query.value("modular").toString();
    item.cab = query.value("cab").toString();
    item.road = query.value("road").toString();
    item.devtype = query.value("devtype").toString();
    item.ip = query.value("ip").toString();
    item.devnum = query.value("devnum").toString();
    item.item = query.value("item").toString();
    item.sw = query.value("sw").toString();
    item.vol = query.value("vol").toDouble();
    item.cur = query.value("cur").toDouble();
    item.pow = query.value("pow").toDouble();
    item.pow = query.value("pow").toDouble();
    item.pf = query.value("pf").toDouble();
    item.ele = query.value("ele").toDouble();
}
