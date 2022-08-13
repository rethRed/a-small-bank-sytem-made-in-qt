#ifndef TRACKUSERSECTION_H
#define TRACKUSERSECTION_H

#include <QString>
#include <QSqlQuery>

class TrackUserSection
{
public:
    TrackUserSection();

    static bool setCurrentUser(QString name, QString password);
    static void removeCurrentUser();
    static bool setBalance(double balance, QString transactionType);
    static int getUserId();
    static double getBalance();



private:
    static int userId;
    static bool userLoggedIn;

};

#endif // TRACKUSERSECTION_H
