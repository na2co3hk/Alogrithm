### 原题链接 -- [[130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions/)]

### 题目概述：
Tag : 「并查集」、「广度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/201520626-7bb44651-5a19-477c-a478-56535b1fca5c.png)

![image](https://user-images.githubusercontent.com/99656524/201520629-bf8da5ed-cc98-4118-a73d-6195db3e7575.png)

### 数据范围：
* m == board.length
* n == board[i].length
* 1 <= m, n <= 200
* board[i][j] 为 'X' 或 'O'

### 解法一：并查集
题目大意为将被X围起来的O换成X。我们可以将O的情况分为两种，一种是在边界上的，另一种是被X包围的，将在边界上或与边界上的O连接的点保留下来，因为他们没有被X包围，然后将其余的O换成X即可，我们可以用并查集这种数据结构来判断矩形的连接情况.并查集模板可以看并查集目录下的并查集模板

C++代码：
```cpp
const int N = 200*200+10;

class Solution {
public:
    const int dx[4] = {-1,1,0,0};
    const int dy[4] = {0,0,-1,1};
    int n, m;
    int p[N];
    int find(int x)
    {
        if(x!=p[x])p[x] = find(p[x]);
        return p[x];
    }

    void Union(int a,int b)
    {
        p[find(a)] = p[find(b)];
    }

    int idx(int x,int y)
    {
        return y * m + x;
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        int dummy = n*m;//dummy是一个虚拟节点，所有不需要覆盖的都和它相连，最后在遍历一遍，没有和dummy相连的就置为'X'。
        for(int i = 0;i <= n*m+1;i++)p[i] = i;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(board[i][j] == 'X')continue;
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1)Union(dummy, idx(i, j));
                for(int k = 0; k < 4 ;k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(board[x][y] == 'O')Union(idx(i, j), idx(x, y));
                }
            }
        }

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
               if(find(dummy) != find(idx(i, j)))board[i][j] = 'X';
            }
        }
    }
};
```
* 时间复杂度： $O(nm)$
* 空间复杂度： $O(nm)$ 
