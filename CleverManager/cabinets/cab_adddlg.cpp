#include "cab_adddlg.h"
#include "ui_cab_adddlg.h"
#include <QMessageBox>
#include <QIntValidator>


Cab_AddDlg::Cab_AddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cab_AddDlg)
{
    ui->setupUi(this);
}

Cab_AddDlg::~Cab_AddDlg()
{
    delete ui;
}

void Cab_AddDlg::init(CabinetItem &item)
{
    ui->cabEdit->setText(item.cab);
    ui->ipEdit_1->setText(item.main_ip);
    ui->ipEdit_2->setText(item.spare_ip);
    ui->powSpin->setValue(item.pow);
    ui->heightSpin->setValue(item.height);

    if(!item.main_ip.isEmpty()) {
        ui->comboBox_1->setCurrentText(item.main_num);
        ui->typeCb_1->setCurrentText(item.main_type);
    }

    if(!item.spare_ip.isEmpty()) {
        ui->comboBox_2->setCurrentText(item.spare_num);
        ui->typeCb_2->setCurrentText(item.spare_type);
    }
    m_item = item;
}



bool Cab_AddDlg::checkInput()
{
    QString ipAddr = ui->ipEdit_1->text();
    bool ret = cm_isIPaddress(ipAddr);
    if(!ret) {
        CriticalMsgBox box(this,tr("主机IP地址无效(%1)!").arg(ipAddr));
        return false;
    }

    ipAddr = ui->ipEdit_2->text();
    ret = cm_isIPaddress(ipAddr);
    if(!ret) {
        CriticalMsgBox box(this,tr("备机IP地址无效(%1)!").arg(ipAddr));
        return false;
    }

    QString name = ui->cabEdit->text();
    if(name.isEmpty()){
        CriticalMsgBox box(this,tr("机柜名称为空！请填写有效名称！"));
        return false;
    }

    int rtn = DbCabinetList::get()->contains(m_item.room, name);
    if(rtn > 0)  {
        CriticalMsgBox box(this,tr("机柜中已有对应名称机柜(%1),请重命名！").arg(name));
        return false;
    }

    return true;
}

void Cab_AddDlg::getInput()
{
    m_item.cab = ui->cabEdit->text();
    m_item.main_ip = ui->ipEdit_1->text();
    m_item.main_num = ui->comboBox_1->currentText();
    m_item.main_type = ui->typeCb_1->currentText();

    m_item.spare_ip = ui->ipEdit_2->text();
    m_item.spare_num = ui->comboBox_2->currentText();
    m_item.spare_type = ui->typeCb_2->currentText();
    m_item.height = ui->heightSpin->value();
    m_item.pow = ui->powSpin->value();
}


void Cab_AddDlg::save()
{
    DbCabinetList::get()->insertItem(m_item);
}


void Cab_AddDlg::on_okBtn_clicked()
{
    bool ret = checkInput();
    if(ret) {
        getInput();
        save();
        accept();
    }
}

void Cab_AddDlg::on_quitBtn_clicked()
{
    this->close();
}



Cab_ModifyDlg::Cab_ModifyDlg(QWidget *parent) :
    Cab_AddDlg(parent)
{
    this->setWindowTitle(tr("修改机柜"));
    ui->label_describe->setText(tr("请填写修改机柜的详细信息："));
}


void Cab_ModifyDlg::save()
{
    DbCabinetList::get()->updateItem(m_item);
}
