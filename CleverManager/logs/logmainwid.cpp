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
    mLandLog->initWid(DbLandLog::get(), new Log_LandBar());
    ui->stackedWid->addWidget(mLandLog);

    mPduALarmLog = new LogComWid(ui->stackedWid);
    mPduALarmLog->initWid(DbPduAlarm::get(), new Log_PduAlarmBar());
    ui->stackedWid->addWidget(mPduALarmLog);
}

void LogMainWid::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWid->setCurrentIndex(index);
}
