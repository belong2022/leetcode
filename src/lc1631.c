
#if 0 // BFS 二分
#include <math.h>
#include <string.h>
#include <stdlib.h>

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize) {
    int m = heightsSize;
    int n = heightsColSize[0];
    int left = 0;
    int right = 999999;
    int ans = 0;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        int q[n * m][2];
        int qleft = 0;
        int qright = 0;
        q[qright][0] = 0;
        q[qright++][1] = 0;
        int seen[m * n];
        memset(seen, 0, sizeof(seen));
        seen[0] = 1;
        while (qleft < qright) {
            int x = q[qleft][0];
            int y = q[qleft++][1];
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid) {
                    q[qright][0] = nx;
                    q[qright++][1] = ny;
                    seen[nx * n + ny] = 1;
                }
            }
        }
        if (seen[m * n - 1]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
#endif

#if 0 // 并查集
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int *parent;
    int *rank;
} DSU;

typedef struct {
    int ps; // point start
    int pe; // point end
    int dh; // delta height
} EDGE;

void UfInit(DSU* obj, int n) {
    obj->parent = malloc(sizeof(int) * n);
    obj->rank = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        obj->parent[i] = i;
        obj->rank[i] = 1;
    }
}

int UfFind(DSU* obj, int v) {
    return obj->parent[v] == v ? v : UfFind(obj, obj->parent[v]);
}

void UfUnion(DSU* obj, int v, int w) {
    int tv = UfFind(obj, v);
    int tw = UfFind(obj, w);
    if (tv != tw) {
        if (obj->rank[tv] < obj->rank[tw]) {
            int tt = tv;
            tv = tw;
            tw = tt;
        }
        obj->rank[tv] += obj->rank[tw];
        obj->parent[tw] = tv;
    }
}

int UfConnect(DSU* obj, int x, int y) {
    return UfFind(obj, x) == UfFind(obj, y);
}

int cmp(const void* a, const void* b) {
    EDGE *ta = (EDGE*)a;
    EDGE *tb = (EDGE*)b;
    return ta->dh - tb->dh;
}

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize) {
    int m = heightsSize;
    int n = heightsColSize[0];
    EDGE edges[n * m * 2]; // 一个点对应两条边
    int edgesSize = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ( i + 1 < m) {
                edges[edgesSize].ps = i * n + j;
                edges[edgesSize].pe = (i + 1) * n + j;
                edges[edgesSize].dh = fabs(heights[i][j] - heights[i+1][j]);
                edgesSize++;
            }
            if (j + 1 < n) {
                edges[edgesSize].ps = i * n + j;
                edges[edgesSize].pe = i * n + j + 1;
                edges[edgesSize].dh = fabs(heights[i][j] - heights[i][j+1]);
                edgesSize++;
            }
        }
    }
    qsort(edges, edgesSize, sizeof(EDGE), cmp);
    DSU* uf = malloc(sizeof(DSU));
    UfInit(uf, m * n * 2);
    int ans = 0;
    for (int i = 0; i < edgesSize; i++) {
        UfUnion(uf, edges[i].ps, edges[i].pe);
        if (UfConnect(uf, 0, m * n - 1)) {
            ans = edges[i].dh;
            break;
        }
    }
    return ans;
}
#endif

#if 0 // Dijkstra
int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize) {

}
#endif

#if 1 // 二分 + DFS
#include <stdbool.h>
#include <math.h>
#include <string.h>

int diff[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool dfs(int **heights, int x, int y, int m, int n, int k, int* visit) {
    if (x == m-1 && y == n-1) {
        return true;
    }
    if (visit[x * n + y]) {
        return false;
    }
    visit[x * n + y] = true;
    for (int i=0; i<4; ++i) {
        int x1 = x + diff[i][0];
        int y1 = y + diff[i][1];
        if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && fabs(heights[x][y] - heights[x1][y1]) <= k) {
            if (dfs(heights, x1, y1, m, n, k, visit)) {
                return true;
            }
        }
    }
    return false;
}

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize){
    int m = heightsSize;
    int n = heightsColSize[0];
    int lo = 0;
    int hi = 1000000;
    int visit[m * n];
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        memset(visit, 0, sizeof(visit));
        if (dfs(heights, 0, 0, m, n, mid, visit)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
#endif
