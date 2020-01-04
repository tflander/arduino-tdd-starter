#ifndef _CONSOLE_DISPLAY_ADAPTER_H_
#define _CONSOLE_DISPLAY_ADAPTER_H_

#include "abstractDisplayAdapter.hpp"

class ConsoleDisplayAdapter : AbstractDisplayAdapter {

    public:

        void display(struct Grid grid);

    private:

        static void preDisplay();
        static void postDisplay();
        static void displayCell(struct Point point, char mark);
        static void endRow();

};

#endif