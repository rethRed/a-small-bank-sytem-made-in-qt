#ifndef USERVERIFICATIONGUI_H
#define USERVERIFICATIONGUI_H

#include <QMainWindow>

namespace Ui {
class UserVerificationGui;
}

class UserVerificationGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserVerificationGui(QWidget *parent = nullptr);
    ~UserVerificationGui();

protected:
    Ui::UserVerificationGui *ui;
};

#endif // USERVERIFICATIONGUI_H
