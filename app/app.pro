QT += core quick quickcontrols2 multimedia network
QT += widgets

TEMPLATE = app
CONFIG += c++11 qt
CONFIG -= app_bundle

SOURCES += \
    helper.cpp \
    main.cpp


HEADERS += \ \
    helper.h


RESOURCES += qml.qrc

QMAKE_CFLAGS += -Wall -Wextra -Werror
QMAKE_CXXFLAGS += -std=c++0x
# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
