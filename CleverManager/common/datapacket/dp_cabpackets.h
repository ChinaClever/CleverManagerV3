#ifndef DP_CABPACKETS_H
#define DP_CABPACKETS_H

#include "dp_pdupackets.h"

class Dp_CabPackets : public QThread
{
    Q_OBJECT
public:
    explicit Dp_CabPackets(QObject *parent = nullptr);

    sCabPacket *get(const QString &room, const QString &cab);

protected:
    void initFun();
    void initPacket(CabinetItem &it);

protected:
    sCabPacket *insert(const QString &key);
    sCabPacket *find(const QString &key);
    void remove(const QString &key);
    bool contains(const QString &key) {return mHash.contains(key);}

private slots:
    void cabinetItemChange(int, int);

private:
    QHash<QString, sCabPacket *> mHash;
    Dp_PduPackets *mPdus;
    DbCabinetList *mDb;
};

#endif // DP_CABPACKETS_H
