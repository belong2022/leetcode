#include <gtest/gtest.h>

extern "C" {
#include "leetcode.h"
}

TEST(swimInWater, swimInWater_1)
{
    int gridSize = 2;
    int gridColSize[gridSize] = {2,2};
    int grid[][gridColSize[0]] = {{0,2},{1,3}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = swimInWater(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 3);
}

TEST(swimInWater, swimInWater_2)
{
    int gridSize = 5;
    int gridColSize[gridSize] = {5,5,5,5,5};
    int grid[][gridColSize[0]] = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = swimInWater(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 16);
}

TEST(swimInWater, swimInWater_3)
{
    int gridSize = 4;
    int gridColSize[gridSize] = {4,4,4,4};
    int grid[][gridColSize[0]] = {{11,15,3,2},{6,4,0,13},{5,8,9,10},{1,14,12,7}};
    int *pgrid[gridSize];
    for (int i = 0; i < gridSize; i++) {
        pgrid[i] = grid[i];
    }
    int res = swimInWater(pgrid, gridSize, gridColSize);
    ASSERT_EQ(res, 11);
}
