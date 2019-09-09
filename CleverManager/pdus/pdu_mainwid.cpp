#include "pdu_mainwid.h"
#include "ui_pdu_mainwid.h"

Pdu_MainWid::Pdu_MainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pdu_MainWid)
{
    ui->setupUi(this);
    QTimer::singleShot(500,this,SLOT(initWidSlot()));
}

Pdu_MainWid::~Pdu_MainWid()
{
    delete ui;
}



void Pdu_MainWid::initWidSlot()
{
    mOutputWid = new Pdu_OutputWid(ui->stackedWid);
    ui->stackedWid->addWidget(mOutputWid);

    mEnvWid = new Pdu_EnvWid(ui->stackedWid);
    ui->stackedWid->addWidget(mEnvWid);
}

void Pdu_MainWid::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWid->setCurrentIndex(index);
}
