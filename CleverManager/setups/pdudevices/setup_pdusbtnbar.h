#ifndef SETUP_PDUSBTNBAR_H
#define SETUP_PDUSBTNBAR_H

#include "setup_pdusquerydlg.h"

class Setup_PdusBtnBar : public SqlBtnBar
{
    Q_OBJECT
public:
    explicit Setup_PdusBtnBar(QWidget *parent = nullptr);
    void setDlg(LogQueryBase *dlg){mQueryDlg=dlg;}

protected:
    virtual QString queryBtn();

protected:
    LogQueryBase *mQueryDlg;
};

#endif // SETUP_PDUSBTNBAR_H
