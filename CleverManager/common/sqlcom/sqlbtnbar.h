#ifndef SQLBTNBAR_H
#define SQLBTNBAR_H

#include "sqldatebar.h"

namespace Ui {
class SqlBtnBar;
}

class SqlBtnBar : public QWidget
{
    Q_OBJECT

public:
    explicit SqlBtnBar(QWidget *parent = 0);
    ~SqlBtnBar();

    void setNoEdit();

signals:
    void delSig();
    void modifySig();
    void refreshSig();
    void clearSig();
    void exportSig();
    void querySig(const QString &);

protected:
    virtual void on_addBtn_clicked();
    virtual void on_modifyBtn_clicked();
    virtual void on_queryBtn_clicked();

private slots:
    void on_refreshBtn_clicked();
    void on_delBtn_clicked();
    void on_clearBtn_clicked();
    void on_exportBtn_clicked();

private:
    Ui::SqlBtnBar *ui;
};

#endif // SQLBTNBAR_H
