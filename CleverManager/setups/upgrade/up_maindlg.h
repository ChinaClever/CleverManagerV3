#ifndef UP_MAINDLG_H
#define UP_MAINDLG_H

#include <QDialog>
#include "ipswid.h"
#include "upgradewid.h"
#include "okstabwid.h"
#include "devselectwid.h"

namespace Ui {
class Up_MainDlg;
}

class Up_MainDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Up_MainDlg(QWidget *parent = 0);
    ~Up_MainDlg();

private:
    Ui::Up_MainDlg *ui;

    QTimer* timer;
    IpsWid *mIpsWid;
    UpgradeWid *mUpgradeWid;
    IpsTabWid *mIpsTabWid;
    OksTabWid *mOksTabWid;
    ErrsTabWid *mErrsTabWid;
    DevSelectWid *mDevSelectWid;
};

#endif // UP_MAINDLG_H
