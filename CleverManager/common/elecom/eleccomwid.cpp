#include "eleccomwid.h"
#include "ui_eleccomwid.h"

ElecComWid::ElecComWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElecComWid)
{
    ui->setupUi(this);
    groupBox_background_icon(this);
    mSqlTableWid = new SqlTableWid(ui->widget);
}

ElecComWid::~ElecComWid()
{
    delete ui;
}

void ElecComWid::initWid(BasicSql *db,  LogQueryBase *btn)
{
    LogBtnBar *bar = new LogBtnBar;
    bar->setDlg(btn);
    mSqlTableWid->initWid(db, bar);
    ui->groupBox->setTitle(db->tableTile);
}
