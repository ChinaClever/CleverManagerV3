#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mNavBar = new NavBarWid(ui->navWId);
    QTimer::singleShot(5,this,SLOT(initFunSLot()));
    connect(mNavBar, SIGNAL(navBarSig(int)), this, SLOT(navBarSlot(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initFunSLot()
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
