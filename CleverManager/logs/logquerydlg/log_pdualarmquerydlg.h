#ifndef LOG_PDUALARMQUERYDLG_H
#define LOG_PDUALARMQUERYDLG_H

#include <QDialog>
#include "logcomwid.h"
#include "dbpdualarm.h"

namespace Ui {
class Log_PduAlarmQueryDlg;
}

class Log_PduAlarmQueryDlg : public QDialog, public SqlQueryBase
{
    Q_OBJECT

public:
    explicit Log_PduAlarmQueryDlg(QWidget *parent = 0);
    ~Log_PduAlarmQueryDlg();

    QString getCmd();
    int Exec() {return this->exec();}
    virtual bool inputCheck();

private slots:
    void on_quitBtn_clicked();
    void on_okBtn_clicked();

protected:
    Ui::Log_PduAlarmQueryDlg *ui;
    SqlDateBar *mDateBar;
};

#endif // LOG_PDUALARMQUERYDLG_H