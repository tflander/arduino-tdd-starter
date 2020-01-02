#include "support.hpp"

extern "C" {
    #include "render.h"
}

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <gtest/gtest.h>

void verifyRow(struct Grid grid, int rowIndex, char* expected) {
    char actual[grid.numCols + 1];
    rowAsString(actual, grid, rowIndex);
    if(0 != strcmp(expected, actual)) {
        char msg[255];
        sprintf(msg, "Error in row %d.  Expected %s, found %s", rowIndex, expected, actual);
        ASSERT_TRUE(false) << msg;
    }
}

void verifyGrid(struct Grid grid, ...) {
    va_list ap; 
    va_start(ap, grid); 
  
    for (int r = 0; r < grid.numRows; ++r) {
        char* row = va_arg(ap, char*); 
        verifyRow(grid, r, row);
    }
  
    va_end(ap); 
}
