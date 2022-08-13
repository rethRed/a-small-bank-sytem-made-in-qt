#include "deposit.h"
#include "ui_transactionwindow.h"


Deposit::Deposit()
{
    this->setWindowTitle("Deposit");
    ui->label_title->setText("Deposit");
    ui->pushButton_ok->setText("Deposit");
    ui->lineEdit->setValidator(new QDoubleValidator());

    QObject::connect(ui->pushButton_ok, &QPushButton::clicked,this,&Deposit::makeDeposit);

}



void Deposit::makeDeposit()
{
    double amount = ui->lineEdit->text().toDouble();

    if(!TrackUserSection::setBalance(amount,"deposit"))
    {
        QMessageBox::warning(nullptr,"warning","Something went wrong.");
        return;
    }
    this->close();
    emit operationFinished();
}
