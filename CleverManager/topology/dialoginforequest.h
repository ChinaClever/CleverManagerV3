#ifndef DIALOGEDITCABINETMAP_H
#define DIALOGEDITCABINETMAP_H

#include "tp_addroomdlg.h"

namespace Ui {
class DialogInfoRequest;
}

class DialogInfoRequest : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInfoRequest(QWidget *parent = 0);
    explicit DialogInfoRequest(QWidget *parent ,const QString &title,const QString& text);
    ~DialogInfoRequest();

    void delRoom(int id, const QString &name);
public slots:
    void accept();
private:
    Ui::DialogInfoRequest *ui;
};

#endif // DIALOGEDITCABINETMAP_H
