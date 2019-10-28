/*
 *
 *  Created on: 2019年10月1日
 *      Author: Lzy
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "net_dataanalyze.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LandingUser::get(this);
    mNavBar = new NavBarWid(ui->navWId);
    QTimer::singleShot(5,this,SLOT(initPacksSLot()));
    QTimer::singleShot(500,this,SLOT(initWidSLot()));
    QTimer::singleShot(1500,this,SLOT(initNetWork()));
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
    mTpWid = new Tp_TopologyWid(ui->stackedWid);
    ui->stackedWid->addWidget(mTpWid);

    mLog = new LogMainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mLog);

    mPduWid = new Pdu_MainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mPduWid);

    mRoom = new Room_MainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mRoom);

    mSetup = new Setup_MainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mSetup);

    mCab = new Cab_MainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mCab);
    connect(mTpWid, SIGNAL(selectSig(int)), mCab, SIGNAL(selectedSig(int)));
    connect(mTpWid, SIGNAL(selectSig(int)), this, SLOT(selectSlot(int)));
}

void MainWindow::navBarSlot(int id)
{
    ui->stackedWid->setCurrentIndex(id);
}

void MainWindow::selectSlot(int)
{
    ui->stackedWid->setCurrentWidget(mCab);
}
