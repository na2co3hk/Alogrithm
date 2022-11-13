### 原题链接 -- [[剑指 Offer II 106. 二分图](https://leetcode.cn/problems/vEAB3K/)]

### 题目概述：
Tag : 「二分图」、「深度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/197371400-2cd9c27a-1316-4970-be05-950179a26e7e.png)

![image](https://user-images.githubusercontent.com/99656524/197371406-a596b1db-a4e9-4821-a9a8-783c73fc3d2d.png)

![image](https://user-images.githubusercontent.com/99656524/197371410-52048674-4c84-41b1-acdd-efe710ad08ad.png)

### 数据范围
* $graph.length == n$
* $1 <= n <= 100$
* $0 <= graph[u].length < n$
* $0 <= graph[u][i] <= n - 1$
* $graph[u] 不会包含 u$
* $graph[u] 的所有值 互不相同$
* $如果 graph[u] 包含 v，那么 graph[v] 也会包含 u$

### 解法一：染色法
本题是二分图染色法的入门题，可以作为一个模板

题目大意为将一个无相图分为两个独立的集合，并且两个集合中不能有交集，我们可以用染色法来对无相图染色，首先将一个点染色，并将无法相容的点染成对立的颜色，若染色过程中一个点出现两种颜色，则代表有交集，就无法完成二分图，反之则可以完成二分图

C++代码：
```cpp
class Solution {
public:
    int n;
    vector<int> color;    // 记录每个点染的颜色，共两种颜色，0和1
    vector<vector<int>> g;
    // 染色
    bool dfs(int u, int c)
    {
        color[u] = c;
        for (auto v: g[u])
        {
            if (color[v] == -1 && !dfs(v, 1 - c))return false;  // 将相邻的点染成不同的颜色
            if (color[v] == c)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        color.resize(n, -1);
        for (int i = 0; i < n; i ++ )
        {
            if (color[i] != -1)continue;
            if (!dfs(i, 0))return false;
        }
        return true;
    }
};
```
* 时间复杂度： $O(n + m)$，n和m分别为无相图点和边的数量
* 空间复杂度： $O(n)$，递归调用栈的空间 

