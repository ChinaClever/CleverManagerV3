#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navbarwid.h"
#include "setupmainwid.h"
#include "logmainwid.h"
#include "pdu_mainwid.h"
#include "room_mainwid.h"
#include "tp_topologywid.h"
#include "cab_mainwid.h"

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
    Room_MainWid *mRoom;
    Tp_TopologyWid *mTpWid;
    Cab_MainWid *mCab;
};

#endif // MAINWINDOW_H
