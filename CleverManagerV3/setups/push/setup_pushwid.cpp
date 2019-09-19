#include "setup_pushwid.h"
#include "ui_setup_pushwid.h"

Setup_PushWid::Setup_PushWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setup_PushWid)
{
    ui->setupUi(this);
}

Setup_PushWid::~Setup_PushWid()
{
    delete ui;
}
