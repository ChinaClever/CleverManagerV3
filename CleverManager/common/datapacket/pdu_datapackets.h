#ifndef PDU_DATAPACKETS_H
#define PDU_DATAPACKETS_H

#include <QObject>

class Pdu_DataPackets : public QObject
{
    Q_OBJECT
public:
    explicit Pdu_DataPackets(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PDU_DATAPACKETS_H