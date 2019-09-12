#include "landinguser.h"


bool usr_land_jur()
{
    return LandingUser::get()->user.jur;
}

QString user_land_name()
{
     return LandingUser::get()->user.name;
}


LandingUser::LandingUser()
{
    land = false;
    init();
}


LandingUser *LandingUser::get()
{
    static LandingUser* sington = nullptr;
    if(sington == nullptr)
        sington = new LandingUser();
    return sington;
}

void LandingUser::init()
{
    DbUser* db = DbUser::bulid();
    int ret = db->counts();
    if(ret < 1) {
        user.jur = 1;
        user.jurisdiction =  QObject::tr("管理员");
        user.name = "admin";
        user.pwd = "admin";
        user.telephone = "18576689472";
        user.email = "luozhiyong131@qq.com";
        user.remarks = QObject::tr("默认账号，请修改账号信息");
        db->insertItem(user);
    }
}


