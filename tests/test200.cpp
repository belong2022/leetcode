#include <gtest/gtest.h>

extern "C" {
#include "leetcode.h"
}

TEST(numIslands, numIslands_1) {
    int gridSize = 4;
    int gridColSize[gridSize] = {5,5,5,5};
    char test[][gridColSize[0]] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    char* ptest[gridSize];
    for (int i = 0; i < gridSize; i++) {
        ptest[i] = test[i];
    }
    int res = numIslands(ptest, gridSize, gridColSize);
    ASSERT_EQ(res, 1);
}

TEST(numIslands, numIslands_2) {
    int gridSize = 4;
    int gridColSize[gridSize] = {5,5,5,5};
    char test[][gridColSize[0]] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    char* ptest[gridSize];
    for (int i = 0; i < gridSize; i++) {
        ptest[i] = test[i];
    }
    int res = numIslands(ptest, gridSize, gridColSize);
    ASSERT_EQ(res, 3);
}

TEST(numIslands, numIslands_3) {
    int gridSize = 1;
    int gridColSize[gridSize] = {2};
    char test[][gridColSize[0]] = {{'1','1'}};
    char* ptest[gridSize];
    for (int i = 0; i < gridSize; i++) {
        ptest[i] = test[i];
    }
    int res = numIslands(ptest, gridSize, gridColSize);
    ASSERT_EQ(res, 1);
}
