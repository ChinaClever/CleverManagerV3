#include "ipstabwid.h"

IpsTabWid::IpsTabWid(QWidget *parent) : ComTableWid(parent)
{
    initWid();
    mData = Up_DataPacket::bulid()->data;
}

void IpsTabWid::initWid()
{
    QString title = tr("需升级IP列表");
    QStringList header;
    header <<title;

    initTableWid(header, 0, title);
}

void IpsTabWid::updateData(QStringList &lst)
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

void IpsTabWid::timeoutDone()
{
    updateData(mData->ips);
}
