TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jengine/game/managers/event_manager.cpp \
    jengine/game/managers/signal_manager.cpp \
    jengine/game/utils/tab_indexable.cpp \
    jengine/game/views/menu.cpp \
    jengine/graphics/objects/button.cpp \
    jengine/graphics/objects/rectangle.cpp \
    jengine/graphics/objects/sprite.cpp \
    jengine/graphics/objects/text.cpp \
    jengine/graphics/utils/container.cpp \
    jengine/graphics/utils/jdrawable.cpp \
    jengine/graphics/utils/movable.cpp \
    jengine/graphics/utils/vlayout.cpp \
    jengine/graphics/object.cpp \
    jengine/graphics/view.cpp \
    jengine/managers/configuration_manager.cpp \
    jengine/managers/font_manager.cpp \
    jengine/managers/texture_manager.cpp \
    jengine/utils/directory.cpp \
    pazaak/views/main_menu.cpp \
    pazaak/game.cpp \
    jengine/graphics/jwindow.cpp \
    pazaak/views/settings.cpp \
    jengine/graphics/objects/multi_choice.cpp \
    jengine/graphics/utils/hlayout.cpp \
    jengine/graphics/utils/layout.cpp \
    jengine/graphics/objects/slide_bar.cpp


CONFIG += c++11

LIBS += -lboost_system -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    jengine/game/managers/event_manager.hpp \
    jengine/game/managers/signal_manager.hpp \
    jengine/game/utils/tab_indexable.hpp \
    jengine/game/views/menu.hpp \
    jengine/graphics/objects/button.hpp \
    jengine/graphics/objects/rectangle.hpp \
    jengine/graphics/objects/sprite.hpp \
    jengine/graphics/objects/text.hpp \
    jengine/graphics/utils/container.hpp \
    jengine/graphics/utils/jdrawable.hpp \
    jengine/graphics/utils/movable.hpp \
    jengine/graphics/utils/properties.hpp \
    jengine/graphics/utils/vlayout.hpp \
    jengine/graphics/object.hpp \
    jengine/graphics/view.hpp \
    jengine/managers/configuration_manager.hpp \
    jengine/managers/font_manager.hpp \
    jengine/managers/texture_manager.hpp \
    jengine/utils/logging/easylogging++.h \
    jengine/utils/directory.hpp \
    jengine/defines.hpp \
    pazaak/views/main_menu.hpp \
    pazaak/defines.hpp \
    pazaak/game.hpp \
    jengine/graphics/jwindow.hpp \
    pazaak/views/settings.hpp \
    jengine/graphics/objects/multi_choice.hpp \
    jengine/utils/fonts.hpp \
    jengine/graphics/utils/hlayout.hpp \
    jengine/graphics/utils/layout.hpp \
    jengine/graphics/objects/slide_bar.hpp
