#ifndef DP_HASHBASIC_H
#define DP_HASHBASIC_H
#include <QtCore>

template <typename T>
class Dp_HashBasic
{
protected:
    virtual T newDataPacket()=0;
    T insert(const QString &key) {
        T node = find(key);
        if(!node) {
            node = newDataPacket();
            mHash.insert(key, node);
        }

        return node;
    }

    T find(const QString &key) {
        T node = nullptr;
        bool ret = contains(key);
        if(ret) {
            auto index = mHash.find(key);
            if(index != mHash.end()) {
                node = index.value();
            }
        }
        return node;
    }

    void remove(const QString &key) {
        T node = find(key);
        if(node) {
            mHash.remove(key);
            delete node;
        }
    }

    bool contains(const QString &key) {return mHash.contains(key);}

protected:
    QHash<QString, T> mHash;
};

#endif // DP_HASHBASIC_H
