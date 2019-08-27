#include "sqltablewid.h"
#include "ui_sqltablewid.h"

SqlTableWid::SqlTableWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SqlTableWid)
{
    ui->setupUi(this);
    mTableView = new SqlTableView(ui->viewWid);
    mExportDlg = new SqlExportDlg(this);
}

SqlTableWid::~SqlTableWid()
{
    delete ui;
}

void SqlTableWid::initWid(const QString &name, BasicSql *db, QStringList &list,  SqlBtnBar *btn)
{
    mBtnBar = btn;
    mTableTile = name;

    mTableView->initTable(db, list);
    btn->setParent(ui->btnWid);
    initFunSLot();
}

void SqlTableWid::setNoEdit()
{
    mBtnBar->setNoEdit();
    mTableView->setNoEdit();
}

void SqlTableWid::initFunSLot()
{
    connect(mBtnBar,SIGNAL(exportSig()),this,SLOT(exportSlot()));
    connect(mBtnBar,SIGNAL(delSig()),mTableView,SLOT(delSlot()));
    connect(mBtnBar,SIGNAL(modifySig()),mTableView,SLOT(submitSlot()));
    connect(mBtnBar,SIGNAL(clearSig()),mTableView,SLOT(clearTableSlot()));
    connect(mBtnBar,SIGNAL(refreshSig()),mTableView,SLOT(refreshSlot()));
    connect(mBtnBar,SIGNAL(querySig(const QString &)),mTableView,SLOT(queryFilter(const QString &)));
    connect(this,SIGNAL(querySig(const QString &)),mTableView,SLOT(queryFilter(const QString &)));
    connect(mBtnBar,SIGNAL(refreshSig()),this,SIGNAL(refreshSig()));
}

void SqlTableWid::exportSlot()
{
    QList<QStringList> list;
    mTableView->getList(list);
    mExportDlg->init(mTableTile, list);
    mExportDlg->exec();
}
