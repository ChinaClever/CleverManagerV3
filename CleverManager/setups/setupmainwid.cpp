/*
 *
 *  Created on: 2019年10月1日
 *      Author: Lzy
 */
#include "setupmainwid.h"
#include "ui_setupmainwid.h"
#include "logmainwid.h"
#include "pdudevices/setup_pdustablewid.h"
#include "sound.h"
#include "configbase.h"

SetUpMainWid::SetUpMainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUpMainWid)
{
    ui->setupUi(this);
    //    groupBox_background_icon(this);
    QTimer::singleShot(rand()%50,this,SLOT(initFunSLot()));

}

SetUpMainWid::~SetUpMainWid()
{
    delete ui;
}


void SetUpMainWid::initPdusTable()
{
    mUpdlg = new Up_MainDlg(this);
    Setup_PdusTableWid *pdu = new Setup_PdusTableWid(ui->stackedWid);
    pdu->initWid(DbPduDevices::get(), new Setup_PdusQueryDlg(this));
    ui->stackedWid->addWidget(pdu);

    Setup_PdusTableWid *cab = new Setup_PdusTableWid(ui->stackedWid);
    cab->initWid(DbCabinetList::get(), new Setup_CabQueryDlg(this));
    ui->stackedWid->addWidget(cab);

    Setup_PdusTableWid *room = new Setup_PdusTableWid(ui->stackedWid);
    room->initWid(DbRoomList::get(), new Setup_RoomQueryDlg(this));
    ui->stackedWid->addWidget(room);

    sConfigItem *item = ConfigBase::bulid()->item;
    ui->alarmCmb->setCurrentIndex(item->sound);
    ui->logSpin->setValue(item->logTimes);
    ui->priceSPin->setValue(item->elePrice);
}



void SetUpMainWid::initFunSLot()
{
    mUserWid = new UserMainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mUserWid);

    initPdusTable();
}

void SetUpMainWid::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWid->setCurrentIndex(index);
}

void SetUpMainWid::on_upBtn_clicked()
{
    mUpdlg->exec();
}

void SetUpMainWid::on_alarmCmb_currentIndexChanged(int index)
{
    Sound::bulid(this)->setAllow(index);
    ConfigBase *con = ConfigBase::bulid();
    con->item->sound = index;
    con->setSound(index);
}


void SetUpMainWid::on_logSpin_valueChanged(int arg1)
{
    ConfigBase *con = ConfigBase::bulid();
    con->item->logTimes = arg1;
    con->setLogTime(arg1);
}

void SetUpMainWid::on_priceSPin_valueChanged(double arg1)
{
    ConfigBase *con = ConfigBase::bulid();
    con->item->elePrice = arg1;
    con->setElePrice(arg1);
}
