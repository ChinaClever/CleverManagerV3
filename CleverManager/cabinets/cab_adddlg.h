#ifndef DIALOGADDCABINET_H
#define DIALOGADDCABINET_H

#include <QDialog>
#include "dbcabinetlist.h"
#include <QTableWidget>
#include "dbuserlog.h"

namespace Ui {
class Cab_AddDlg;
}

class Cab_AddDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Cab_AddDlg(QWidget *parent);
    ~Cab_AddDlg();

    CabinetItem *getItem() {return &m_item;}
    virtual void save();

    void del(CabinetItem &item);

protected:
    void init(CabinetItem &item);
    bool checkInput();
    virtual bool nameCheck(const QString &name);
    void getInput();

protected slots:
    void on_quitBtn_clicked();
    virtual void on_okBtn_clicked();

protected:
    Ui::Cab_AddDlg *ui;
    CabinetItem m_item;
};

class Cab_ModifyDlg : public Cab_AddDlg
{
    Q_OBJECT

public:
    explicit Cab_ModifyDlg(QTableWidget* parent, CabinetItem &it);

protected:
    void save();
    bool nameCheck(const QString &name){return true;}
};

#endif // DIALOGADDCABINET_H
