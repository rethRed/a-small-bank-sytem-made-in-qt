#ifndef MAKESIGNUP_H
#define MAKESIGNUP_H

#include <QString>

class MakeSignUp
{
public:
    virtual bool canSignUp(QString name, QString password) = 0;
    virtual void makeSignUp() = 0;
};

#endif // MAKESIGNUP_H
