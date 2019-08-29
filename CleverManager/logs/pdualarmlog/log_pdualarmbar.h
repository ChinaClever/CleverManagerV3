#ifndef LOG_PDUALARMBAR_H
#define LOG_PDUALARMBAR_H

#include "log_pdualarmquerydlg.h"

class Log_PduAlarmBar : public LogBtnBar
{
    Q_OBJECT
public:
    explicit Log_PduAlarmBar(QWidget *parent = nullptr);

protected:
    QString queryBtn();

private:
    Log_PduAlarmQueryDlg *mDlg;
};

#endif // LOG_PDUALARMBAR_H
