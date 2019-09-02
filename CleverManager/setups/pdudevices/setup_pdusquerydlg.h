#ifndef SETUP_PDUSQUERYDLG_H
#define SETUP_PDUSQUERYDLG_H

#include "logquerybase.h"

namespace Ui {
class Setup_PdusQueryDlg;
}

class Setup_PdusQueryDlg : public QDialog , public LogQueryBase
{
    Q_OBJECT

public:
    explicit Setup_PdusQueryDlg(QWidget *parent = 0);
    ~Setup_PdusQueryDlg();

    QString getCmd();
    int Exec() {return this->exec();}
    virtual bool inputCheck();

private slots:
    void on_okBtn_clicked();
    void on_quitBtn_clicked();

private:
    Ui::Setup_PdusQueryDlg *ui;
};

#endif // SETUP_PDUSQUERYDLG_H
