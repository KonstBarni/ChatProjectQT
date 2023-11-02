QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


SOURCES += \
    adddatabaseform.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    BadLogin.cpp \
    BadPassword.cpp \
    Chat.cpp \
    DataBase.cpp \
    Message.cpp \
    User.cpp \
    registrationform.cpp \
    startscreen.cpp

HEADERS += \
    adddatabaseform.h \
    loginform.h \
    mainwindow.h \
    BadLogin.h \
    BadPassword.h \
    Chat.h \
    DataBase.h \
    Message.h \
    User.h \
    registrationform.h \
    startscreen.h

FORMS += \
    adddatabaseform.ui \
    loginform.ui \
    mainwindow.ui \
    registrationform.ui \
    startscreen.ui

