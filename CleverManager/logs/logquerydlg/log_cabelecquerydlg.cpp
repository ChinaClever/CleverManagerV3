#include "log_cabelecquerydlg.h"
#include "ui_log_cabhrsquerydlg.h"

Log_CabElecQueryDlg::Log_CabElecQueryDlg(QWidget *parent) :
    Log_CabHrsQueryDlg(parent)
{
    ui->roadCmb->removeItem(0);
}

Log_CabElecQueryDlg::~Log_CabElecQueryDlg()
{

}

bool Log_CabElecQueryDlg::inputCheck()
{
    bool ret = false;
    QString str = ui->roomEdit->text();
    if(str.isEmpty()) {
        CriticalMsgBox box(this, tr("机房名不能为空，请重新输入!!!"));
    } else {
        ret = true;
    }

    return ret;
}

QStringList Log_CabElecQueryDlg::getCabs()
{
    QStringList list;

    QString str = ui->cabEdit->text();
    if(!str.isEmpty()) {
        list << QString(" and cab like '%%1%'").arg(str);
    } else {
         QString room = ui->roomEdit->text();
         // 获取此机房内的甩有机柜


    }

    return list;
}

QStringList Log_CabElecQueryDlg::getCmds()
{
    QString str = ui->roomEdit->text();
    QString room = QString(" and room like '%%1%'").arg(str);

    str = ui->roadCmb->currentText();
    QString road = QString(" and road like '%%1%'").arg(str);

    QStringList list, cabs = getCabs();
    for(int i=0; i<cabs.size(); ++i) {
        list << room + cabs.at(i) + road;
    }

    return list;
}


QString Log_CabElecQueryDlg::getCmd()
{
    QStringList list = getCmds();
    DbCabElec::bulid()->elec(list);

    return "";
}
