#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navbarwid.h"
#include "setupmainwid.h"
#include "logmainwid.h"

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
    void initFunSLot();
    void navBarSlot(int);

private:
    Ui::MainWindow *ui;
    NavBarWid *mNavBar;
    SetUpMainWid *mSetup;
    LogMainWid *mLog;
    UserMainWid *mUserWid;
};

#endif // MAINWINDOW_H
