#ifndef LANDINGUSER_H
#define LANDINGUSER_H
#include "dbuserlog.h"

QString user_land_name();

class LandingUser : public QObject
{
    Q_OBJECT
    LandingUser();
public:
    static LandingUser* get();
    sUserItem user;
    bool land;

signals:
    void landSig();

protected:
    void init();

};

#endif // LANDINGUSER_H
