#include <stdbool.h>

#include <gtest/gtest.h>

using namespace ::testing;

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern "C" {
    #include "gameOfLife.h"
    #include "rules.h"
    #include "render.h"
    #include "neighbor_counter.h"
}
#include "support.hpp"
#include "consoleDisplayAdapter.hpp"

class OscillatorTest : public BaseGridTest {

    protected:

        const static int numRows = 12;
        const static int numCols = 12;
        OscillatorTest() : BaseGridTest(numRows, numCols) {}

        ConsoleDisplayAdapter displayAdapter;
};


TEST_F(OscillatorTest, pinwheel)
{
    setGrid(grid,
        "......XX....",
        "......XX....",
        "............",
        "....XXXX....",
        "XX.X..X.X...",
        "XX.XX...X...",
        "...X.X..X.XX",
        "...X....X.XX",
        "....XXXX....",
        "............",
        "....XX......",
        "....XX......"
    );

    tick(grid);
    displayAdapter.display(grid);
    
    verifyGrid(grid,
        "......XX....",
        "......XX....",
        "............",
        "....XXXX....",
        "XX.X..X.X...",
        "XX.X.X..X...",
        "...X...XX.XX",
        "...X....X.XX",
        "....XXXX....",
        "............",
        "....XX......",
        "....XX......"
    );

    for (int i = 0; i < 10; ++i) {
        sleep(1);
        tick(grid);
        displayAdapter.display(grid);
    }
}

