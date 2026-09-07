QT += sql opengl openglextensions

CONFIG += link_pkgconfig
PKGCONFIG += glib-2.0 dbus-glib-1 gstreamer-1.0 gstreamer-player-1.0 gstreamer-video-1.0 egl audioresource-qt nemo-gstreamer-interfaces-1.0

INCLUDEPATH += \
    $$PWD/src

HEADERS += \
    $$PWD/src/player/player.h \
    $$PWD/src/player/renderernemo.h \
    $$PWD/src/volume/pulseaudiocontrol.h

SOURCES += \
    $$PWD/src/player/player.cpp \
    $$PWD/src/player/renderernemo.cpp \
    $$PWD/src/volume/pulseaudiocontrol.cpp
