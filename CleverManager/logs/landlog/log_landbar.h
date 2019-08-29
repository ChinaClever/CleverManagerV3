#ifndef LOG_LANDBAR_H
#define LOG_LANDBAR_H

#include "log_landquerydlg.h"

class Log_LandBar : public LogBtnBar
{
    Q_OBJECT
public:
    explicit Log_LandBar(QWidget *parent = nullptr);

protected:
    QString queryBtn();

private:
    Log_LandQueryDlg *mDlg;
};

#endif // LOG_LANDBAR_H
