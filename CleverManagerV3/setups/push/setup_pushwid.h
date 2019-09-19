#ifndef SETUP_PUSHWID_H
#define SETUP_PUSHWID_H

#include <QWidget>

namespace Ui {
class Setup_PushWid;
}

class Setup_PushWid : public QWidget
{
    Q_OBJECT

public:
    explicit Setup_PushWid(QWidget *parent = 0);
    ~Setup_PushWid();

private:
    Ui::Setup_PushWid *ui;
};

#endif // SETUP_PUSHWID_H
