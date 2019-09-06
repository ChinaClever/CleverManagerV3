#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "netdataanalyze.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mNavBar = new NavBarWid(ui->navWId);
    QTimer::singleShot(5,this,SLOT(initPacksSLot()));
    QTimer::singleShot(500,this,SLOT(initWidSLot()));
    QTimer::singleShot(2500,this,SLOT(initNetWork()));
    connect(mNavBar, SIGNAL(navBarSig(int)), this, SLOT(navBarSlot(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPacksSLot()
{
    Dp_RoomPackets::bulid(this);
}

void MainWindow::initNetWork()
{
    NetDataAnalyze::bulid(this);
}


void MainWindow::initWidSLot()
{
    mSetup = new SetUpMainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mSetup);

    mLog = new LogMainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mLog);
}



void MainWindow::navBarSlot(int id)
{

    switch (id) {
    case 1: ui->stackedWid->setCurrentWidget(mSetup); break;
    case 2: ui->stackedWid->setCurrentWidget(mLog); break;
    }
}
