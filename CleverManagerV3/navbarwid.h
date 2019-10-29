﻿#ifndef NAVBARWID_H
#define NAVBARWID_H

#include "usermainwid.h"

namespace Ui {
class NavBarWid;
}

class NavBarWid : public QWidget
{
    Q_OBJECT

public:
    explicit NavBarWid(QWidget *parent = 0);
    ~NavBarWid();

signals:
    void navBarSig(int);

protected:
    void enableBtn();

private slots:
    void on_userBtn_clicked();
    void on_setupBtn_clicked();
    void on_logBtn_clicked();

    void on_pduBtn_clicked();

    void on_roomBtn_clicked();

    void on_tpBtn_clicked();

    void on_cabBtn_clicked();

private:
    void setBtndefault(QPushButton *btn, const QString &str);
    void initBtnColour();
    void setBtnClicked(QPushButton *btn, const QString &str);

private:
    Ui::NavBarWid *ui;

};

#endif // NAVBARWID_H