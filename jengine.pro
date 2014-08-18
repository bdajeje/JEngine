TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    graphics/window.cpp \
    graphics/object.cpp \
    graphics/view.cpp \
    game/views/main_menu.cpp \
    graphics/objects/button.cpp \
    graphics/utils/container.cpp \
    managers/font_manager.cpp \
    graphics/objects/text.cpp \
    graphics/objects/rectangle.cpp \
    graphics/utils/sizable.cpp \
    utils/directory.cpp \
    managers/configuration_manager.cpp \
    graphics/utils/vlayout.cpp

CONFIG += c++11

LIBS += -lboost_system -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    graphics/window.hpp \
    defines.hpp \
    graphics/object.hpp \
    graphics/view.hpp \
    game/views/main_menu.hpp \
    graphics/objects/button.hpp \
    graphics/window.hpp \
    graphics/utils/properties.hpp \
    graphics/utils/container.hpp \
    managers/font_manager.hpp \
    graphics/objects/text.hpp \
    graphics/objects/rectangle.hpp \
    graphics/utils/sizable.hpp \
    utils/directory.hpp \
    managers/configuration_manager.hpp \
    graphics/utils/vlayout.hpp
