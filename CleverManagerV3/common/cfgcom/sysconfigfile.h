#ifndef SYSCONFIGFILE_H
#define SYSCONFIGFILE_H
#include <QtCore>

bool com_cfg_open(void);
void com_cfg_close(void);
QString com_cfg_readStr(QString, QString strGroup="System");
int com_cfg_readInt(QString, QString strGroup="System");
double com_cfg_readDouble(QString, QString strGroup="System");
void com_cfg_write(QString, QString, QString strGroup="System");

void com_cfg_writeParam(QString, QString, QString strGroup="System");
extern QString cm_pathOfData(const QString& name);

#endif // SYSCONFIGFILE_H

