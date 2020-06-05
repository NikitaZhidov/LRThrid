QT += quick

TEMPLATE = app


SOURCES += \
    helper.cpp \
    main.cpp


HEADERS += \ \
    helper.h


RESOURCES += qml.qrc

//QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
