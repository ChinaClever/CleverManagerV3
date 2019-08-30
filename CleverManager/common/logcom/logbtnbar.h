#ifndef LOGBTNBAR_H
#define LOGBTNBAR_H

#include "logquerybase.h"

class LogBtnBar : public SqlBtnBar
{
    Q_OBJECT
public:
    explicit LogBtnBar(QWidget *parent = nullptr);
    void setDlg(LogQueryBase *dlg){mQueryDlg=dlg;}

protected:
    virtual QString queryBtn();

protected:
    LogQueryBase *mQueryDlg;
};

#endif // LOGBTNBAR_H
