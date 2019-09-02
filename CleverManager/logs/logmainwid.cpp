#include "logmainwid.h"
#include "ui_logmainwid.h"


LogMainWid::LogMainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogMainWid)
{
    ui->setupUi(this);
    QTimer::singleShot(rand()%50,this,SLOT(initFunSLot()));
}

LogMainWid::~LogMainWid()
{
    delete ui;
}


void LogMainWid::initFunSLot()
{
    mLandLog = new LogComWid(ui->stackedWid);
    mLandLog->initWid(DbUserLog::bulid(), new Log_UserQueryDlg(this));
    ui->stackedWid->addWidget(mLandLog);

    mPduALarmLog = new LogComWid(ui->stackedWid);
    mPduALarmLog->initWid(DbPduAlarm::bulid(), new Log_PduAlarmQueryDlg(this));
    ui->stackedWid->addWidget(mPduALarmLog);

    mPduHrs = new LogComWid(ui->stackedWid);
    mPduHrs->initWid(DbPduHrs::bulid(), new Log_PduAlarmQueryDlg(this));
    ui->stackedWid->addWidget(mPduHrs);

    mCabHrs = new LogComWid(ui->stackedWid);
    mCabHrs->initWid(DbCabHrs::bulid(), new Log_CabHrsQueryDlg(this));
    ui->stackedWid->addWidget(mCabHrs);

    mCabElec = new ElecComWid(ui->stackedWid);
    mCabElec->initWid(DbCabElec::bulid(), new Log_CabElecQueryDlg(this));
    ui->stackedWid->addWidget(mCabElec);

    mPduElec = new ElecComWid(ui->stackedWid);
    mPduElec->initWid(DbPduElec::bulid(), new Log_PduElecQueryDlg(this));
    ui->stackedWid->addWidget(mPduElec);

}

void LogMainWid::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWid->setCurrentIndex(index);
}
