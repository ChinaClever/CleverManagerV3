#ifndef DATAPACKETS_H
#define DATAPACKETS_H

#include <QObject>
#include "datapacket.h"
#include <QHash>

class DataPackets : public QObject
{
    Q_OBJECT
public:
    explicit DataPackets(QObject *parent = nullptr);

    sDataPacket *get(const QString &ip, int devNum);
    sDataPacket *get(const QString &ip, const QString &dev_num);

protected:
    virtual sDataPacket *newDataPacket()=0;
    sDataPacket *find(const QString &key);
    sDataPacket *insert(const QString &key);
    bool contains(const QString &key) {return mHash.contains(key);}

private:
    int averData(ushort *data, int len);
    void tgDevData(sDevData &dev);

protected:
    QHash<QString, sDataPacket *> mHash;
};

#endif // DATAPACKETS_H
