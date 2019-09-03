#ifndef SETUPMAINWID_H
#define SETUPMAINWID_H

#include "usermainwid.h"
#include "dbpdudevices.h"

namespace Ui {
class SetUpMainWid;
}

class SetUpMainWid : public QWidget
{
    Q_OBJECT

public:
    explicit SetUpMainWid(QWidget *parent = 0);
    ~SetUpMainWid();

protected:
    void initPdusTable();


protected slots:
    void initFunSLot();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_upBtn_clicked();

private:
    Ui::SetUpMainWid *ui;
    UserMainWid *mUserWid;
};

#endif // SETUPMAINWID_H
