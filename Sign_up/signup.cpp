#include "signup.h"
#include "ui_signup.h"
#include "ui_userverificationgui.h"

SignUp::SignUp(QWidget *parent) :
    UserVerificationGui(parent)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign Up");
    ui->label_title->setText("Sing Up");
    ui->btn_login->setText("Sign Up");
    ui->label_fotter_text->setText("Already have an account? ");

    QObject::connect(ui->pushButton_click_here,&QPushButton::clicked,this,&SignUp::goToSignIn);
    QObject::connect(ui->btn_login,&QPushButton::clicked,this,&SignUp::makeSignUp);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::goToSignIn()
{
    this->close();
    SignIn *signInWindow = new SignIn();
    signInWindow->show();
}


bool SignUp::canSignUp(QString name, QString password)
{
    QSqlQuery qry;

    qry.prepare("select id from User where Name = :name and Password = :password");
    qry.bindValue(":name", name);
    qry.bindValue(":password", password);

    if(qry.exec()){

        if(qry.next())
        {
            return false;
        }else
        {
            return true;
        }

    }else
    {
    qCritical() << qry.lastError();
    }
    return false;
}

void SignUp::makeSignUp()
{

    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_password->text();

    if(!canSignUp(name,password)){
        QMessageBox::warning(nullptr,"Error","userName In use...");
        return;
    }

    QSqlQuery qry;

    qry.prepare("insert into User(Name,Password, Balance) values(:name,:password, 0.00)");
    qry.bindValue(":name", name);
    qry.bindValue(":password", password);

    if(qry.exec())
    {
        QMessageBox::information(nullptr,"successfully","Sign up successfully made.");
        goToSignIn();
        return;

    }else
    {
        qCritical() << qry.lastError();
        QMessageBox::warning(nullptr,"Error","It was not possible to make login.");
        return;
    }


}




