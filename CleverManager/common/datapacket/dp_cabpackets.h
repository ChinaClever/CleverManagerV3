#ifndef DP_CABPACKETS_H
#define DP_CABPACKETS_H

#include "dp_cabhrssave.h"

class Dp_CabPackets : public QThread, public Dp_HashBasic<sCabPacket *>
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

    void tgCabData(sCabPacket *cab);
    int getStatus(sDataPacket *pack);

    sCabPacket *newDataPacket() {return new sCabPacket;}


private slots:
    void cabinetItemChange(int, int);

private:
    bool isRun;
    Dp_PduPackets *mPdus;
    DbCabinetList *mDb;
    Dp_CabHrsSave *mCabHrs;
};

#endif // DP_CABPACKETS_H
