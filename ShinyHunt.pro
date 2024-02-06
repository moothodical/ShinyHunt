QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/data/huntdata.cpp \
    src/data/huntdatalistmodel.cpp \
    src/data/pokemongame.cpp \
    src/data/pokemonparser.cpp \
    src/gui/main.cpp \
    src/gui/mainwindow.cpp \
    src/gui/newhuntwindow.cpp \
    src/gui/huntwindow.cpp \
    src/gui/showhunts.cpp

HEADERS += \
    src/data/huntdata.h \
    src/data/huntdatalistmodel.h \
    src/data/pokemongame.h \
    src/data/pokemonparser.h \
    src/gui/mainwindow.h \
    src/gui/newhuntwindow.h \
    src/gui/huntwindow.h \
    src/gui/showhunts.h

FORMS += \
    src/gui/mainwindow.ui \
    src/gui/newhuntwindow.ui \
    src/gui/huntwindow.ui \
    src/gui/showhunts.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
