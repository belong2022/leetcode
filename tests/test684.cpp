#include <gtest/gtest.h>

extern "C" {
#include "leetcode.h"
}

TEST(findCircleNum, findRedundantConnection_1) {
    int test[][3] = {{1,2}, {1,3}, {2,3}};
    int edgesColSize[] = {2, 2, 2};
    int edgesSize = 3;
    int *ptest[edgesSize];
    for (int i = 0; i < edgesSize; i++) {
        ptest[i] = test[i];
    }
    int retSize;
    int* res = findRedundantConnection(ptest, edgesSize, edgesColSize, &retSize);
    ASSERT_EQ(res[0], 2);
    ASSERT_EQ(res[1], 3);
}

TEST(findCircleNum, findRedundantConnection_2) {
    int edgesSize = 5;
    int test[][edgesSize] = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    int edgesColSize[] = {2, 2, 2, 2, 2};
    int *ptest[edgesSize];
    for (int i = 0; i < edgesSize; i++) {
        ptest[i] = test[i];
    }
    int retSize;
    int* res = findRedundantConnection(ptest, edgesSize, edgesColSize, &retSize);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 4);
}