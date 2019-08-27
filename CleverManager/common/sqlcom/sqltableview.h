#ifndef SQLTABLEVIEW_H
#define SQLTABLEVIEW_H
#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>
#include "sqltablemodel.h"

class SqlTableView : public QWidget
{
    Q_OBJECT
public:
    explicit SqlTableView(QWidget *parent = nullptr);

    void initTable(BasicSql *db, QStringList &list);

    bool refreshTable(const QString &table);
    void setStretch();
    void setColumnHidden(int column);
    int getList(QList<QStringList> &list);
    void setNoEdit();
    void insertRow(QStringList &list);

public slots:
    void delSlot();
    void clearTableSlot();
    void refreshSlot();
    void submitSlot();
    void querySlot(const QString &);

public:
    BasicSql *mDb;
    QStringList mHeadList;
    SqlTableModel *model;

private:
    QTableView *tableView;
    QList<int> mHiddens;
};

#endif // SQLTABLEVIEW_H
