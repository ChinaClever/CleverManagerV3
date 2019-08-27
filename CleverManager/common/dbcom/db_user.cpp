/*
 * db_usr.cpp
 * 用户数据库表
 *
 *  Created on: 2016年10月11日
 *      Author: Lzy
 */
#include "db_user.h"

DbUser::DbUser()
{
    createTable();
}

void DbUser::createTable()
{
    QString cmd =
            "create table if not exists %1("
            "id             INTEGER primary key autoincrement not null,"
            "dateTime       TEXT,"
            "name           TEXT not null,"
            "pwd            TEXT,"
            "email          TEXT,"
            "telephone      INTEGER,"
            "remarks        INTEGER,"
            "jur            INTEGER);";
    QSqlQuery query;
    if(!query.exec(cmd.arg(tableName())))
    {
        throwError(query.lastError());
    }
}

DbUser *DbUser::get()
{
    static DbUser* sington = nullptr;
    if(sington == nullptr)
        sington = new DbUser();
    return sington;
}

void DbUser::insertItem(sUserItem &item)
{
    item.id = maxId()+1;
    QString cmd = "insert into %1 (id,dateTime,name,pwd,email,telephone,remarks,jur) "
                  "values(:id,:dateTime,:name,:pwd,:email,:telephone,:remarks,:jur)";
    modifyItem(item,cmd.arg(tableName()));
    emit itemChanged(item.id,Insert);
}


void DbUser::updateItem(const sUserItem &item)
{
    QString cmd = "update %1 set "
                  "name        = :name,"
                  "pwd         = :pwd,"
                  "email       = :email,"
                  "telephone   = :telephone,"
                  "remarks     = :remarks,"
                  "jur         = :jur"
                  " where id   = :id";
    modifyItem(item,cmd.arg(tableName()));
    emit itemChanged(item.id,Update);
}

void DbUser::modifyItem(const sUserItem &item, const QString &cmd)
{
    QSqlQuery query;
    query.prepare(cmd);
    query.bindValue(":id",item.id);
    query.bindValue(":dateTime",item.dateTime);
    query.bindValue(":name",item.name);
    query.bindValue(":pwd",item.pwd);
    query.bindValue(":email",item.email);
    query.bindValue(":telephone",item.telephone);
    query.bindValue(":remarks",item.remarks);
    query.bindValue(":jur",item.jur);
    if(!query.exec())
        throwError(query.lastError());
}

void DbUser::selectItem(QSqlQuery &query,sUserItem &item)
{
    item.id = query.value("id").toInt();
    item.dateTime = query.value("dateTime").toString();
    item.name = query.value("name").toString();
    item.pwd = query.value("pwd").toString();
    item.email = query.value("email").toString();
    item.telephone = query.value("telephone").toString();
    item.remarks = query.value("remarks").toString();
    item.jur = query.value("jur").toInt();
}


QVector<sUserItem> DbUser::selItemsByName(const QString& Name)
{
    return selectItems(QString("where name = %1").arg(Name));
}


void DbUser::removeItemsByName(const QString& name)
{
    QVector<sUserItem> items = selItemsByName(name);
    foreach(const sUserItem& item,items)
        removeItem(item);
}
