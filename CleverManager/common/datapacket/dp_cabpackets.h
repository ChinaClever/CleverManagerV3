#ifndef DP_CABPACKETS_H
#define DP_CABPACKETS_H

#include "dp_cabhrssave.h"

class Dp_CabPackets : public QThread
{
    Q_OBJECT
    explicit Dp_CabPackets(QObject *parent = nullptr);
public:
    static Dp_CabPackets *bulid(QObject *parent);
    ~Dp_CabPackets();

    sCabPacket *get(const QString &room, const QString &cab);

    sCabPacket *getByCab(uint id);
    QVector<sCabPacket *> getByRoom(uint id);

    void delCab(uint id);
    void delRoom(uint id);

protected:
    void run();
    void initFun();
    void workDown();
    void initPacket(CabinetItem &it);
    void dels(QVector<sCabPacket *> &packs);

    void tgData(sCabPacket *cab);
    int getStatus(sTgObjData *tg, sDataPacket *pack);
    int getStatus(sTgObjData *tg, sDataPacket *m,  sDataPacket *s);

private:
    sCabPacket *insert(const QString &key);
    sCabPacket *find(const QString &key);
    void remove(const QString &key);
    bool contains(const QString &key) {return mHash.contains(key);}

private slots:
    void cabinetItemChange(int, int);

private:
    bool isRun;
    Dp_PduPackets *mPdus;
    DbCabinetList *mDb;
    Dp_CabHrsSave *mCabHrs;
    QHash<QString, sCabPacket *> mHash;
};

#endif // DP_CABPACKETS_H
