#ifndef DP_BASICTHREAD_H
#define DP_BASICTHREAD_H
#include "dp_basichash.h"
#include <QtSql>

class Dp_DbTran
{
public:
    Dp_DbTran() {QSqlDatabase::database().transaction();}
    ~Dp_DbTran() {QSqlDatabase::database().commit();}
};

template <typename T>
class Dp_BasicThread : public QThread, public Dp_BasicHash<T>
{
public:
    Dp_BasicThread(QObject *parent = nullptr): QThread(parent) {isRun=true; start();}
    ~Dp_BasicThread() { isRun = false; wait();}

protected:
    void run(){
        initFun();
        while (isRun) {
            msleep(1000 + rand()%230);
            static QReadWriteLock lock;
            QWriteLocker locker(&lock);

            Dp_DbTran db;
            workDown();
        }
    }

    void workDown() {
        QHashIterator<QString, T> iter(mHash);
        while(iter.hasNext())
        {
            iter.next();
            if(iter.value()) {
                T pack = iter.value();
                if(pack->en) {
                    pack->count++;
                    workDown(pack);
                }
            }
        }
    }

    virtual void initFun()=0;
    virtual void workDown(T pack)=0;

protected:
    bool isRun;
    QHash<QString, T> mHash;
};

#endif // DP_BASICTHREAD_H
