#include "bankwindow.h"
#include "ui_bankwindow.h"

BankWindow::BankWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BankWindow)
{
    ui->setupUi(this);
    loadUserData();
    tableDisplay.setTable(ui->tableWidget_history);
}

BankWindow::~BankWindow()
{
    delete ui;
}

void BankWindow::loadUserData()
{
    ui->label_balance->setText("Balance: $"+ QString::number(TrackUserSection::getBalance(), 'f', 2 ));
}



void BankWindow::on_pushButton_deposit_clicked()
{
    Deposit *depositWindow = new Deposit();
    QObject::connect(depositWindow,&Deposit::operationFinished,this,&BankWindow::loadUserData);
    depositWindow->exec();
}


void BankWindow::on_pushButton_withdraw_clicked()
{
    WithDraw *withdrawWindow = new WithDraw;
    QObject::connect(withdrawWindow,&WithDraw::operationFinished,this,&BankWindow::loadUserData);
    withdrawWindow->exec();
}


void BankWindow::on_actionLeave_triggered()
{

    TrackUserSection::removeCurrentUser();
    this->close();

    SignIn *signIn = new SignIn;
    signIn->show();
}


void BankWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0){
        loadUserData();
    }
    else if(index == 1){
        setSearchFilter(ui->comboBox_transaction_type->currentText());
    }
}




void BankWindow::on_comboBox_transaction_type_currentIndexChanged(int index)
{
    setSearchFilter(ui->comboBox_transaction_type->currentText());
}

void BankWindow::setSearchFilter(QString filter)
{
    QString StringQry = "select Date, cast(amount as Text) amount from UserTransactions where Type = '%1' and IdUser = %2 order by Date desc";
    StringQry = StringQry.arg(filter.toLower()).arg(TrackUserSection::getUserId());
    tableDisplay.setQuery(StringQry);

    QSqlQuery qry;
    StringQry = "select count(amount) from (select amount from UserTransactions where Type = '%1' and IdUser = %2)";
    StringQry = StringQry.arg(filter.toLower()).arg(TrackUserSection::getUserId());

    if(qry.exec(StringQry)){
        if(qry.next())
        {
            ui->label_quantity_found_history->setText("Found: "+QString::number(qry.value(0).toInt()));

        }
    }else{
        qDebug() << qry.lastError();
    }
    ui->tableWidget_history->resizeColumnsToContents();

}
