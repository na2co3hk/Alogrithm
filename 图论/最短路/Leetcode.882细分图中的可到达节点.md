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
题目大意为，在原本的无相图上加上权重（新的点），问总共能达到多少个点。那么这题为什么要用到最短路算法呢？我们将图细分之后，相当于我们只能向各个点走 $maxMoves$ 步，原题目就抽象成了从0开始走 $maxMoves$ 步的最短路径题。我们可以用Dijkstra算法来解决最短路径类的题目，我们这里用到的是朴素的Dijkstra算法。Dijkstra算法的基本思想是贪心，即每一步都只走最小权重的边，然后将边的终点加入进来，重复上述过程。计算出各个点的最短路之后，我们还需要统计答案，在本题中，若边能到达的权重小于 $maxMoves$ 步，也要加到答案里，我们可以通过计算之前走过的步数（计算出来的最短路）和总共能走的步数（maxMoves）就能得出还需要加的步数（总的减去走过的）。

* 疑点 ：建图的时候为什么要 + 1 ？ 因为细分后的图两条边之间有 edge[2] 个点，再加上要到达细分前的点则需要再 + 1

C++代码：
```cpp
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        const int inf = INT_MAX / 2;
        vector<vector<int>>g(n, vector<int>(n, inf));
        for(auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            g[x][y] = edge[2] + 1;//无相图
            g[y][x] = edge[2] + 1;//两边同时加边
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
```
* 时间复杂度： $O(m + n^2)$，其中n是点的个数, m是边的个数（建图）
* 空间复杂度： $O(n^2)$

### 解法二：堆优化Dijkstra算法
根据上面对Dijkstra算法的理解，我们每次都需要抽出最小权重的边构建最短路，而堆的作用就是维护元素中的最值，我们可以用堆来优化这个抽出最小权重边的过程。本题也可以拿来当模板用（代码来自灵神）

* 疑点：为什么这里就不用vis数组来统计遍历过的点呢？堆优化的迪杰斯特拉算法无需vis数组，因为出堆的时候就已经代表不会再遍历到这个点了，vis数组只是用来优化搜索过程，而下面代码中的 if (d > dist[x]) continue; 保证了不会回去，就代替了vis数组的作用

C++代码：
```cpp
class Solution {
    // Dijkstra 算法模板
    // 返回从 start 到每个点的最短路
    vector<int> dijkstra(vector<vector<pair<int, int>>> &g, int start) {
        vector<int> dist(g.size(), INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto[d, x] = pq.top();
            pq.pop();
            if (d > dist[x]) continue;
            for (auto[y, wt] : g[x]) {
                int new_d = dist[x] + wt;
                if (new_d < dist[y]) {
                    dist[y] = new_d;
                    pq.emplace(new_d, y);
                }
            }
        }
        return dist;
    }

public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1], cnt = e[2];
            g[u].emplace_back(v, cnt + 1);
            g[v].emplace_back(u, cnt + 1); // 建图
        }

        auto dist = dijkstra(g, 0); // 从 0 出发的最短路

        int ans = 0;
        for (int d : dist)
            if (d <= maxMoves) // 这个点可以在 maxMoves 步内到达
                ++ans;
        for (auto &e: edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = max(maxMoves - dist[u], 0);
            int b = max(maxMoves - dist[v], 0);
            ans += min(a + b, cnt); // 这条边上可以到达的节点数
        }
        return ans;
    }
};
```
* 时间复杂度： $O(mlogn)$，其中n是点的个数，m是边的个数
* 空间复杂度： $O(n + m)$
