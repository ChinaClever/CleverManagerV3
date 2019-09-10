#include "pdu_settemdlg.h"

Pdu_SetTemDlg::Pdu_SetTemDlg(QWidget *parent) : Pdu_SetThresholdDlg(parent)
{

}

void Pdu_SetTemDlg::init(int id, sDataPacket *packet)
{
    setMode(SET_CMD_ENV_TEM, id, packet);
}
