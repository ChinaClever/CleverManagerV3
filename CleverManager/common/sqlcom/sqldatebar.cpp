#include "sqldatebar.h"
#include "ui_sqldatebar.h"

SqlDateBar::SqlDateBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SqlDateBar)
{
    ui->setupUi(this);
    ui->startDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate());
}

SqlDateBar::~SqlDateBar()
{
    delete ui;
}


QString SqlDateBar::getDate()
{
    QString str;

    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();
    if(startDate > endDate) {
        CriticalMsgBox box(this, tr("起始日期早于结束日期，请重新填写日期!"));
    } else {
        QString startDateStr = startDate.toString("yyyy-MM-dd");
        QString endDateStr = endDate.toString("yyyy-MM-dd");
        str = QString("date between \'%1\' and  \'%2\'").arg(startDateStr).arg(endDateStr);
    }

    return str;
}


void SqlDateBar::on_startDateBtn_clicked()
{
    MsgCalendarDlg dlg(this);
    dlg.exec();
    ui->startDateEdit->setDate(dlg.getDate());
}

void SqlDateBar::on_endDateBtn_clicked()
{
    MsgCalendarDlg dlg(this);
    dlg.exec();
    ui->endDateEdit->setDate(dlg.getDate());
}
