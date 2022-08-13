#include "signin.h"
#include "ui_signin.h"
#include "ui_userverificationgui.h"

SignIn::SignIn(QWidget *parent) :
    UserVerificationGui(parent)
{
    this->setWindowTitle("Login");
    QObject::connect(ui->pushButton_click_here,&QPushButton::clicked,this,&SignIn::goToSignUp);
    QObject::connect(ui->btn_login,&QPushButton::clicked,this,&SignIn::makeLogin);
}

SignIn::~SignIn()
{

}

void SignIn::goToSignUp()
{
    this->close();
    SignUp *signUpWindow = new SignUp();
    signUpWindow->show();
}


bool SignIn::canMakeLogin(QString name, QString password)
{
    QSqlQuery qry;

    qry.prepare("select id from User where Name = :name and Password = :password");
    qry.bindValue(":name", name);
    qry.bindValue(":password", password);

    if(qry.exec()){

        if(qry.next()){
            return true;
        }
    }else
    {
    qCritical() << qry.lastError();
    }
    return false;

}

void SignIn::makeLogin()
{
    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_password->text();

    if(!canMakeLogin(name,password)){
        QMessageBox::warning(nullptr,"Error","Name or password is invalid.");
        return;
    }

    if(TrackUserSection::setCurrentUser(name, password)){

        this->close();
        BankWindow *bankWidow = new BankWindow();
        bankWidow->show();

    }else{
        QMessageBox::warning(nullptr,"Error","It was not possible to make login.");
    };




//    QSqlQuery qry;

//    qry.prepare("insert into User(Name,Password) values(:name,:password)");
//    qry.bindValue(":name", name);
//    qry.bindValue(":password", password);

//    if(qry.exec())
//    {
//        QMessageBox::information(nullptr,"successfully","Sign up successfully made.");
//        return;

//    }else
//    {
//        qCritical() << qry.lastError();
//        QMessageBox::warning(nullptr,"Error","It was not possible to make login.");
//        return;
//    }
}
