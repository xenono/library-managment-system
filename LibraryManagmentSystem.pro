QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appwindow.cpp \
    loginpage.cpp \
    main.cpp \
    signuppage.cpp \
    startpage.cpp \
    startwindow.cpp

HEADERS += \
    appwindow.h \
    loginpage.h \
    signuppage.h \
    startpage.h \
    startwindow.h

FORMS += \
    appwindow.ui \
    loginpage.ui \
    signuppage.ui \
    startpage.ui \
    startwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
