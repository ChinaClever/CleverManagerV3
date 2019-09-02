#ifndef DBCABINETLIST_H
#define DBCABINETLIST_H

#include "dbroomlist.h"

struct CabinetItem
{
    CabinetItem(){id=room_id=-1;row=column=0;height=42;}
    QString room, cab;
    int id, room_id,height,row,column;
    QString main_ip, main_num, main_type;
    QString spare_ip,spare_num,spare_type;
};
Q_DECLARE_METATYPE(CabinetItem)



class DbCabinetList : public SqlBasic<CabinetItem>
{
    Q_OBJECT
    DbCabinetList();
public:
    static DbCabinetList* get();
    QString tableName(){return "cabinets";}
    void insertItem(CabinetItem &item);
    bool updateItem(const CabinetItem& item);

    void removeItemsByRoomId(int roomId);
    QVector<CabinetItem> selItemsByRoomId(int room_id);
    QVector<int> selRoomIdsByAddress(const QString& addr,int num);

    QStringList list(const QString &room);
    int contains(const QString &room, const QString &cab);
    bool removeCab(const QString &room, const QString &cab);

    int findId(const QString& room, const QString &cab);
    CabinetItem find(const QString &room, const QString &cab);

signals:
    void updateSig(int ,QString);

protected slots:
    void roomItemChange(int roomId,int type);

protected:
    void createTable();
    bool modifyItem(const CabinetItem& item,const QString& cmd);
    void selectItem(QSqlQuery &query,CabinetItem &item);
};

#endif // DBCABINETLIST_H
