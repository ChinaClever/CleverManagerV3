#include "log_landbar.h"

Log_LandBar::Log_LandBar(QWidget *parent) : LogBtnBar(parent)
{
    mDlg = new Log_LandQueryDlg(this);
}

QString Log_LandBar::queryBtn()
{
    QString str;
    int ret = mDlg->exec();
    if(ret == QDialog::Accepted) {
        str = mDlg->getCmd();
    }

    return str;
}
