#include "dialoginforequest.h"
#include "ui_dialoginforequest.h"
#include <QMessageBox>


DialogInfoRequest::DialogInfoRequest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInfoRequest)
{
    ui->setupUi(this);
}

DialogInfoRequest::DialogInfoRequest(QWidget *parent, const QString &title, const QString &text) :
    QDialog(parent),ui(new Ui::DialogInfoRequest)
{
    ui->setupUi(this);
    this->setWindowTitle(title);
    ui->label_text->setText(text);
}

DialogInfoRequest::~DialogInfoRequest()
{
    delete ui;
}

void DialogInfoRequest::accept()
{
    QDialog::accept();
}

void DialogInfoRequest::delRoom(int id, const QString &name)
{
    DbRoomList::get()->remove(id);

    sUserLogItem log;
    log.remarks = tr("机房管理：");
    log.remarks += tr("删除机房:%1").arg(name);
    DbUserLog::bulid()->insertItem(log);
}
