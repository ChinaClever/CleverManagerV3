#ifndef PDU_MAINWID_H
#define PDU_MAINWID_H

#include <QWidget>

namespace Ui {
class Pdu_MainWid;
}

class Pdu_MainWid : public QWidget
{
    Q_OBJECT

public:
    explicit Pdu_MainWid(QWidget *parent = 0);
    ~Pdu_MainWid();

private:
    Ui::Pdu_MainWid *ui;
};

#endif // PDU_MAINWID_H
