#ifndef NETANALYZEDATA_H
#define NETANALYZEDATA_H

#include "netdataformat.h"

class NetAnalyticData
{
public:
    NetAnalyticData() {}
    static NetAnalyticData *bulid();
    uchar net_data_xor(uchar *buf, ushort len);
    int net_data_analytic(uchar *buf, ushort len, net_data_packet *msg);
    int dev_data_analytic(uchar *buf, ushort len, net_dev_data *pkt);

protected:
    int data_packet_getDomain(uchar *buf, net_data_packet *msg);
    int data_packet_getCode(uchar *buf, net_dev_code *code);
    int data_packet_sync(uchar *buf, ushort len);
};

#endif // NETANALYZEDATA_H
