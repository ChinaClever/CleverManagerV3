#include "dbpduelec.h"
#include "dbtemplateelec.h"

DbPduElec::DbPduElec()
{
    createTable();
    tableTile = tr("PDU电量计算");
    hiddens << 2 << 14;
    headList.clear();
    headList << tr("编号") << tr("机房") << tr("模块") << tr("机柜")  << tr("主备路")
             << tr("设备类型") << tr("设备IP") << tr("级联编号") << tr("项目")
             << tr("起始时间") << tr("起始电能") << tr("结束时间") << tr("结束电能")
             << tr("耗电量") << tr("单价") << tr("电费");
}


void DbPduElec::createTable()
{
    QString cmd =
            "create table if not exists %1("
            "id             INTEGER primary key autoincrement not null,"
            "room           VCHAR,"
            "modular        VCHAR,"
            "cab            VCHAR,"
            "road           VCHAR,"
            "devtype        VCHAR,"
            "ip             VCHAR,"
            "devnum         VCHAR,"
            "item           VCHAR,"
            "startdt        VCHAR,"
            "startele       DOUBLE,"
            "enddt          VCHAR,"
            "endele         DOUBLE,"
            "ele            DOUBLE,"
            "price          DOUBLE,"
            "fees           DOUBLE);";
    QSqlQuery query;
    if(!query.exec(cmd.arg(tableName()))) {
        throwError(query.lastError());
    }
}


DbPduElec *DbPduElec::bulid()
{
    static DbPduElec* sington = nullptr;
    if(sington == nullptr)
        sington = new DbPduElec();
    return sington;
}


bool DbPduElec::insertItem(sPduElecItem &item)
{
    QString cmd = "insert into %1 (room,modular,cab,road,devtype,ip,devnum,item,startdt,startele,enddt,ele,price,fees) "
                  "values(:room,:modular,:cab,:road,:devtype,:ip,:devnum,:item,:startdt,:startele,:enddt,:ele,:price,:fees)";
    return modifyItem(item,cmd.arg(tableName()));
}


bool DbPduElec::modifyItem(const sPduElecItem &item, const QString &cmd)
{
    QSqlQuery query;
    query.prepare(cmd);
    query.bindValue(":room",item.room);
    query.bindValue(":modular",item.modular);
    query.bindValue(":cab",item.cab);
    query.bindValue(":road",item.road);
    query.bindValue(":devtype",item.devtype);
    query.bindValue(":ip",item.ip);
    query.bindValue(":devnum",item.devnum);
    query.bindValue(":item",item.item);
    query.bindValue(":startdt",item.startdt);
    query.bindValue(":startele",item.startele);
    query.bindValue(":enddt",item.enddt);
    query.bindValue(":ele",item.ele);
    query.bindValue(":price",item.price);
    query.bindValue(":fees",item.fees);
    bool ret = query.exec();
    if(!ret)  throwError(query.lastError());
    return ret;
}

void DbPduElec::elec(QStringList &list)
{
    sDbPduHrsItem it;
    sPduElecItem ele;

    DbPduHrs* db = DbPduHrs::bulid();
    for(int i=0; i<list.size(); ++i) {
        QString cmd = list.at(i);
        bool ret = elec_bulid_get(db, it, ele, cmd);
        if(ret) {
            ele.room = it.room;
            ele.modular = it.modular;
            ele.cab = it.cab;
            ele.road = it.road;
            ele.devtype = it.devtype;
            ele.ip = it.ip;
            ele.devnum = it.devnum;
            ele.item = it.item;
            insertItem(ele);
        }
    }
}
