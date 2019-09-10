#ifndef PDU_MAINWID_H
#define PDU_MAINWID_H

#include "pdu_env/pdu_envwid.h"

namespace Ui {
class Pdu_MainWid;
}

class Pdu_MainWid : public QWidget
{
    Q_OBJECT

public:
    explicit Pdu_MainWid(QWidget *parent = 0);
    ~Pdu_MainWid();


protected slots:
    void initWidSlot();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Pdu_MainWid *ui;

    Pdu_EnvWid *mEnvWid;
    Pdu_OutputWid *mOutputWid;
};

#endif // PDU_MAINWID_H
