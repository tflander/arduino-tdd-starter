#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <gtest/gtest.h>
#include <string.h>
#include <time.h>

extern "C" {
    #include "render.h"
    #include "gameOfLife.h"
    #include "rules.h"
    #include "render.h"
    #include "neighbor_counter.h"
}
#include "support.hpp"

class GridTest : public BaseGridTest {

    protected:

        const static int numRows = 3;
        const static int numCols = 4;
        GridTest() : BaseGridTest(numRows, numCols) {}
};

TEST_F(GridTest, create_empty_grid) {

    for(int r = 0; r < grid.numRows; ++r) {
        for(int c = 0; c < grid.numCols; ++c) {
           ASSERT_EQ(' ', getCell(grid, (struct Point){.x=c, .y=r}));
       }
    }
}

TEST_F(GridTest, randomize_grid) {
    randomizeGrid(grid, time(0));
    int numMarks = 0;
    for(int r = 0; r < grid.numRows; ++r) {
        for(int c = 0; c < grid.numCols; ++c) {
            if ('X' == getCell(grid, (struct Point){.x=c, .y=r})) {
                ++numMarks;
            }
       }
    }
    int numCells = grid.numCols * grid.numRows;
    ASSERT_TRUE(numMarks > 0 && numMarks < numCells);
}

TEST_F(GridTest, set_grid_cell) {
    setLivingCell(grid, (struct Point){.x=1, .y=2});  // good
    ASSERT_EQ('X', getCell(grid, (struct Point){.x=1, .y=2}));
}

TEST_F(GridTest, middle_cell_has_one_living_neighbor) {
    setLivingCell(grid, (struct Point){.x=0, .y=0});
    ASSERT_EQ(1, count_neighbors(grid, (struct Point){.x=1, .y=1}));
}

TEST_F(GridTest, top_left_cell_has_one_living_neighbor) {
    setLivingCell(grid, (struct Point){.x=0, .y=1});
    ASSERT_EQ(1, count_neighbors(grid, (struct Point){.x=0, .y=0}));
}

TEST_F(GridTest, bottom_right_cell_has_one_living_neighbor) {
    setLivingCell(grid, (struct Point){.x=3, .y=1});
    ASSERT_EQ(1, count_neighbors(grid, (struct Point){.x=3, .y=2}));
}

TEST_F(GridTest, live_cell_with_fewer_than_two_neighbors_dies)
{
    setLivingCell(grid, (struct Point){.x=0, .y=0});
    tick(grid);
    ASSERT_FALSE(isAlive(grid, (struct Point){0, 0}));
}

TEST_F(GridTest, live_cell_with_two_or_three_neighbors_survives)
{
    setGrid(grid,
        "XX  ",
        "X   ",
        "    "
    );
    tick(grid);
    ASSERT_TRUE(isAlive(grid, (struct Point){0, 0}));
}

TEST_F(GridTest, live_cell_with_more_than_three_neighbors_dies)
{
    setGrid(grid,
        "XXX.",
        "XXX.",
        "...."
    );

    tick(grid);
    verifyGrid(grid,
        "X.X.",
        "X.X.",
        ".X.."
    );
    ASSERT_FALSE(isAlive(grid, (struct Point){.x=1, .y=0}));
}

TEST_F(GridTest, dead_cell_with_three_neighbors_becomes_live)
{
   setGrid(grid,
        "X   ",
        "XX  ",
        "    "
    );
    tick(grid);
    ASSERT_TRUE(isAlive(grid, (struct Point){1, 0}));

}

TEST_F(GridTest, dead_cell_with_two_neighbors_stays_dead)
{
    setGrid(grid,
        "XX  ",
        "    ",
        "    "
    );
    tick(grid);
    ASSERT_FALSE(isAlive(grid, (struct Point){1, 0}));
}
