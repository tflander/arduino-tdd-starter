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

class OscillatorTest : public ::testing::Test {

 private:

    const static int numColsForPinwheelTests = 12;
    const static  int numRowsForPinwheelTests = 12;
    char gridData[numRowsForPinwheelTests][numColsForPinwheelTests];

 public:

   struct Grid gridForPinwheel;

    OscillatorTest() {
        gridForPinwheel = (struct Grid){(char*)gridData, numRowsForPinwheelTests, numColsForPinwheelTests};
    }

 protected:

  ConsoleDisplayAdapter displayAdapter;


  void SetUp() override {
    wipeGrid(gridForPinwheel);
  }

};

TEST_F(OscillatorTest, pinwheel)
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
    displayAdapter.display(gridForPinwheel);
    
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
        displayAdapter.display(gridForPinwheel);
    }
}

