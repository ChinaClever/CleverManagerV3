/*
 *
 *  Created on: 2019年10月1日
 *      Author: Lzy
 */
#include "usermainwid.h"
#include "ui_usermainwid.h"

UserMainWid::UserMainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserMainWid)
{
    ui->setupUi(this);
    //groupBox_background_icon(this);
    ui->groupBox->setTitle(tr("用户管理"));

    LandingUser::get();
    mBtnBar = new UserBtnBar;
    mDbTable = new SqlTableWid(ui->widget);
    mDbTable->initWid(DbUser::bulid(), mBtnBar);
}

UserMainWid::~UserMainWid()
{
    delete ui;
}
