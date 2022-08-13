#include "userverificationgui.h"
#include "ui_userverificationgui.h"

UserVerificationGui::UserVerificationGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserVerificationGui)
{
    ui->setupUi(this);

}

UserVerificationGui::~UserVerificationGui()
{
    delete ui;
}





