QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    page1.cpp \
    page2.cpp \
    page3.cpp \
    page4.cpp

HEADERS += \
    confirmationcode.h \
<<<<<<< HEAD
=======
    confirmationcode.h \
>>>>>>> b810aeec8e7c09d68e7ca96bf5104e924d5fa0b9
    page1.h \
    page2.h \
    page3.h \
    page4.h

FORMS += \
    page1.ui \
    page2.ui \
    page3.ui \
    page4.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    p1.qrc \
    page1image.qrc \
    page2image.qrc \
    refresh.qrc \
    show_pass_icon.qrc

DISTFILES +=
