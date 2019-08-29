#ifndef USRLANDDLG_H
#define USRLANDDLG_H

#include <QDialog>
#include "editusrdlg.h"

namespace Ui {
class UsrLandDlg;
}

class UsrLandDlg : public QDialog
{
    Q_OBJECT

public:
    explicit UsrLandDlg(QWidget *parent = 0);
    ~UsrLandDlg();

    bool quitWidget(void);
    int selectWork(void);

protected:
    void usrLand(void);

private slots:
    void on_landBtn_clicked();
    void on_pushButton_clicked();

private:
    Ui::UsrLandDlg *ui;
};

#endif // USRLANDDLG_H