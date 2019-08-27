#ifndef SQLTABLEWID_H
#define SQLTABLEWID_H
#include "sqltableview.h"
#include "sqlbtnbar.h"

namespace Ui {
class SqlTableWid;
}

class SqlTableWid : public QWidget
{
    Q_OBJECT

public:
    explicit SqlTableWid(QWidget *parent = 0);
    ~SqlTableWid();

    void setNoEdit();
    void initWid(const QString& name, BasicSql *db, QStringList &list,  SqlBtnBar *btn);

signals:
    void refreshSig();
    void querySig(const QString &);

protected slots:
    void initFunSLot();
    void exportSlot();

private:
    Ui::SqlTableWid *ui;
    SqlBtnBar *mBtnBar;
    SqlTableView *mTableView;
    QString mTableTile;
    SqlExportDlg *mExportDlg;
};

#endif // SQLTABLEWID_H
