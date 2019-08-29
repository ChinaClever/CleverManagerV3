#ifndef SETUPMAINWID_H
#define SETUPMAINWID_H

#include "usermainwid.h"

namespace Ui {
class SetUpMainWid;
}

class SetUpMainWid : public QWidget
{
    Q_OBJECT

public:
    explicit SetUpMainWid(QWidget *parent = 0);
    ~SetUpMainWid();

protected slots:
    void initFunSLot();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::SetUpMainWid *ui;
    UserMainWid *mUserWid;
};

#endif // SETUPMAINWID_H
