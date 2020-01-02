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

const int numColsForPinwheelTests = 12;
const int numRowsForPinwheelTests = 12;
char gridData[numRowsForPinwheelTests][numColsForPinwheelTests];
struct Grid gridForPinwheel = (struct Grid){(char*)gridData, numRowsForPinwheelTests, numColsForPinwheelTests};

class OscillatorTest : public ::testing::Test {

 private:

    static void myPreDisplay() {
        printf("\nGame Of Life\n");
    }

    static void myPostDisplay() {
        printf("^^^^^^^^^^^^^^\n");
    }

    static void myDisplayCell(struct Point point, char mark) {
        printf("%c", mark);
    }

    static void myEndRow() {
        printf("|\n");
    }

 protected:

  void SetUp() override {
    struct displayFunctionPointers fp = {
        .displayCellFunction = myDisplayCell,
        .preDisplayFunction = myPreDisplay,
        .endRowFunction = myEndRow,
        .postDisplayFunction = myPostDisplay

    };

    overrideDisplay(fp);

    wipeGrid(gridForPinwheel);

  }

};

TEST(Oscillator, pinwheel)
{
    setGrid(gridForPinwheel,
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

    tick(gridForPinwheel);
    display(gridForPinwheel);
    
    verifyGrid(gridForPinwheel,
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
        tick(gridForPinwheel);
        display(gridForPinwheel);
    }
}
