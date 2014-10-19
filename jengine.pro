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
    utils/directory.cpp \
    managers/configuration_manager.cpp \
    graphics/utils/vlayout.cpp \
    graphics/utils/movable.cpp \
    graphics/utils/jdrawable.cpp \
    managers/texture_manager.cpp \
    graphics/objects/sprite.cpp \
    game/utils/tab_indexable.cpp \
    game/managers/event_manager.cpp \
    game/views/menu.cpp

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
    utils/directory.hpp \
    managers/configuration_manager.hpp \
    graphics/utils/vlayout.hpp \
    graphics/utils/movable.hpp \
    graphics/utils/jdrawable.hpp \
    game/utils/defines.hpp \
    managers/texture_manager.hpp \
    graphics/objects/sprite.hpp \
    game/utils/tab_indexable.hpp \
    game/managers/event_manager.hpp \
    game/views/menu.hpp
