#include "usermainwid.h"
#include "ui_usermainwid.h"

UserMainWid::UserMainWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserMainWid)
{
    ui->setupUi(this);

    LandingUser::get();
    mBtnBar = new UserBtnBar;
    mDbTable = new SqlTableWid(ui->widget);
    mDbTable->initWid(DbUser::get(), mBtnBar);
}

UserMainWid::~UserMainWid()
{
    delete ui;
}
