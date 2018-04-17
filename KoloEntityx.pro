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
    movementsystem.cpp

HEADERS += \
    ResourcesManager.h \
    game.h \
    vertexdata.h \
    position.h \
    shape.h \
    rendersystem.h \
    velocity.h \
    movementsystem.h
