#include "log_landquerydlg.h"
#include "ui_log_landquerydlg.h"

Log_LandQueryDlg::Log_LandQueryDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_LandQueryDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("用户登陆查询对话框"));
    groupBox_background_icon(this);
    mDateBar = new SqlDateBar(ui->dateWid);
}

Log_LandQueryDlg::~Log_LandQueryDlg()
{
    delete ui;
}

QString Log_LandQueryDlg::getCmd()
{
    QString cmd = mDateBar->getDate();
    QString str = ui->userEdit->text();
    if(!str.isEmpty()) {
         cmd += QString(" and name like '%%1%'").arg(str);
    }

    return cmd;
}

void Log_LandQueryDlg::on_quitBtn_clicked()
{
    this->close();
}

void Log_LandQueryDlg::on_okBtn_clicked()
{
    this->accept();
}
