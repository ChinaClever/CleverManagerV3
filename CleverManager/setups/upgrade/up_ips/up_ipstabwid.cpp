#include "up_ipstabwid.h"

Up_IpsTabWid::Up_IpsTabWid(QWidget *parent) : ComTableWid(parent)
{
    initWid();
    mData = Up_DataPacket::bulid()->data;
}

void Up_IpsTabWid::initWid()
{
    QString title = tr("需升级IP列表");
    QStringList header;
    header <<title;

    initTableWid(header, 0, title);
}

void Up_IpsTabWid::updateData(QStringList &lst)
{
    if(lst.size()) {
        checkTableRow(lst.size());
        for(int i=0; i<lst.size(); ++i)
        {
            QStringList list;
            list << lst.at(i);
            setTableRow(i, list);
        }
    } else {
        clearTable();
    }
}

void Up_IpsTabWid::timeoutDone()
{
    updateData(mData->ips);
}
