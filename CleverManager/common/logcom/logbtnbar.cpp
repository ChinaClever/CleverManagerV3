#include "logbtnbar.h"

LogBtnBar::LogBtnBar(QWidget *parent) : SqlBtnBar(parent)
{
    setNoEdit();
    mQueryDlg = nullptr;
}


QString LogBtnBar::queryBtn()
{
    QString str;
    if(mQueryDlg) {
        int ret = mQueryDlg->Exec();
        if(ret == QDialog::Accepted) {
            str = mQueryDlg->getCmd();
        }
    }

    return str;
}
