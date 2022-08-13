#include "trackusersection.h"
#include "qsqlerror.h"

int TrackUserSection::userId;
bool TrackUserSection::userLoggedIn;

TrackUserSection::TrackUserSection()
{

}



bool TrackUserSection::setCurrentUser(QString name, QString password)
{
    QSqlQuery qry;

    qry.prepare("select Id from User where Name = :name and password = :password");
    qry.bindValue(":name", name);
    qry.bindValue(":password", password);

    if(qry.exec()){

        if(qry.next())
        {
            TrackUserSection::userId = qry.value(0).toInt();
            TrackUserSection::userLoggedIn = true;
            return true;
        }else
        {
            return false;
        }
    }else
    {
        qry.lastError();
    }

    return false;
}

void TrackUserSection::removeCurrentUser()
{
    TrackUserSection::userId = 0;
    TrackUserSection::userLoggedIn = false;
}



bool TrackUserSection::setBalance(double balance, QString transactionType)
{
    if(!TrackUserSection::userLoggedIn){return false;}

    double newBalance;

    if(transactionType == "deposit")
    {
        newBalance = TrackUserSection::getBalance() + balance;
    }
    else if(transactionType == "withdraw")
    {
        newBalance = TrackUserSection::getBalance() - balance;
    }
    else {return false;}

    QSqlQuery qry;

    qry.prepare("update User set Balance = :newAmount where Id = :id");
    qry.bindValue(":newAmount", newBalance);
    qry.bindValue(":id", TrackUserSection::userId);

    if(!qry.exec()){
        qDebug() << qry.lastError();
        return false;
    }

    qry.prepare("insert into UserTransactions(IdUser ,Date ,Type, amount)  values (:idUser, datetime('now','localtime'), :type, :amount)");
    qry.bindValue(":idUser", TrackUserSection::userId);
    qry.bindValue(":type", transactionType);
    qry.bindValue(":amount", balance);

    if(qry.exec()){
        return true;
    }else
    {
        qDebug() << qry.lastError();
    }

    return false;
}

double TrackUserSection::getBalance()
{
    if(!TrackUserSection::userLoggedIn){return false;}

    QSqlQuery qry;

    qry.prepare("select Balance from User where Id = :id");
    qry.bindValue(":id", TrackUserSection::userId);

    if(qry.exec())
    {
        if(qry.next())
        {
            return qry.value(0).toDouble();
        }
        return 0;

    }else
    {
        qry.lastError();
    }
    return 0;

}



int TrackUserSection::getUserId()
{
    return TrackUserSection::userId;
}






