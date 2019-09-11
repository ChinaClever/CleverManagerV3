#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navbarwid.h"
#include "setupmainwid.h"
#include "logmainwid.h"
#include "pdu_mainwid.h"
#include "tg_roomwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
//    void initFunSLot();
    void initPacksSLot();
    void initNetWork();
    void initWidSLot();

    void navBarSlot(int);

private:
    Ui::MainWindow *ui;
    NavBarWid *mNavBar;
    SetUpMainWid *mSetup;
    LogMainWid *mLog;
    UserMainWid *mUserWid;
    Pdu_MainWid *mPduWid;
    TG_RoomWidget *mRoom;
};

#endif // MAINWINDOW_H
