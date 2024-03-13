#-------------------------------------------------
# Project created by QtCreator 2024-03-13T00:00:00
#-------------------------------------------------

QT       += core gui widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include

# Source files
SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/person.cpp

# Header files
HEADERS += \
    include/SerializeDeserialize.hpp \
    include/mainwindow.hpp \
    include/person.hpp

# Form files
FORMS += \
    ui/mainwindow.ui

# Deployment rules
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Additional files
DISTFILES += \
    database.txt
