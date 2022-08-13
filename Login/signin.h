#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlError>
#include "interfaces/login/makelogin.h"
#include "gui_interfaces/verification/userverificationgui.h"
#include "interfaces/userSection/trackusersection.h"
#include "bank/bankwindow.h"
#include "Sign_up/signup.h"

namespace Ui {
class SignIn;
}

class SignIn : public UserVerificationGui, public MakeLogin
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

    void goToSignUp();

    // MakeLogin interface
private:
    bool canMakeLogin(QString name, QString password) override;
    void makeLogin() override;
};

#endif // SIGNIN_H
