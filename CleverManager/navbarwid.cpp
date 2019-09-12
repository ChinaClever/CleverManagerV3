#include "navbarwid.h"
#include "ui_navbarwid.h"

NavBarWid::NavBarWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavBarWid)
{
    ui->setupUi(this);
    set_background_icon(this,":/image/title_back.jpg");
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
    emit navBarSig(4);
}

void NavBarWid::on_logBtn_clicked()
{
    emit navBarSig(1);
}

void NavBarWid::on_pduBtn_clicked()
{
     emit navBarSig(2);
}

void NavBarWid::on_roomBtn_clicked()
{
    emit navBarSig(3);
}

void NavBarWid::on_tpBtn_clicked()
{
    emit navBarSig(0);
}
