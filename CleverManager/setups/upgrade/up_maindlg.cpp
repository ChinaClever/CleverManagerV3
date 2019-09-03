#include "up_maindlg.h"
#include "ui_up_maindlg.h"

Up_MainDlg::Up_MainDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Up_MainDlg)
{
    ui->setupUi(this);

    Up_DataPacket::bulid()->data;
    mIpsWid = new IpsWid(ui->ipWid);
    mUpgradeWid = new UpgradeWid(ui->upWid);

    mIpsTabWid = new IpsTabWid(ui->ipsTabWid);
    mOksTabWid = new OksTabWid(ui->oksTabWid);
    mErrsTabWid = new ErrsTabWid(ui->errsTabWid);
    mDevSelectWid = new DevSelectWid(ui->devWid);
}

Up_MainDlg::~Up_MainDlg()
{
    delete ui;
}
