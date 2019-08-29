#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mUserWid = new UserMainWid(ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
