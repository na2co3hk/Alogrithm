### 原题链接 -- [[934. 最短的桥](https://leetcode.cn/problems/shortest-bridge/)]

### 题目概述：
Tag : 「广度优先搜索」、「并查集」

![image](https://user-images.githubusercontent.com/99656524/197792056-bfa49218-feb6-4353-817e-ace7e33efecb.png)

### 数据范围
* n == grid.length == grid[i].length
* 2 <= n <= 100
* grid[i][j] 为 0 或 1
* grid 中恰有两个岛

### 解法一：双向BFS + 并查集
题解和思路来自[宫水三叶](https://leetcode.cn/problems/shortest-bridge/solution/by-ac_oier-56ly/)，以下是我对算法的思路总结

