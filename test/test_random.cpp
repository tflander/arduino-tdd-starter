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
#include "consoleDisplayAdapter.hpp"

class RandomTest : public BaseGridTest {

    protected:

        const static int numRows = 10;
        const static int numCols = 23;
        RandomTest() : BaseGridTest(numRows, numCols) {}

        ConsoleDisplayAdapter displayAdapter;
};

TEST_F(RandomTest, random)
{
    randomizeGrid(grid, time(0));
    displayAdapter.display(grid);

    for (int i = 0; i < 10; ++i) {
        sleep(1);
        tick(grid);
        displayAdapter.display(grid);
    }
}

