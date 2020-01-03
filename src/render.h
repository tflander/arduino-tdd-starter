#ifndef _RENDER_H_
#define _RENDER_H_

#include "grid.h"

struct displayFunctionPointers {
    void (*preDisplayFunction)(void); 
    void (*endRowFunction)(void); 
    void (*postDisplayFunction)(void); 
    void (*displayCellFunction)(struct Point point, char mark);
};

void display(struct Grid grid, struct displayFunctionPointers displayFunctionPointers);

#endif