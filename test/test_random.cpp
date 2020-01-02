#include <stdbool.h>
#include <gtest/gtest.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
extern "C" {
    #include "gameOfLife.h"
    #include "rules.h"
    #include "render.h"
    #include "neighbor_counter.h"
}
#include "support.hpp"

class RandomTest : public ::testing::Test {
    protected:

        const static int numColsForRandomTests = 23;
        const static int numRowsForRandomTests = 10;
        char randomGridData[numRowsForRandomTests][numColsForRandomTests];
        struct Grid randomGrid;

        RandomTest() {
            randomGrid = (struct Grid){(char*)randomGridData, numRowsForRandomTests, numColsForRandomTests};
            randomizeGrid(randomGrid, time(0));
        }
};

TEST_F(RandomTest, random)
{
    display(randomGrid);

    for (int i = 0; i < 10; ++i) {
        sleep(1);
        tick(randomGrid);
        display(randomGrid);
    }
}

