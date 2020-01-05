#include <gtest/gtest.h>

extern "C" {
    #include "gameOfLifeEngine/rules.h"
}


bool currentlyAlive = true;
bool currentlyDead = false;

TEST(Rules, live_cell_with_fewer_than_two_neighbors_dies)
{
    ASSERT_FALSE(cell_alive(currentlyAlive, 1));
    ASSERT_FALSE(cell_alive(currentlyAlive, 0));
}

TEST(Rules, live_cell_with_two_or_three_neighbors_survives)
{
    ASSERT_TRUE(cell_alive(currentlyAlive, 2));
    ASSERT_TRUE(cell_alive(currentlyAlive, 3));
}

TEST(Rules, live_cell_with_more_than_three_neighbors_dies)
{
    ASSERT_FALSE(cell_alive(currentlyAlive, 4));
    ASSERT_FALSE(cell_alive(currentlyAlive, 5));
}

TEST(Rules, dead_cell_with_three_neighbors_becomes_live)
{
    ASSERT_TRUE(cell_alive(currentlyDead, 3));
}

TEST(Rules, dead_cell_with_two_neighbors_stays_dead)
{
    ASSERT_FALSE(cell_alive(currentlyDead, 2));
}
