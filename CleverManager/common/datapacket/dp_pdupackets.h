#ifndef PDU_DATAPACKETS_H
#define PDU_DATAPACKETS_H

#include "datapackets.h"
#include "dp_pduhrssave.h"
#include "dbpdudevices.h"

class Dp_PduPackets : public DataPackets
{
    Q_OBJECT
    explicit Dp_PduPackets(QObject *parent = nullptr);
public:
    static Dp_PduPackets *bulid(QObject *parent=0);

protected:
    void initFun();
    void initPacket(PduDeviceItem &it);

    void workDown(sDataPacket *pack);
    sDataPacket *newDataPacket();

protected slots:
    void pduItemChange(int,int);

private:
    DbPduDevices *mDb;
    Dp_PduAlarm *mAlarm;
    Dp_PduHrsSave *mHrs;
};

#endif // PDU_DATAPACKETS_H
