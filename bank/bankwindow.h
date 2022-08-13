#ifndef BANKWINDOW_H
#define BANKWINDOW_H

#include <QMainWindow>
#include "Login/signin.h"
#include "bank/transactions/deposit/deposit.h"
#include "bank/transactions/withdraw/withdraw.h"
#include "interfaces/tableDisplay/itemtabledisplay.h"

namespace Ui {
class BankWindow;
}

class BankWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BankWindow(QWidget *parent = nullptr);
    ~BankWindow();
    void loadUserData();
    void setSearchFilter(QString filter);

private slots:
    void on_pushButton_deposit_clicked();
    void on_pushButton_withdraw_clicked();

    void on_actionLeave_triggered();

    void on_tabWidget_currentChanged(int index);

    void on_comboBox_transaction_type_currentIndexChanged(int index);

private:
    ItemTableDisplay tableDisplay;
    Ui::BankWindow *ui;
};

#endif // BANKWINDOW_H
