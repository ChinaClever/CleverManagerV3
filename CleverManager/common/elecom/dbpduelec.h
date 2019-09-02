#ifndef DBPDUELEC_H
#define DBPDUELEC_H
#include "dbcabelec.h"
#include "dbpduhrs.h"

struct sPduElecItem : public DbBasicElecItem
{
    QString room, modular, cab, road;
    QString devtype, ip, devnum;
    QString item;
};


class DbPduElec: public SqlBasic<sPduElecItem>
{
    DbPduElec();
public:
    static DbPduElec* bulid();
    QString tableName(){return "pduelecs";}
    bool insertItem(sPduElecItem& item);

    void elec(QStringList &list);

protected:
    void createTable();
    bool modifyItem(const sPduElecItem &item, const QString &cmd);
};

#endif // DBPDUELEC_H
