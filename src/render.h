#ifndef _RENDER_H_
#define _RENDER_H_

#include "gameOfLifeEngine/grid.h"

typedef void (voidFn)(void);
typedef void (displayCellFn)(struct Point point, char mark);

struct displayFunctionPointers {

    voidFn* preDisplayFunction; 
    voidFn* endRowFunction; 
    voidFn* postDisplayFunction; 
    displayCellFn* displayCellFunction;
};

void display(struct Grid grid, struct displayFunctionPointers displayFunctionPointers);

#endif