#include <gtest/gtest.h>

extern "C" {
    #include "render.h"
}
#include "consoleDisplayAdapter.hpp"
#include "support.hpp"

class ConsoleDisplayAdapterTest : public BaseGridTest {

    protected:

        const static int numRows = 3;
        const static int numCols = 4;
        ConsoleDisplayAdapterTest() : BaseGridTest(numRows, numCols) {}
};

TEST_F(ConsoleDisplayAdapterTest, display)
{
    ConsoleDisplayAdapter displayAdapter;
    displayAdapter.display(grid);
}
