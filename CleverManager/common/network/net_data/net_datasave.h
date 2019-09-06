#ifndef NET_DATASAVE_H
#define NET_DATASAVE_H

#include "net_devdata.h"

class Net_DataSave
{
    Net_DataSave();
public:
    static Net_DataSave *bulid();

    void dataSave(pdu_devData_packet *packet);

protected:
    void dataFun(sDataPacket *dev,pdu_dev_data *data);
    void outputName(QString *name, pdu_dev_data *data);
    void user(QString &user, QString &pwd, pdu_dev_data *data);
    void iPAddr(sIpAddr &ip,pdu_dev_data *data);
    void devName(QString &name,pdu_dev_data *data);

private:
    Net_DevData *mDevData;
    Net_DataCom *mDataCom;
};

#endif // NET_DATASAVE_H
