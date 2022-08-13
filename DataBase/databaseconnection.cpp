#include "databaseconnection.h"

DataBaseConnection::DataBaseConnection()
{

}




bool connectToDataBase()
{
    QSqlDatabase dataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString DataBasePath = QFileInfo(".").absolutePath()+"/Bank/DataBase/DataBase.db";
    dataBase.setDatabaseName(DataBasePath);

    if(dataBase.open())
    {
        return makeDataBaseFromScratch();
    }
    return false;


}


bool makeDataBaseFromScratch()
{
    QString createTableTransactionType;
    createTableTransactionType = QStringLiteral(
      "CREATE TABLE IF NOT EXISTS 'TransactionType' ("
      "     'type'	TEXT NOT NULL,"
      "     PRIMARY KEY('type')"
      ");");

    QString createTableUser;
    createTableUser = QStringLiteral(
      "CREATE TABLE IF NOT EXISTS 'User' ("
      "     'Id'	INTEGER NOT NULL,"
      "     'Name'	TEXT NOT NULL,"
      "     'Password'	TEXT NOT NULL,"
      "     'Balance'	REAL NOT NULL,"
      "     PRIMARY KEY('Id' AUTOINCREMENT)"
      ");");

    QString createTableUserTransactions;
    createTableUserTransactions = QStringLiteral(
      "CREATE TABLE IF NOT EXISTS 'UserTransactions' ("
      "     'Id'	INTEGER NOT NULL,"
      "     'IdUser'	INTEGER,"
      "     'Date'	TEXT NOT NULL,"
      "     'Type'	TEXT NOT NULL,"
      "     'amount'	REAL NOT NULL,"
      "     FOREIGN KEY('Type') REFERENCES 'TransactionType'('type') "
      "     ON UPDATE CASCADE ON DELETE SET NULL,"
      "     FOREIGN KEY('IdUser') REFERENCES 'User'('Id') "
      "     ON UPDATE CASCADE ON DELETE CASCADE,"
      "     PRIMARY KEY('Id')"
      ")"
      ""
      "");

    QSqlQuery qry;

    qry.prepare(createTableTransactionType);

    if(!qry.exec()){
        qDebug() << qry.lastError();
        return false;
    }

    qry.prepare(createTableUser);
    if(!qry.exec()){
        qDebug() << qry.lastError();
        return false;
    }

    qry.prepare(createTableUserTransactions);
    if(!qry.exec()){
        qDebug() << qry.lastError();
        return false;
    }

    return true;

}




