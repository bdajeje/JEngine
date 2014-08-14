TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    graphics/window.cpp \
    graphics/object.cpp \
    graphics/view.cpp \
    graphics/utils/sizable.cpp \
    game/views/main_menu.cpp \
    graphics/utils/movable.cpp \
    graphics/objects/button.cpp

CONFIG += c++11

LIBS += -lboost_system -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    graphics/window.hpp \
    defines.hpp \
    graphics/object.hpp \
    graphics/view.hpp \
    graphics/utils/sizable.hpp \
    game/views/main_menu.hpp \
    graphics/utils/movable.hpp \
    graphics/objects/button.hpp \
    graphics/window.hpp
