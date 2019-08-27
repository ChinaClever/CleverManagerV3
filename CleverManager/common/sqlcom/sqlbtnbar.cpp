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


void SqlBtnBar::setNoEdit()
{
    ui->addBtn->setHidden(true);
    ui->modifyBtn->setHidden(true);
    ui->delBtn->setHidden(true);
}

void SqlBtnBar::on_refreshBtn_clicked()
{
    emit refreshSig();
}

void SqlBtnBar::on_addBtn_clicked()
{

}

void SqlBtnBar::on_modifyBtn_clicked()
{
    QString str = tr("是否提交修改内容?");
    QuMsgBox box(this, str);
    bool ret = box.Exec();
    if(ret) {
        emit modifySig();
    }
}

void SqlBtnBar::on_delBtn_clicked()
{
    QString str = tr("是否删除这条纪录?");
    QuMsgBox box(this, str);
    bool ret = box.Exec();
    if(ret) {
        emit delSig();
    }
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

}

void SqlBtnBar::on_exportBtn_clicked()
{
    emit exportSig();
}
