#include <gtest/gtest.h>

extern "C" {
#include "leetcode.h"
}

#if 1 // L547 省份数量
TEST(findCircleNum, findCircleNum_1) {
    int test[][3] = {{1,1,0},{1,1,0},{0,0,1}};
    int isConnectedColSize[] = {3, 3, 3};
    int isConnectedSize = 3;
    int *ptest[3];
    for (int i = 0; i < isConnectedSize; i++) {
        ptest[i] = test[i];
    }
    int res = findCircleNum(ptest, isConnectedSize, isConnectedColSize);
    ASSERT_EQ(res, 2);
}

TEST(findCircleNum, findCircleNum_2) {
    int test[][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int isConnectedColSize[] = {3, 3, 3};
    int isConnectedSize = 3;
    int *ptest[3];
    for (int i = 0; i < isConnectedSize; i++) {
        ptest[i] = test[i];
    }
    int res = findCircleNum(ptest, isConnectedSize, isConnectedColSize);
    ASSERT_EQ(res, 3);
}

TEST(findCircleNum, findCircleNum_3) {
    int test[][3] = {{1,1,1},{1,1,1},{1,1,1}};
    int isConnectedColSize[] = {3, 3, 3};
    int isConnectedSize = 3;
    int *ptest[3];
    for (int i = 0; i < isConnectedSize; i++) {
        ptest[i] = test[i];
    }
    int res = findCircleNum(ptest, isConnectedSize, isConnectedColSize);
    ASSERT_EQ(res, 1);
}

TEST(findCircleNum, findCircleNum_4) {
    int test[][4] = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    int isConnectedColSize[] = {4,4,4,4};
    int isConnectedSize = 4;
    int *ptest[4];
    for (int i = 0; i < isConnectedSize; i++) {
        ptest[i] = test[i];
    }
    int res = findCircleNum(ptest, isConnectedSize, isConnectedColSize);
    ASSERT_EQ(res, 1);
}
#endif