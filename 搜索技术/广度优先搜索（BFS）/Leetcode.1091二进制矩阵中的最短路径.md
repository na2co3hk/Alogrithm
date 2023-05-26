### 原题链接 -- [[1091. 二进制矩阵中的最短路径](https://leetcode.cn/problems/shortest-path-in-binary-matrix/)]

### 题目概述：
Tag : 「广度优先搜索」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/f9db33a4-988d-4b16-a5b3-dd595ff5f75b)

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/389ec614-4c91-4131-bea4-9456fb779b58)

### 数据范围
* n == grid.length
* n == grid[i].length
* 1 <= n <= 100
* grid[i][j] 为 0 或 1

### 解法一：广度优先搜索
先说明，本题无法用深度优先搜索来做，本题属于是在网格图中寻找到右下角的最短路径，而对于网格图最短路径，就需要想到用BFS。题目很简单，但是总结很重要，下面是对于什么时候用BFS，什么时候用DFS的理解。（偷的）

#### 什么时候用BFS？ 
当需要找到网格图中的最短路径时，就可以用BFS。因为DFS必须等所有可能的情况都试过之后才能确定最短路径，而BFS是一层一层搜索的，只要遇到解，那就是最优解。

#### 什么时候用DFS？
当需要找到网格图中某结果是否存在的时候，就可以用DFS。因为DFS会先把每一种可能都尝试，如果符合条件就可以直接返回，而BFS一层一层搜索，从而尝试了很多不必要的路径。

代码偷的灵神的双数组写法

C++代码：
```cpp
class Solution {
public:
    const int dx[8] = {1, 1, 0, 0, 1, -1, -1, -1};
    const int dy[8] = {1, 0, 1, -1, -1, 1, 0, -1};
    const int inf = INT_MAX / 2;
    using PII = pair<int, int>;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dis(n, vector<int>(n, inf));
        if(grid[n-1][n-1] == 1)return -1;
        if(n == 1)return 1;
        vector<PII>q = {make_pair(0, 0)};
        for(int step = 1; !q.empty(); step++)
        {
            vector<PII>nq;
            for(auto [x, y] : q)
            {
                for(int i = 0;i < 8;i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 and nx < n and ny >= 0 and ny < m and dis[nx][ny] == inf and grid[x][y] == 0)
                    {
                        dis[nx][ny] = step + 1;
                        nq.push_back({nx, ny});
                    }    
                }
            }
            q = move(nq);
        }
        return dis[n - 1][n - 1] ==  inf ? -1 : dis[n - 1][n - 1];
    }
};
```
