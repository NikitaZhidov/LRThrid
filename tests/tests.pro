include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG += thread


QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     \
    ../app/helper.h \
    delT_test.h \
    editT_test.h \
    loadDL_test.h \
    loadTL_test.h \
    madeT_test.h \
    makeT_test.h

SOURCES +=     main.cpp \
    ../app/helper.cpp \

INCLUDEPATH += ../app
