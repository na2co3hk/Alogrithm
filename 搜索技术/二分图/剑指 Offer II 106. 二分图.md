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

题目大意为将一个无相图分为两个独立的集合
