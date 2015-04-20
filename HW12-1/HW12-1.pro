TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../hw12/gameoflife/demo.cpp \
    ../hw12/gameoflife/Map.cpp \
    ../hw12/gameoflife/Player.cpp \
    ../hw12/gameoflife/Property.cpp \
    ../hw12/gameoflife/Square.cpp

HEADERS += \
    ../hw12/gameoflife/Player.hpp \
    ../hw12/gameoflife/Property.hpp \
    ../hw12/gameoflife/Square.hpp \
    ../hw12/gameoflife/Map.hpp

