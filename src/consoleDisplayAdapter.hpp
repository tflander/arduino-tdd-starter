extern "C" {
    #include "grid.h"
}

class ConsoleDisplayAdapter {
    public:

        void display(struct Grid grid);

    private:

        static void preDisplay();
        static void postDisplay();
        static void displayCell(struct Point point, char mark);
        static void endRow();

};
