#ifndef DATAPACKETS_H
#define DATAPACKETS_H

#include <QObject>
#include "datapacket.h"
#include <QHash>

class DataPackets : public QThread
{
    Q_OBJECT
public:
    explicit DataPackets(QObject *parent = nullptr);
    ~DataPackets();

    sDataPacket *get(const QString &ip, int devNum);
    sDataPacket *get(const QString &ip, const QString &dev_num);

    void delPdu(uint id);
    void delCab(uint id);
    void delRoom(uint id);

protected:
    void run();
    void workDown();

    virtual void initFun()=0;
    virtual void workDown(sDataPacket *pack)=0;
    virtual sDataPacket *newDataPacket()=0;

    sDataPacket *find(const QString &key);
    sDataPacket *insert(const QString &key);
    bool contains(const QString &key) {return mHash.contains(key);}

    int averData(ushort *data, int len);
    void tgDevData(sDevData &dev);
protected:
    bool isRun;
    QHash<QString, sDataPacket *> mHash;
};

#endif // DATAPACKETS_H
