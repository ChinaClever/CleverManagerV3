﻿#ifndef BASICSQL_H
#define BASICSQL_H

#include <QtSql>
#include <QObject>
#include "common.h"

#define LOG_DELAY 1

class Db_Tran
{
public:
    Db_Tran() {QSqlDatabase::database().transaction();}
    ~Db_Tran() {QSqlDatabase::database().commit();}
};

struct DbBasicItem {
    DbBasicItem():id(-1){
        QDateTime dateTime = QDateTime::currentDateTime();
        date = dateTime.toString("yyyy-MM-dd");
        time = dateTime.toString("hh:mm:ss");
    }

    uint id;
    QString date, time;
};

struct DbBasicElecItem {
    DbBasicElecItem():id(-1){
        startele=endele=ele=price=fees=0;
    }

    uint id;
    QString startdt, enddt;
    double startele, endele, ele, price, fees;
};

class BasicSql : public QObject
{
    Q_OBJECT
public:
    explicit BasicSql(QObject *parent = 0);
    ~BasicSql();

    QList<int> hiddens;
    QString tableTile;
    QStringList headList;
    enum{Remove,Insert,Update};
    virtual QString tableName() = 0;

    bool remove(int id);
    bool remove(const QString &condition);
    bool removeMinIds(int id);

    int maxId();
    int maxId(const QString &condition);
    int maxId(const QString &idName, const QString &condition);

    int minId();
    int minId(const QString &condition);
    int minId(const QString &idName, const QString &condition);
    bool minIdRemove();
    bool minIdsRemove(int id);

    int counts();
    int count(const QString &column_name, const QString &condition);
    bool countsRemove(int count);

    QStringList listColumn(const QString &column_name, const QString &condition);
    QVector<int> listColumnToInt(const QString &column_name, const QString &condition);
    QVector<int> selectIds(const QString &condition="");

    bool updateColumn(const QString& column_name, double value, const QString &condition);
    bool updateColumn(const QString& column_name, const QString& value, const QString &condition);

    bool clear(); // 清空 表
    virtual void createTable()=0;

    QSqlDatabase mDb;
    static QSqlDatabase initDb();

signals:
    void itemChanged(int id,int type);
protected:
    void throwError(const QSqlError& err); /// inline static
    QString tableMarking();
    void setTableMarking(const QString& marking);
};


//该类为sql通用类型。
template <typename T> //模板
class SqlBasic:public BasicSql
{
public:

    QVector<T> allItems() {
        return selectItems("");
    }

    QVector<T> findItemById(int id){
        return selectItems(QString("where id = %1").arg(id));
    }

    T findById(int id){
        return findItemById(id).first();
    }

    QVector<T> selectByDate(const QString &start, const QString &end) {
        QString cmd = QString("where date Between \'%2\' and \'%3\'").arg(start).arg(end);
        return selectItems(cmd);
    }

    QVector<T> selectByDate(const QString &date) {
        return selectItems(QString("where date = %1").arg(date));
    }

protected:
    virtual void selectItem(QSqlQuery &,T &){} //纯虚函数
    QVector<T> selectItems(const QString &condition)
    {
        QVector<T> items;
        QSqlQuery query(mDb);
        QString sqlcom = QString("SELECT * from %1 %2").arg(tableName()).arg(condition);
        query.prepare(sqlcom);
        if(query.exec()){
            T item;
            while(query.next()){
                selectItem(query,item);
                items.append(item);
            }
        } else {
            qDebug()<<" "<<query.lastError().databaseText();
            qDebug()<<" "<<query.lastError().driverText();
            qDebug()<<sqlcom;
            throwError(query.lastError());
        }
        return items;
    }
};

void DB_selectTableByTime(QString &name, QString &start, QString &end, QList<QStringList> &list);
bool db_select_dateList(const QString &tableName, QStringList &dateList);
#endif // BASICSQL_H
