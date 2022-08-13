#ifndef TRANSACTIONWINDOW_H
#define TRANSACTIONWINDOW_H

#include <QDialog>

namespace Ui {
class TransactionWindow;
}

class TransactionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionWindow(QWidget *parent = nullptr);
    ~TransactionWindow();

protected:
    Ui::TransactionWindow *ui;
};

#endif // TRANSACTIONWINDOW_H
