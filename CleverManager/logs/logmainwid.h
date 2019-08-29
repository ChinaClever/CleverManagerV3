#ifndef LOGMAINWID_H
#define LOGMAINWID_H

#include "landlog/log_landbar.h"
#include "pdualarmlog/log_pdualarmbar.h"

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
};

#endif // LOGMAINWID_H
