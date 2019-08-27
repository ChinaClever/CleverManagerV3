#include "sqltableview.h"
#include <QGridLayout>

SqlTableView::SqlTableView(QWidget *parent) : QWidget(parent)
{
    tableView = new QTableView(this);
    tableView->setSortingEnabled(true);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);//
    tableView->resizeColumnsToContents();

    model = new SqlTableModel(tableView);
    tableView->setModel(model->model);
    tableView->horizontalHeader()->setStretchLastSection(true);

    QGridLayout *gridLayout = new QGridLayout(parent);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->addWidget(this);
}


/**
 * @brief 初始化表格
 */
void SqlTableView::initTable(BasicSql *db, QStringList &list)
{
    QString table = db->tableName();
    this->refreshTable(table);

    mHeadList = list;
    model->setHeaders(mHeadList);
}



/**
 * @brief 列平均分配
 */
void SqlTableView::setStretch()
{
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

/**
 * @brief 禁用编辑功能
 */
void SqlTableView::setNoEdit()
{
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁用编辑功能
}

void SqlTableView::submitSlot()
{
    bool ret = model->submitChanges();
    if(!ret) {
        QMessageBox::warning(this, mDb->tableName(),
                             tr("数据库错误: %1").arg(model->model->lastError().text()));
    }
}

void SqlTableView::querySlot(const QString &str)
{
    model->queryFilter(str);
}

/**
 * @brief 插入一行
 * @param list
 */
void SqlTableView::insertRow(QStringList &list)
{
    int rowNum = model->model->rowCount(); //获得表的行数
    model->model->insertRow(rowNum); //添加一行

    int id = mDb->maxId() + 1;
    QModelIndex index = model->model->index(rowNum,0);
    model->model->setData(index,id);
    for(int i=0; i< list.size(); ++i) {
        index = model->model->index(rowNum,i+1);
        model->model->setData(index,list.at(i));
    }
    //    submitSlot();
}

/**
 * @brief 刷新表格
 * @param table 表格名
 * @return
 */
bool SqlTableView::refreshTable(const QString &table)
{
    bool ret = model->refreshTable(table);
    if(ret) {
        mHiddens.clear();
        tableView->sortByColumn(0, Qt::DescendingOrder); // 降序排列
        setColumnHidden(0);
    }
    return  ret;
}

void SqlTableView::setColumnHidden(int column)
{
    mHiddens << column;
    tableView->setColumnHidden(column, true);
}

void SqlTableView::refreshSlot()
{
    initTable(mDb, mHeadList);
}

/**
 * @brief 清空数据库
 */
void SqlTableView::clearTableSlot()
{
    model->model->setTable("markingtable");
    BasicSql* db = mDb;
    db->clear();
    db->createTable();
    initTable(mDb, mHeadList);
}

/**
 * @brief 删除一条纪录
 */
void SqlTableView::delSlot()
{
    int curRow = tableView->currentIndex().row();
    model->removeRow(curRow);
}



int SqlTableView::getList(QList<QStringList> &list)
{
    list.append(mHeadList);

    int row = model->model->rowCount();
    for(int j=0; j<row; ++j) {
        QStringList strList;
        int column = model->model->columnCount();
        for(int i=0; i<column; ++i)
        {
            if(mHiddens.contains(i)) continue;
            QModelIndex index = model->model->index(j, i);
            strList << model->model->data(index, Qt::DisplayRole).toString();
        }
        list.append(strList);
    }
    return list.size();
}

