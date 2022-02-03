#include "leetcode.h"
#include <stdlib.h>
#include <string.h>

#if 0 // L547 省份数量 UF
int UfFind(int *t, int v)
{
    return (v == t[v]) ? t[v] : UfFind(t, t[v]);
}

void UfUion(int *t, int v, int w)
{
    t[UfFind(t, t[v])] = UfFind(t, t[w]);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if (NULL == isConnected || NULL == isConnectedColSize || isConnectedSize < 1) {
        return 0;
    }

    int city[isConnectedSize];

    for (int i = 0; i < isConnectedSize; i++) {
        city[i] = i;
    }
    for (int i = 0; i < isConnectedSize; i++) {
        for (int j = 0; j < isConnectedColSize[i]; j++) {
            if (i == j) {
                continue;
            }
            if (isConnected[i][j]) {
                UfUion(city, i, j);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (city[i] == i) {
            res++;
        }
    }
    return  res;
}
#endif

#if 0 // L547 省份数量 DFS
void dfs(int** isConnected, int isConnectedSize, int *visited, int index)
{
    for (int j = 0; j < isConnectedSize; j++) {
        if (isConnected[index][j] == 1 && visited[j] == 0) {
            visited[j] = 1;
            dfs(isConnected, isConnectedSize, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if (NULL == isConnected || NULL == isConnectedColSize || isConnectedSize < 1) {
        return 0;
    }

    int visited[isConnectedSize];
    int res = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < isConnectedSize; i++) {
        if (visited[i] == 0) {
            dfs(isConnected, isConnectedSize, visited, i);
            res++;
        }
    }
    return res;
}

// wrong answer!!!.
// int const dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// void dfs(int** grid, int gridSize, int* gridColSize, int x, int y)
// {
//     grid[x][y] = 2;
//     for (int i = 0; i < 4; i++) {
//         int tx = x + dir[i][0];
//         int ty = y + dir[i][1];
//         if (tx >= 0 && tx < gridSize && ty >= 0 && ty < gridColSize[tx] && grid[tx][ty] == 1) {
//             dfs(grid, gridSize, gridColSize, tx, ty);
//         }
//     }
//     return;
// }
// int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
//     if (NULL == isConnected || NULL == isConnectedColSize || isConnectedSize < 1) {
//         return 0;
//     }
//     int res = 0;
//     for (int i = 0; i < isConnectedSize; i++) {
//         for (int j = 0; j < isConnectedColSize[i]; j++) {
//             if (isConnected[i][j] == 1) {
//                 dfs(isConnected, isConnectedSize, isConnectedColSize, i, j);
//                 res++;
//             }
//         }
//     }
//     return res;
// }

#endif

#if 1 // L547 省份数量 BFS
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if (NULL == isConnected || NULL == isConnectedColSize || isConnectedSize < 1) {
        return 0;
    }
    int visited[isConnectedSize];
    memset(visited, 0, sizeof(visited));
    int res = 0;
    int queue[isConnectedSize];
    int rear = 0;
    int front = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (visited[i] == 0) {
            queue[rear++] = i;
            while (front < rear) {
                int t = queue[front++];
                visited[t] = 1;
                for (int j = 0; j < isConnectedSize; j++) {
                    if (isConnected[t][j] == 1 && visited[j] == 0) {
                        queue[rear++] = j;
                    }
                }
            }
            res++;
        }
    }
    return res;
}
#endif
