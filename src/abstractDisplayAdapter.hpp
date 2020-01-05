#ifndef _ABSTRACT_DISPLAY_ADAPTER_H_
#define _ABSTRACT_DISPLAY_ADAPTER_H_

extern "C" {
    #include "gameOfLifeEngine/grid.h"
}

class AbstractDisplayAdapter {
    virtual void display(struct Grid grid) = 0;
};

#endif