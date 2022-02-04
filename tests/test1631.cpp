#include <gtest/gtest.h>

extern "C" {
#include "leetcode.h"
}

TEST(minimumEffortPath, minimumEffortPath_1)
{
    int gridSize = 3;
    int gridColSize[gridSize] = {3,3,3};
    int grid[][gridColSize[0]] = {{1,2,2},{3,8,2},{5,3,5}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = minimumEffortPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 2);
}

TEST(minimumEffortPath, minimumEffortPath_2)
{
    int gridSize = 3;
    int gridColSize[gridSize] = {3,3,3};
    int grid[][gridColSize[0]] = {{1,2,3},{3,8,4},{5,3,5}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = minimumEffortPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 1);
}

TEST(minimumEffortPath, minimumEffortPath_3)
{
    int gridSize = 5;
    int gridColSize[gridSize] = {5,5,5,5,5};
    int grid[][gridColSize[0]] = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = minimumEffortPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 0);
}

TEST(minimumEffortPath, minimumEffortPath_4)
{
    int gridSize = 1;
    int gridColSize[gridSize] = {8};
    int grid[][gridColSize[0]] = {{1,10,6,7,9,10,4,9}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = minimumEffortPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 9);
}

TEST(minimumEffortPath, minimumEffortPath_5)
{
    int gridSize = 7;
    int gridColSize[gridSize] = {2, 2, 2, 2, 2, 2,2};
    int grid[][gridColSize[0]] = {{10,8},{10,8},{1,2},{10,3},{1,3},{6,3},{5,2}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = minimumEffortPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 6);
}

TEST(minimumEffortPath, minimumEffortPath_6)
{
    int gridSize = 3;
    int gridColSize[gridSize] = {8,8,8};
    int grid[][gridColSize[0]] = {{2,3,6,3,6,6,1,2},{4,5,6,5,5,10,1,2},{9,1,4,10,4,7,7,3}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = minimumEffortPath(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 4);
}

