#ifndef LOG_LANDQUERYDLG_H
#define LOG_LANDQUERYDLG_H

#include <QDialog>
#include "logcomwid.h"
#include "dbuserlandlog.h"

namespace Ui {
class Log_LandQueryDlg;
}

class Log_LandQueryDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Log_LandQueryDlg(QWidget *parent = 0);
    ~Log_LandQueryDlg();
    QString getCmd();

private slots:
    void on_quitBtn_clicked();
    void on_okBtn_clicked();

private:
    Ui::Log_LandQueryDlg *ui;
    SqlDateBar *mDateBar;
};

#endif // LOG_LANDQUERYDLG_H
