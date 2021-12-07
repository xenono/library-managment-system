QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appwindow.cpp \
    database.cpp \
    loginpage.cpp \
    main.cpp \
    profilepage.cpp \
    signuppage.cpp \
    startpage.cpp \
    startwindow.cpp \
    user.cpp

HEADERS += \
    appwindow.h \
    database.h \
    loginpage.h \
    profilepage.h \
    signuppage.h \
    startpage.h \
    startwindow.h \
    user.h

FORMS += \
    appwindow.ui \
    loginpage.ui \
    profilepage.ui \
    signuppage.ui \
    startpage.ui \
    startwindow.ui

QT += sql
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../mysql/lib/release/ -lmysqlcppconn
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../mysql/lib/debug/ -lmysqlcppconn
else:unix: LIBS += -L$$PWD/../../mysql/lib/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../../mysql/include
DEPENDPATH += $$PWD/../../mysql/include

unix:!macx: LIBS += -L$$PWD/../../mysql/lib/ -lmysqlcppconn-static

INCLUDEPATH += $$PWD/../../mysql/include
DEPENDPATH += $$PWD/../../mysql/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../mysql/lib/libmysqlcppconn-static.a

unix:!macx: LIBS += -L$$PWD/../../mysql/lib/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../../mysql/include
DEPENDPATH += $$PWD/../../mysql/include
