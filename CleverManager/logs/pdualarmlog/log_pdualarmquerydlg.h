#ifndef LOG_PDUALARMQUERYDLG_H
#define LOG_PDUALARMQUERYDLG_H

#include <QDialog>
#include "logcomwid.h"
#include "dbpdualarm.h"

namespace Ui {
class Log_PduAlarmQueryDlg;
}

class Log_PduAlarmQueryDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Log_PduAlarmQueryDlg(QWidget *parent = 0);
    ~Log_PduAlarmQueryDlg();

    QString getCmd();

private slots:
    void on_quitBtn_clicked();
    void on_okBtn_clicked();

private:
    Ui::Log_PduAlarmQueryDlg *ui;
    SqlDateBar *mDateBar;
};

#endif // LOG_PDUALARMQUERYDLG_H
