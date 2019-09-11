#ifndef DIALOGADDCABINET_H
#define DIALOGADDCABINET_H

#include <QDialog>
#include "dbcabinetlist.h"
#include <QTableWidget>


namespace Ui {
class Cab_AddDlg;
}

class Cab_AddDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Cab_AddDlg(QWidget *parent);
    ~Cab_AddDlg();

    void init(CabinetItem &item);

protected:
    bool checkInput();
    void getInput();
    virtual void save();

private slots:
    void on_quitBtn_clicked();
    void on_okBtn_clicked();

protected:
    Ui::Cab_AddDlg *ui;
    CabinetItem m_item;
};

class DialogModifyCabinet : public Cab_AddDlg
{
    Q_OBJECT

public:
    explicit DialogModifyCabinet(QWidget* parent);

protected:
    void save();
};

#endif // DIALOGADDCABINET_H
