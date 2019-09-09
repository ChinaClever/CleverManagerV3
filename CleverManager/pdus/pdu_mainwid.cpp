#include "pdu_mainwid.h"
#include "ui_pdu_mainwid.h"

Pdu_MainWid::Pdu_MainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pdu_MainWid)
{
    ui->setupUi(this);
}

Pdu_MainWid::~Pdu_MainWid()
{
    delete ui;
}


void Pdu_MainWid::on_comboBox_currentIndexChanged(int index)
{

}
