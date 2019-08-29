#include "log_pdualarmbar.h"

Log_PduAlarmBar::Log_PduAlarmBar(QWidget *parent) : LogBtnBar(parent)
{
    mDlg = new Log_PduAlarmQueryDlg(this);
}

QString Log_PduAlarmBar::queryBtn()
{
    QString str;
    int ret = mDlg->exec();
    if(ret == QDialog::Accepted) {
        str = mDlg->getCmd();
    }

    return str;
}
