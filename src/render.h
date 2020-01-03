#ifndef _RENDER_H_
#define _RENDER_H_

#include "grid.h"

void rowAsString(char* buffer, struct Grid grid, int rowIndex);

struct displayFunctionPointers {
    void (*preDisplayFunction)(void); 
    void (*endRowFunction)(void); 
    void (*postDisplayFunction)(void); 
    void (*displayCellFunction)(struct Point point, char mark);
};

void display(struct Grid grid, struct displayFunctionPointers displayFunctionPointers);
// void overrideDisplay(struct displayFunctionPointers fp);

#endif