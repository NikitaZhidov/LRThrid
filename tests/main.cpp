#include "loadTL_test.h"
#include "loadDL_test.h"
#include "delT_test.h"
#include "madeT_test.h"
#include "makeT_test.h"
#include "editT_test.h"

#include <gtest/gtest.h>


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
