#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QValidator>
#include <QObject>
#include <QMessageBox>
#include "gui_interfaces/transaction/transactionwindow.h"
#include "interfaces/userSection/trackusersection.h"

class WithDraw : public TransactionWindow
{
    Q_OBJECT

public:
    WithDraw();

signals:
    void operationFinished();

private:
    void makeWithDraw();
};

#endif // WITHDRAW_H
