#include "sqlbtnbar.h"
#include "ui_sqlbtnbar.h"

SqlBtnBar::SqlBtnBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SqlBtnBar)
{
    ui->setupUi(this);
}

SqlBtnBar::~SqlBtnBar()
{
    delete ui;
}

void SqlBtnBar::importHidden()
{
    ui->importBtn->setHidden(true);
}

void SqlBtnBar::clearHidden()
{
    ui->clearBtn->setHidden(true);
}

void SqlBtnBar::queryHidden()
{
    ui->queryBtn->setHidden(true);
}

void SqlBtnBar::gridLayout(QWidget *parent)
{
    QGridLayout *gridLayout = new QGridLayout(parent);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->addWidget(this);
}

void SqlBtnBar::setNoEdit()
{
    ui->addBtn->setHidden(true);
    ui->modifyBtn->setHidden(true);
    ui->delBtn->setHidden(true);
    ui->importBtn->setHidden(true);
}

void SqlBtnBar::on_refreshBtn_clicked()
{
    InfoMsgBox box(this, tr("刷新成功!"));
    emit refreshSig();
}

void SqlBtnBar::on_addBtn_clicked()
{
    addBtn();
    emit refreshSig();
}

void SqlBtnBar::on_modifyBtn_clicked()
{   
    emit modifySig();
}

void SqlBtnBar::modifySlot(int id)
{
    QString str = tr("请确认需要进行修改?");
    QuMsgBox box(this, str);
    bool ret = box.Exec();
    if(ret) {
        modifyBtn(id);
    }
    emit refreshSig();
}

void SqlBtnBar::delSlot(int id)
{
    bool ret = delBtn(id);
    if(!ret) return;

    QString str = tr("是否删除这条纪录?");
    QuMsgBox box(this, str);
    ret = box.Exec();
    if(ret) {
        emit delSig(id);
    }
}

void SqlBtnBar::on_delBtn_clicked()
{
    emit delSig();
}

void SqlBtnBar::on_clearBtn_clicked()
{
    QString str = tr("是否清空纪录?");
    QuMsgBox box(this, str);
    bool ret = box.Exec();
    if(ret) {
        emit clearSig();
    }
}

void SqlBtnBar::on_queryBtn_clicked()
{
    queryBtn();
}

void SqlBtnBar::on_exportBtn_clicked()
{
    emit exportSig();
}

void SqlBtnBar::on_importBtn_clicked()
{
    bool ret = importBtn();
    if(ret) {
        InfoMsgBox box(this, tr("数据导入成功!"));
        emit refreshSig();
    }
}
