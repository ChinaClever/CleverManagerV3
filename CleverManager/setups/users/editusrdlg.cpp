/*
 * editusrdlg.cpp
 *  用户信息修改界面
 *
 *  Created on: 2016年10月11日
 *      Author: Lzy
 */
#include "editusrdlg.h"

EditUsrDlg::EditUsrDlg(QWidget *parent) :
    NewUsrDlg(parent)
{
    QString str = tr("编辑用户");
    editTitle(str);
}

EditUsrDlg::~EditUsrDlg()
{
}


void EditUsrDlg::setUsrId(int id)
{
    mId = id;
    sUserItem user = DbUser::bulid()->findById(id);
    loadUsrInfo(user);
}


bool EditUsrDlg::saveUsrInfo(sUserItem &user)
{
    user.id = mId;
    DbUser* db = DbUser::bulid();
    bool ret = db->updateItem(user);
    if(ret) {
        sUserLogItem item;
        item.name = LandingUser::get()->user.name;
        item.remarks = tr("修改用户");
        DbUserLog::bulid()->insertItem(item);
    }

    return ret;
}
