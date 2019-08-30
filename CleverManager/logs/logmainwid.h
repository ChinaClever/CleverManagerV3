#ifndef LOGMAINWID_H
#define LOGMAINWID_H

#include "logquerydlg/log_querydlgs.h"
#include "dbpduhrs.h"
#include "eleccomwid.h"

namespace Ui {
class LogMainWid;
}

class LogMainWid : public QWidget
{
    Q_OBJECT

public:
    explicit LogMainWid(QWidget *parent = 0);
    ~LogMainWid();

protected slots:
    void initFunSLot();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::LogMainWid *ui;

    LogComWid *mLandLog;
    LogComWid *mPduALarmLog;
    LogComWid *mPduHrs;
    LogComWid *mCabHrs;
    ElecComWid *mCabElec;
};

#endif // LOGMAINWID_H
