#include "leetcode.h"

#include <stdlib.h>

/*
如果两个顶点属于不同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间不连通，因此当前的边不会导致环出现，合并这两个顶点的连通分量。
如果两个顶点属于相同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间已经连通，因此当前的边导致环出现，为附加的边，将当前的边作为答案返回。
*/

int UfFind(int* t, int v)
{
    return (v == t[v]) ? t[v] : UfFind(t, t[v]);
}

void UfUinon(int* t, int v, int w)
{
    t[UfFind(t, t[v])] = UfFind(t, t[w]);
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int parent[edgesSize + 1];
    for (int i = 1; i < edgesSize + 1; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < edgesSize; i++) {
        if (UfFind(parent, edges[i][0]) != UfFind(parent, edges[i][1])) {
            UfUinon(parent, edges[i][0], edges[i][1]);
        } else {
            (*returnSize) = 2;
            return edges[i];
        }
    }
    return NULL;
}