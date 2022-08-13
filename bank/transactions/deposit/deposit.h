#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QValidator>
#include <QObject>
#include <QMessageBox>
#include "gui_interfaces/transaction/transactionwindow.h"
#include "interfaces/userSection/trackusersection.h"

class Deposit :  public TransactionWindow
{
    Q_OBJECT


public:
    Deposit();

signals:
    void operationFinished();

private:
    void makeDeposit();

};

#endif // DEPOSIT_H
