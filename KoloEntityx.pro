TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
LIBS += -lentityx

SOURCES += main.cpp \
    ResourcesManager.cpp \
    game.cpp \
    rendersystem.cpp \
    movementsystem.cpp \
    circleshape.cpp \
    rotation.cpp \
    spawnsystem.cpp \
    spawn.cpp \
    collisionsystem.cpp \
    collisionevent.cpp \
    rigidcollision.cpp \
    vector_common.cpp \
    player.cpp \
    playersystem.cpp \
    spawnevent.cpp \
    bullet.cpp \
    timer.cpp \
    lifetime.cpp \
    lifetimesystem.cpp \
    destructionmenager.cpp \
    deathpenalty.cpp \
    color.cpp

HEADERS += \
    ResourcesManager.h \
    game.h \
    vertexdata.h \
    position.h \
    shape.h \
    rendersystem.h \
    velocity.h \
    movementsystem.h \
    circleshape.h \
    rotation.h \
    spawnsystem.h \
    spawn.h \
    collisionsystem.h \
    collisionevent.h \
    rigidcollision.h \
    vector_common.h \
    player.h \
    playersystem.h \
    spawnevent.h \
    bullet.h \
    timer.h \
    lifetime.h \
    lifetimesystem.h \
    destructionmenager.h \
    deathpenalty.h \
    color.h
