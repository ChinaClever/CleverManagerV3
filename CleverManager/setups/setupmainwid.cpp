#include "setupmainwid.h"
#include "ui_setupmainwid.h"

SetUpMainWid::SetUpMainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUpMainWid)
{
    ui->setupUi(this);
    QTimer::singleShot(rand()%50,this,SLOT(initFunSLot()));

}

SetUpMainWid::~SetUpMainWid()
{
    delete ui;
}


void SetUpMainWid::initFunSLot()
{
    mUserWid = new UserMainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mUserWid);


}

void SetUpMainWid::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWid->setCurrentIndex(index);
}
