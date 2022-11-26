### 原题链接 -- [[882. 细分图中的可到达节点](https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/)]

### 题目概述：
Tag : 「最短路径」、「图」

![image](https://user-images.githubusercontent.com/99656524/204070674-87717f1b-63da-4c09-b0db-8edd62b4b9bf.png)

![image](https://user-images.githubusercontent.com/99656524/204070683-b5a672a2-dca1-4aec-bc1e-7ae9c4bcb020.png)

### 数据范围
* $0 <= edges.length <= min(n * (n - 1) / 2, 10^4)$
* $edges[i].length == 3$
* $0 <= ui < vi < n$
* $图中 不存在平行边$
* $0 <= cnti <= 10^4$
* $0 <= maxMoves <= 10^9$
* $1 <= n <= 3000$

### 解法一：朴素Dijkstra算法
题目大意为，在原本的无相图上加上权重（新的点），问总共能达到多少个点。那么这题为什么要用到最短路算法呢？我们将图细分之后，相当于我们只能向各个点走 $maxMoves$ 步，原题目就抽象成了从0开始走 $maxMoves$ 步的最短路径题。我们可以用Dijkstra算法来解决最短路径类的题目，我们这里用到的是朴素的Dijkstra算法。Dijkstra算法的基本思想是贪心，即每一步都只走最小权重的边，然后将边的终点加入进来，重复上述过程。计算出各个点的最短路之后，我们还需要统计答案，在本题中，若边能到达的权重小于 $maxMoves$ 步，也要加到答案里。

C++代码：
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        const int inf = INT_MAX / 2;
        vector<vector<int>>g(n, vector<int>(n, inf));
        for(auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            g[x][y] = edge[2] + 1;
            g[y][x] = edge[2] + 1;
        }
        vector<int>dis(n, inf);
        vector<bool>vis(n, false);
        dis[0] = 0;
        for(int i = 0;i < n;i++)
        {
            int x = -1;
            for(int y = 0;y < n;y++)
            {
                if(!vis[y] && (x == -1 || dis[y] < dis[x]))x = y;
            }

            vis[x] = true;
            for(int y = 0;y < n;y++)
            {
                dis[y] = min(dis[y], dis[x] + g[x][y]);
            }
        }

        //统计答案
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            if(dis[i] <= maxMoves)ans++;
        }
        for(auto edge:edges)
        {
            int x = edge[0];
            int y = edge[1];
            int c = edge[2];
            int c1 = max(0, maxMoves - dis[x]), c2 = max(0, maxMoves - dis[y]);
            ans += min(c, c1 + c2);
        }
        return ans;
    }
};
* 时间复杂度： $O(n^2)$，其中n是点的个数
* 空间复杂度： $O(n^2)$
