#include "consoleDisplayAdapter.hpp"

extern "C" {
    #include "render.h"
    #include <stdio.h>
}

void ConsoleDisplayAdapter::display(struct Grid grid) {

      struct displayFunctionPointers fp = {
        .displayCellFunction = displayCell,
        .preDisplayFunction = preDisplay,
        .endRowFunction = endRow,
        .postDisplayFunction = postDisplay

    };

    ::display(grid, fp);
}

void ConsoleDisplayAdapter::preDisplay() {
    printf("\nGame Of Life\n");
}

void ConsoleDisplayAdapter::postDisplay() {
    printf("^^^^^^^^^^^^^^\n");
}

void ConsoleDisplayAdapter::displayCell(struct Point point, char mark) {
    if (mark == ' ') {
        mark = '.';
    }
    printf("%c ", mark); 
}

void ConsoleDisplayAdapter::endRow() {
    printf("|\n");
}
