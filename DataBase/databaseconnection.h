#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QFileInfo>
#include <QSqlQuery>
#include <QSqlError>


bool makeDataBaseFromScratch();


bool connectToDataBase();


class DataBaseConnection
{
public:
    DataBaseConnection();
};

#endif // DATABASECONNECTION_H
