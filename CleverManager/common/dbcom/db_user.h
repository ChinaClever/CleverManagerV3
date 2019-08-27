#ifndef DB_USR_H
#define DB_USR_H
#include "basicsql.h"

struct sUserItem{
    sUserItem():id(-1),jur(0){}
    int id,jur;
    QString dateTime,name,pwd,email,telephone,remarks;
};



class DbUser : public SqlBasic<sUserItem>
{
    Q_OBJECT
    DbUser();
public:
    static DbUser* get();
    QString tableName(){return "users";}

    void insertItem(sUserItem& item);
    void updateItem(const sUserItem& item);

    QVector<sUserItem> selItemsByName(const QString& Name);
    void removeItemsByName(const QString& name);

protected:
    void createTable();
    void modifyItem(const sUserItem& item,const QString& cmd);
    void selectItem(QSqlQuery &query,sUserItem &item);
};

#endif // DB_USR_H
