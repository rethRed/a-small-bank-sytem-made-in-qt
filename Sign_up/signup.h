#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include "gui_interfaces/verification/userverificationgui.h"
#include "interfaces/signup/makeSignUp.h"
#include "Login/signin.h"
#include "interfaces/userSection/trackusersection.h"
#include <QMessageBox>

namespace Ui {
class SignUp;
}

class SignUp : public UserVerificationGui, public MakeSignUp
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

    void goToSignIn();

private:

    // MakeSignUp interface
public:
    bool canSignUp(QString name, QString password) ;
    void makeSignUp() ;
};

#endif // SIGNUP_H
