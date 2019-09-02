#include "setupmainwid.h"
#include "ui_setupmainwid.h"
#include "logmainwid.h"
#include "pdudevices/setup_pdusquerydlg.h"

SetUpMainWid::SetUpMainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUpMainWid)
{
    ui->setupUi(this);
    groupBox_background_icon(this);
    QTimer::singleShot(rand()%50,this,SLOT(initFunSLot()));

}

SetUpMainWid::~SetUpMainWid()
{
    delete ui;
}


void SetUpMainWid::initPdusTable()
{
    ElecComWid *pdu = new ElecComWid(ui->stackedWid);
    pdu->initWid(DbPduDevices::get(), new Setup_PdusQueryDlg(this));
    ui->stackedWid->addWidget(pdu);

    ElecComWid *cab = new ElecComWid(ui->stackedWid);
    cab->initWid(DbCabinetList::get(), new Log_CabElecQueryDlg(this));
    ui->stackedWid->addWidget(cab);

    SqlBtnBar *roomBar = new SqlBtnBar;
    roomBar->setNoEdit();  roomBar->clearHidden(); roomBar->queryHidden();
    SqlTableWid *roomTable = new SqlTableWid(ui->stackedWid);
    roomTable->initWid(DbRoomList::get(), roomBar);
    ui->stackedWid->addWidget(roomTable);
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
