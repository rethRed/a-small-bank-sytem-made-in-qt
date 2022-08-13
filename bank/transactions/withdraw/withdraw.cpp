#include "withdraw.h"
#include "ui_transactionwindow.h"

WithDraw::WithDraw()
{
    this->setWindowTitle("Withdraw");
    ui->label_title->setText("WithDraw");
    ui->pushButton_ok->setText("WithDraw");
    ui->lineEdit->setValidator(new QDoubleValidator());

    QObject::connect(ui->pushButton_ok, &QPushButton::clicked,this,&WithDraw::makeWithDraw);
}



void WithDraw::makeWithDraw()
{
    double amount = ui->lineEdit->text().toDouble();

    if(!TrackUserSection::setBalance(amount,"withdraw"))
    {
        QMessageBox::warning(nullptr,"warning","Something went wrong.");
        return;
    }
    this->close();
    emit operationFinished();
}
