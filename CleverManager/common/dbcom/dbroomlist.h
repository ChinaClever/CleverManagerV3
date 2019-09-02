#ifndef DBROMELIST_H
#define DBROMELIST_H

#include "basicsql.h"

struct RoomItem: public DbBasicItem
{
    bool unequal(const RoomItem& item) const
    {
        return id!=item.id || name!=item.name || address!=item.address;
    }
    QString name,address;
};
Q_DECLARE_METATYPE(RoomItem)

class DbRoomList : public SqlBasic<RoomItem>
{
    Q_OBJECT
    DbRoomList();
public:
    static DbRoomList* get();
    QString tableName(){return "rooms";}
    void insertItem(RoomItem &item);
    void updateItem(const RoomItem& item);

    QStringList list();
    int contains(const QString &name);
    int findId(const QString& Name);
    RoomItem find(const QString& name);
    void removeRoom(const QString& name);

signals:
    void delSig(QString);
    void updateSig(QString, QString);

protected:
    void createTable();
    void modifyItem(const RoomItem& item,const QString& cmd);
    void selectItem(QSqlQuery &query,RoomItem &item);
};

#endif // DBROMELIST_H
