#ifndef NETPACKDATA_H
#define NETPACKDATA_H
#include "netanalyzedata.h"

class NetPackData
{
public:
    NetPackData() {}
    static NetPackData *bulid();
    int net_data_packets(int num, pdu_dev_data *pkt, uchar *buf, uchar type=TRA_TYPR_UDP);

protected:
    net_data_packet *get_data_packet(net_dev_code *code, uchar *buf, ushort len);
    pdu_dev_code *get_dev_code(int num, uchar type);
    int int_to_uchar(int form, uchar *to);
    int dev_data_pack(net_dev_data *pkt, uchar *buf);
    int data_msg_packet(net_data_packet *pkt, uchar *buf);
    int data_packet_domain(net_data_packet *msg, uchar *buf);
    int data_packet_code(net_dev_code *msg, uchar *buf);
    void data_packet_head(net_data_packet *pkt);

private:
    QReadWriteLock lock;
    uchar mSentBuf[DATA_MSG_SIZE];
};


#endif // NETPACKDATA_H
