#ifndef LOGQUERYBASE_H
#define LOGQUERYBASE_H
#include "sqltablewid.h"

class LogQueryBase
{
public:
    LogQueryBase();

    virtual QString getCmd()=0;
    virtual int Exec()=0;
};

#endif // LOGQUERYBASE_H
