#ifndef _TEST_SUPPORT_H_
#define _TEST_SUPPORT_H_

extern "C" {
    #include "gameOfLifeEngine/grid.h"
}

#include <gtest/gtest.h>

void verifyRow(struct Grid grid, int rowIndex, char* expected);
void verifyGrid(struct Grid grid, ...);

class BaseGridTest : public ::testing::Test {

    protected:

        // const static int numColsForAdapterTests = 5;
        // const static int numRowsForAdapterTests = 4;
        // char gridData[numRowsForAdapterTests][numColsForAdapterTests];
        struct Grid gridForAdapter;

        BaseGridTest() {
            // gridForAdapter = (struct Grid){(char*)gridData, numRowsForAdapterTests, numColsForAdapterTests};
            wipeGrid(gridForAdapter);
        }

        
};

void rowAsString(char* buffer, struct Grid grid, int rowIndex);


#endif