
#ifndef LEETCODE__H
#define LEETCODE__H

#include <stdbool.h>

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize); // L547 省份数量
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize); // L684 冗余连接
int numIslands(char** grid, int gridSize, int* gridColSize); // L200 岛屿数量
int maximumMinimumPath(int** grid, int gridSize, int* gridColSzie); // L1102 得分最高的路径
#endif