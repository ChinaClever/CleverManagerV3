#include "devselectwid.h"
#include "ui_devselectwid.h"
#include "msgbox.h"

DevSelectWid::DevSelectWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DevSelectWid)
{
    ui->setupUi(this);
    mData = Up_DataPacket::bulid()->data;
    timer = new QTimer(this);
    timer->start(200);
    connect(timer, SIGNAL(timeout()),this, SLOT(timeoutDone()));
    mCount = 1;
}

DevSelectWid::~DevSelectWid()
{
    delete ui;
}


void DevSelectWid::timeoutDone(void)
{
    this->setDisabled(mData->isRun);
}


bool DevSelectWid::checkInput()
{
    QString str;
    QString user =ui->userEdit->text();
    if(user.isEmpty())
        str = tr("用户名不能为空，请重新输入!!");

    QString pwd = ui->pwdEdit->text();
    if(pwd.isEmpty())
        str = tr("密码不能为空，请重新输入!!");

    bool ret = true;
    if(str.isEmpty()) {
        mData->usr = user;
        mData->pwd = pwd;
    } else {
        ret = false;
        CriticalMsgBox box(this, str);
    }

    return ret;
}

void DevSelectWid::setenabled(bool e)
{
    ui->comboBox->setEnabled(e);
    ui->userEdit->setEnabled(e);
    ui->pwdEdit->setEnabled(e);
}

void DevSelectWid::on_okBtn_clicked()
{
    bool en = false;
    QString str = tr("修改");
    if(mCount++ %2) {
        if(mData->devtype) {
            if(!checkInput()) {
                mCount--; return;
            }
        }
    } else {
        en = true;
        str = tr("确认");
    }

    setenabled(en);
    ui->okBtn->setText(str);
}

void DevSelectWid::on_comboBox_currentIndexChanged(int index)
{
    bool en = true;
    mData->devtype = index;
    if(index < 2) en = false;
    ui->userEdit->setEnabled(en);
    ui->pwdEdit->setEnabled(en);

    QString dev_type = ui->comboBox->currentText();
    Up_DataPacket::bulid()->data->dev_type = dev_type;
}


