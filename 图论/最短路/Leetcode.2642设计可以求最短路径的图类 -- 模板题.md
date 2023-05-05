### 原题链接 -- [[2662. 前往目标的最小代价](https://leetcode.cn/problems/design-graph-with-shortest-path-calculator/)]

### 题目概述：
Tag : 「最短路径」、「图」

![image](https://user-images.githubusercontent.com/99656524/236496650-ff3c6a0a-ac50-4ca6-9c73-0196ca0df496.png)

![image](https://user-images.githubusercontent.com/99656524/236496689-e4025225-0634-456b-bd83-74f61310be3f.png)

### 数据范围
* $1 <= n <= 100$
* $0 <= edges.length <= n * (n - 1)$
* $edges[i].length == edge.length == 3$
* $0 <= fromi, toi, from, to, node1, node2 <= n - 1$
* $1 <= edgeCosti, edgeCost <= 10^6$
* $图中任何时候都不会有重边和自环。$
* $调用 addEdge 至多 100 次。$
* $调用 shortestPath 至多 100 次。$

### 解法一：Dijkstra算法
模板题，不多讲了

C++代码：
```cpp
class Graph {
public:
    const int inf = INT_MAX / 2;
    vector<vector<int>>g;
    int n_;
    Graph(int n, vector<vector<int>>& edges) {
        n_ = n;
        g = vector<vector<int>>(n, vector<int>(n, inf));
        for(auto & edge : edges)g[edge[0]][edge[1]] = edge[2];
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(n_, inf);
        vector<int>st(n_);
        dist[node1] = 0;
        while(1)
        {
            int x = -1;
            for(int y = 0; y < n_; y++)
            {
                if(!st[y] and (x == -1 or dist[x] > dist[y]))x = y;
            }
            if(x < 0 or dist[x] == inf)return -1; //能遍历的点都遍历完了
            if(x == node2)return dist[x];
            st[x] = true;
            for(int y = 0; y < n_ ; y++)
            {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
```
* 时间复杂度： $O(qn^2)$ ，其中q为调用求最短路次数
* 空间复杂度： $O(n^2)$

### 解法二：堆优化Dijkstra算法
```cpp
class Graph {
public:
    using PII = pair<int, int>;
    const int inf = INT_MAX / 2;
    vector<vector<PII>>g;
    int n_;
    Graph(int n, vector<vector<int>>& edges) {
        g = vector<vector<PII>>(n);
        n_ = n;
        for(auto &edge : edges) g[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(n_, inf);
        dist[node1] = 0;
        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.emplace(node1, 0);
        while(!pq.empty())
        {
            auto [x, dx] = pq.top();
            pq.pop();
            if(dx > dist[x])continue;
            for(auto [y, w] : g[x])
            {
                int dy = dist[x] + w;
                if(dy < dist[y])
                {
                    dist[y] = dy;
                    pq.emplace(y, dy);
                }
            } 
        }
        return dist[node2] == inf ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
```
* 时间复杂度： $O(qnlogn)$ ，其中q为调用求最短路次数
* 空间复杂度： $O(n + m)$ ，其中m为边的个数
