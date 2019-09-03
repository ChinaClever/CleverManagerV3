#ifndef IPSTABWID_H
#define IPSTABWID_H

#include "comtablewid.h"
#include "datapacket.h"

class IpsTabWid : public ComTableWid
{
    Q_OBJECT
public:
    explicit IpsTabWid(QWidget *parent = nullptr);

protected slots:
   virtual void timeoutDone();

protected:
    virtual void initWid();
    virtual void updateData(QStringList &lst);

protected:
    Up_sDataPacket *mData;
};

#endif // IPSTABWID_H
