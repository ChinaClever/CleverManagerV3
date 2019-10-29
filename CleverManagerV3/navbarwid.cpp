/*
 *
 *  Created on: 2019年10月1日
 *      Author: Lzy
 */
#include "navbarwid.h"
#include "ui_navbarwid.h"

NavBarWid::NavBarWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavBarWid)
{
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(parent);//控制ToolBox自适应
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->addWidget(this);
    initBtnColour();
    //set_background_icon(this,":/image/title_back.jpg");
}

NavBarWid::~NavBarWid()
{
    delete ui;
}

/**
 * @brief 主界面按键使能、锁定
 * @param en
 */
void NavBarWid::enableBtn()
{
    bool en = LandingUser::get()->land;
    ui->setupBtn->setEnabled(en);
    ui->logBtn->setEnabled(en);
}




/**
 * @brief 用户登录
 */
void NavBarWid::on_userBtn_clicked()
{
    UsrLandDlg dlg;
    bool lang = LandingUser::get()->land;
    if(lang) {
        int ret = dlg.selectWork();
        if(ret == 1) // 用户切换
            dlg.exec();
        else if(ret == 2) // 用户退出
            dlg.quitWidget();
    } else {
        dlg.exec();
    }

    enableBtn();
}

void NavBarWid::on_setupBtn_clicked()
{
    setBtnClicked(ui->setupBtn, "ser");
    emit navBarSig(4);
}

void NavBarWid::on_logBtn_clicked()
{
    setBtnClicked(ui->logBtn, "log");
    emit navBarSig(1);
}

void NavBarWid::on_pduBtn_clicked()
{
    setBtnClicked(ui->pduBtn, "dev");
    emit navBarSig(2);
}

void NavBarWid::on_roomBtn_clicked()
{
    setBtnClicked(ui->roomBtn, "tg");
    emit navBarSig(3);
}

void NavBarWid::on_tpBtn_clicked()
{
    setBtnClicked(ui->tpBtn, "topo");
    emit navBarSig(0);
}

void NavBarWid::on_cabBtn_clicked()
{
    setBtnClicked(ui->cabBtn, "detail");
    emit navBarSig(5);
}

void NavBarWid::setBtndefault(QPushButton *btn, const QString &str)
{
    QString strNormal = tr("QPushButton{border-image: url(:/toolbutton/toolbutton/%1_normal.png);}").arg(str);
    QString strSelect = tr("QPushButton:hover{border-image: url(:/toolbutton/toolbutton/%1_select.png);}").arg(str);
    QString strClicked = tr("QPushButton:pressed{border-image: url(:/toolbutton/toolbutton/%1_clicked.png);}").arg(str);

    btn->setStyleSheet(strNormal + strSelect + strClicked);
    btn->setText("");
}

/**
 * @brief 初始化按键颜色
 */
void NavBarWid::initBtnColour()
{
    setBtndefault(ui->tpBtn, "topo");
    setBtndefault(ui->roomBtn, "tg");
    setBtndefault(ui->cabBtn, "detail");
    setBtndefault(ui->pduBtn, "dev");
    setBtndefault(ui->setupBtn, "ser");
    setBtndefault(ui->logBtn, "log");
    setBtndefault(ui->userBtn, "usr");
}

void NavBarWid::setBtnClicked(QPushButton *btn, const QString &str)
{
    initBtnColour();
    QString strNormal = tr("QPushButton{border-image: url(:/toolbutton/toolbutton/%1_clicked.png);}").arg(str);
    QString strSelect = tr("QPushButton:hover{border-image: url(:/toolbutton/toolbutton/%1_select.png);}").arg(str);
    QString strClicked = tr("QPushButton:pressed{border-image: url(:/toolbutton/toolbutton/%1_clicked.png);}").arg(str);

    btn->setStyleSheet(strNormal + strSelect + strClicked);
}
