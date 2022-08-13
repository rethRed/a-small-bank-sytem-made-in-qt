#include "Login/signin.h"
#include "DataBase/databaseconnection.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!connectToDataBase())
    {
        QMessageBox::critical(nullptr,"error", "Unable to make the dataBase Connection!");
        exit(0);
    }

    SignIn signIn;
    signIn.show();

    return a.exec();
}
