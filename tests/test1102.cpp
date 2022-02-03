#include <gtest/gtest.h>

extern "C" {
#include "leetcode.h"
}

TEST(maximumMinimumPath, maximumMinimumPath_1)
{
    int gridSize = 3;
    int gridColSize[gridSize] = {3,3,3};
    int grid[][gridColSize[0]] = {{5,4,5},{1,2,6},{7,4,6}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = maximumMinimumPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 4);
}

TEST(maximumMinimumPath, maximumMinimumPath_2)
{
    int gridSize = 2;
    int gridColSize[gridSize] = {6,6};
    int grid[][gridColSize[0]] = {{2,2,1,2,2,2},{1,2,2,2,1,2}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = maximumMinimumPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 2);
}

TEST(maximumMinimumPath, maximumMinimumPath_3)
{
    int gridSize = 6;
    int gridColSize[gridSize] = {5,5,5,5,5,5};
    int grid[][gridColSize[0]] = {{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = maximumMinimumPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 3);
}
