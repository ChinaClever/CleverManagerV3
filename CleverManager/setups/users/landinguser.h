#ifndef LANDINGUSER_H
#define LANDINGUSER_H
#include "dbuserlandlog.h"

class LandingUser
{
    LandingUser();
public:
    static LandingUser* get();
    sUserItem user;
    bool land;

protected:
    void init();

};

#endif // LANDINGUSER_H
