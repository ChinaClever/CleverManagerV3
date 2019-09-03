#include "setupmainwid.h"
#include "ui_setupmainwid.h"
#include "logmainwid.h"
#include "pdudevices/setup_pdustablewid.h"


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
