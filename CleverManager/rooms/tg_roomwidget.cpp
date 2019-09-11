/*
 * tg_roomwidget.cpp
 * 统计界面机房列表处理
 *
 *  Created on: 2016年10月11日
 *      Author: Lzy
 */
#include "tg_roomwidget.h"
#include "ui_tg_roomwidget.h"
#include<fstream>
#include "dp_roompackets.h"

TG_RoomWidget::TG_RoomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TG_RoomWidget)
{
    ui->setupUi(this);

    initWid();
    QTimer::singleShot(1000,this,SLOT(initFunSLot())); //延时初始化
    connect(DbRoomList::get(), SIGNAL(itemChanged(int,int)), this,SLOT(itemChangedSlot(int,int)));
}

TG_RoomWidget::~TG_RoomWidget()
{
    delete ui;
}


void TG_RoomWidget::initFunSLot()
{
    ui->comboBox->clear();
    QStringList rooms = DbRoomList::get()->list();
    ui->comboBox->addItems(rooms);
    if(rooms.size()) ui->comboBox->setCurrentIndex(0);

    //this->setStyleSheet("background-color: rgb(0,45,130);color: rgb(0, 0, 0);");
    //set_background_color(this, QColor(0,45,130));
}


void TG_RoomWidget::initWid()
{
    mBar = new Room_BarGraph(ui->barWid);
    connect(this, SIGNAL(roomSelectSig(sRoomPacket*)), mBar, SLOT(packetSlot(sRoomPacket*)));

    mData = new Room_DataWid(ui->dataWid);
    connect(this, SIGNAL(roomSelectSig(sRoomPacket*)), mData, SLOT(packetSlot(sRoomPacket*)));

    mPow = new Room_PowerGraph(ui->powWid);
    connect(this, SIGNAL(roomSelectSig(sRoomPacket*)), mPow, SLOT(packetSlot(sRoomPacket*)));

    mVc = new Room_VcGraph(ui->vcWid);
    connect(this, SIGNAL(roomSelectSig(sRoomPacket*)), mVc, SLOT(packetSlot(sRoomPacket*)));
}

/**
 * @brief 当机房发生改变时 响应函数
 * @param id
 * @param type
 */
void TG_RoomWidget::itemChangedSlot(int,int)
{
    initFunSLot();
}

/**
 * @brief 上一机房
 */
void TG_RoomWidget::on_upBtn_clicked()
{
    int index = ui->comboBox->currentIndex()-1;
    if(index < 0) index = ui->comboBox->count() -1;
    ui->comboBox->setCurrentIndex(index);
}

/**
 * @brief 下一机房
 */
void TG_RoomWidget::on_downBtn_clicked()
{
    int index = ui->comboBox->currentIndex()+1;
    if(index >= ui->comboBox->count())
        index = 0;
    ui->comboBox->setCurrentIndex(index);
}



void TG_RoomWidget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1.isEmpty()) return;
    ui->roomLabel->setText(tr("机房:") + arg1);
    sRoomPacket *p = Dp_RoomPackets::bulid(this)->get(arg1);
    if(p)  emit roomSelectSig(p);
}
