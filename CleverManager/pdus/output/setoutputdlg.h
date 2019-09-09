#ifndef SETOUTPUTDLG_H
#define SETOUTPUTDLG_H

#include "pdu_setswitchdlg.h"

namespace Ui {
class SetOutputDlg;
}

class SetOutputDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SetOutputDlg(QWidget *parent = 0);
    ~SetOutputDlg();

    void setMode(int id, sDataPacket *packet);

protected:
    void initData(int id);
    bool checkData();

    void saveLog();
    uchar *getData(uchar *buf);
    bool sentData();
    void saveData();

private slots:
    void on_saveBtn_clicked();

private:
    Ui::SetOutputDlg *ui;

    int mId;
    sDataPacket *mPacket;
};

#endif // SETOUTPUTDLG_H
