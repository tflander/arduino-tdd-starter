#include "render.h"
#include <stdio.h>

void defaultPreDisplay();
void defaultPostDisplay();
void defaultDisplayCell(struct Point point, char mark);
void defaultEndRow();

void display(struct Grid grid, struct displayFunctionPointers fp) {
    int c, r; 
    (*fp.preDisplayFunction)();
    for (r = 0; r < grid.numRows; r++) {
        for (c = 0; c < grid.numCols; c++) {
            struct Point point = {.x=c, .y=r};
            char mark = getCell(grid, point);
            (*fp.displayCellFunction)(point, mark);
        }
        (*fp.endRowFunction)();
    }
    (*fp.postDisplayFunction)();
}

// TODO: move to test support
void rowAsString(char* buffer, struct Grid grid, int rowIndex) {
    buffer[grid.numCols + 1] = 0;
    for (int c = 0; c < grid.numCols; ++c) {
        if(isAlive(grid, (struct Point){c, rowIndex})) {
            buffer[c] = 'X';
        } else {
            buffer[c] = '.';
        }
    }
}
