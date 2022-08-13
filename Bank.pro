QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataBase/databaseconnection.cpp \
    Login/signin.cpp \
    Sign_up/signup.cpp \
    bank/bankwindow.cpp \
    gui_interfaces/transaction/transactionwindow.cpp \
    gui_interfaces/verification/userverificationgui.cpp \
    interfaces/tableDisplay/itemtabledisplay.cpp \
    interfaces/userSection/trackusersection.cpp \
    Bank/transactions/deposit/deposit.cpp \
    Bank/transactions/withdraw/withdraw.cpp \
    main.cpp

HEADERS += \
    DataBase/databaseconnection.h \
    Login/signin.h \
    bank/bankwindow.h \
    gui_interfaces/transaction/transactionwindow.h \
    gui_interfaces/verification/userverificationgui.h \
    interfaces \
    Bank/transactions/deposit/deposit.h \
    Bank/transactions/withdraw/withdraw.h \
    interfaces/login/makelogin.h \
    Sign_up/signup.h \
    interfaces/signup/makesignup.h \
    interfaces/tableDisplay/itemtabledisplay.h \
    interfaces/userSection/trackusersection.h



FORMS += \
    bank/bankwindow.ui \
    gui_interfaces/transaction/transactionwindow.ui \
    gui_interfaces/verification/userverificationgui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
