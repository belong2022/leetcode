
#if 0 // DFS
static int dir[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs(char** grid, int gridSize, int* gridColSize, int x, int y) {
    for (int i= 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx >= 0 && ty >= 0 && tx < gridSize && ty < gridColSize[0] && grid[tx][ty] == '1') {
            grid[tx][ty] = '2';
            dfs(grid, gridSize, gridColSize, tx, ty);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, gridSize, gridColSize, i, j);
                res++;
            }   
        }
    }
    return res;
}
#endif

#if 0 // BFS
typedef struct {
    int x;
    int y;
} Point;

static int dir[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int numIslands(char** grid, int gridSize, int* gridColSize){
    Point queue[gridSize * gridColSize[0] + 1];
    int rear = 0;
    int front = 0;
    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                Point t;
                t.x = i;
                t.y = j;
                queue[rear++] =  t;
                while (front < rear) {
                    Point v = queue[front++];
                    for (int i = 0; i < 4; i++) {
                        int tx = v.x + dir[i][0];
                        int ty = v.y + dir[i][1];
                        if (tx >= 0 && ty >= 0 && tx < gridSize && ty < gridColSize[0] && grid[tx][ty] == '1') {
                            Point tv;
                            tv.x = tx;
                            tv.y = ty;
                            queue[rear++] = tv;
                            grid[tx][ty] = '2';
                        }
                    }
                }
                res++;
            }
        }
    }
    return res;
}
#endif


#if 1 // UF
int find(int prev[], int x)
{
    return x == prev[x] ? prev[x] : find(prev, prev[x]);
}

int join(int prev[], int rank[], int x, int y)
{
    int px = find(prev, x);
    int py = find(prev, y);
    if (px != py) {
        if (rank[px] > rank[py])
            prev[py] = px;
        if (rank[px] < rank[py])
            prev[px] = py;
        if (rank[px] == rank[py]) {
            prev[py] = px;
            rank[px] += 1;
        }
        return 1;
    }
    return 0;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    int rows = gridSize;
    int cols = gridColSize[0];
    int prev[rows * cols];
    int rank[rows * cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int x = i * cols + j;
            if (grid[i][j] == '1') {
                prev[x] = x;
                count++;
            }
            else {
                prev[x] = -1;
            }
            rank[x] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                    count -= join(prev, rank, i * cols + j, (i - 1) * cols + j);
                }
                if (i + 1 < rows && grid[i + 1][j] == '1') {
                    count -= join(prev, rank, i * cols + j, (i + 1) * cols + j);
                }
                if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                    count -= join(prev, rank, i * cols + j, i * cols + (j - 1));
                }
                if (j + 1 < cols && grid[i][j + 1] == '1') {
                    count -= join(prev, rank, i * cols + j, i * cols + (j + 1));
                }
            }
        }
    }

    return count;
}

#endif