#include "elecbtnbar.h"

ElecBtnBar::ElecBtnBar(QWidget *parent) : LogBtnBar(parent)
{

}


QString ElecBtnBar::queryBtn()
{
    QString str;
    if(mQueryDlg) {
        int ret = mQueryDlg->Exec();
        if(ret == QDialog::Accepted) {
            emit clearSig(); // 清除现成数据
            str = mQueryDlg->getCmd();
            emit refreshSig();
        }
    }

    return str;
}
