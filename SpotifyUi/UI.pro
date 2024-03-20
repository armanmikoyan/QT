QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    components/body/body.cpp \
    components/friends/friendlist.cpp \
    components/musicPlayer/musicplayer.cpp \
    components/navbar/navbar.cpp \
    components/search/searchbar.cpp \
    src/main.cpp \
    src/main_window.cpp

HEADERS += \
    components/body/body.hpp \
    components/friends/friendlist.hpp \
    components/musicPlayer/musicplayer.hpp \
    components/navbar/navbar.hpp \
    components/search/searchbar.hpp \
    src/main_window.hpp

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
