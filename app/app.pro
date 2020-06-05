QT += quick
QT += widgets
TEMPLATE = app


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
