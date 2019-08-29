#include "log_pdualarmquerydlg.h"
#include "ui_log_pdualarmquerydlg.h"

Log_PduAlarmQueryDlg::Log_PduAlarmQueryDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_PduAlarmQueryDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("PDU报警日志查询对话框"));
    groupBox_background_icon(this);
    mDateBar = new SqlDateBar(ui->dateWid);
}

Log_PduAlarmQueryDlg::~Log_PduAlarmQueryDlg()
{
    delete ui;
}

QString Log_PduAlarmQueryDlg::getCmd()
{
    QString cmd = mDateBar->getDate();
    QString str = ui->roomEdit->text();
    if(!str.isEmpty()) cmd += QString(" and room like '%%1%'").arg(str);

    str = ui->cabEdit->text();
    if(!str.isEmpty()) cmd += QString(" and cab like '%%1%'").arg(str);

    int ret = ui->devtypeCmb->currentIndex();
    if(ret) {
        str = ui->devtypeCmb->currentText();
        cmd += QString(" and devtype like '%%1%'").arg(str);
    }

    str = ui->ipEdit->text();
    if(!str.isEmpty()) cmd += QString(" and ip like '%%1%'").arg(str);

    return cmd;
}


void Log_PduAlarmQueryDlg::on_quitBtn_clicked()
{
    close();
}

void Log_PduAlarmQueryDlg::on_okBtn_clicked()
{
    QString ip = ui->ipEdit->text();
    if(!ip.isEmpty()) {
        bool ret = cm_isIPaddress(ip);
        if(!ret) {
            CriticalMsgBox box(this, tr("设备IP地址输入有误，请重新输入!!!"));
            return;
        }
    }
    this->accept();
}
