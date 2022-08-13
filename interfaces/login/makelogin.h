#ifndef MAKELOGIN_H
#define MAKELOGIN_H

#include <QString>

class MakeLogin
{
public:
    virtual bool canMakeLogin(QString name, QString password) = 0;
    virtual void makeLogin() = 0;
};

#endif // MAKELOGIN_H
