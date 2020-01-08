#ifndef _TEST_SUPPORT_H_
#define _TEST_SUPPORT_H_

extern "C" {
    #include "grid.h"
}

#include <gtest/gtest.h>

void verifyRow(struct Grid grid, int rowIndex, char* expected);
void verifyGrid(struct Grid grid, ...);

class BaseGridTest : public ::testing::Test {

    protected:
        struct Grid grid;
        BaseGridTest(int numRows, int numCols);
};

void rowAsString(char* buffer, struct Grid grid, int rowIndex);


#endif