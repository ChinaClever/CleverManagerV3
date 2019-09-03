#ifndef IPSWID_H
#define IPSWID_H

#include <QWidget>

namespace Ui {
class IpsWid;
}

class IpsWid : public QWidget
{
    Q_OBJECT

public:
    explicit IpsWid(QWidget *parent = 0);
    ~IpsWid();

protected:
    void disEnable();
    bool readFile(QString &fn, QStringList &list);
    int bulidIps(QString startIp, QString &endIp);
    int getIpInt(QString &ip);

private slots:
    void on_exportBtn_clicked();
    void on_ipBtn_clicked();
    void on_ipsBtn_clicked();
    void on_ipRadio_clicked(bool checked);
    void on_ipsRadio_clicked(bool checked);
    void on_exportRadio_clicked(bool checked);

    void on_getRadio_clicked(bool checked);

    void on_getBtn_clicked();

private:
    Ui::IpsWid *ui;
    QStringList mList;
};

#endif // IPSWID_H
