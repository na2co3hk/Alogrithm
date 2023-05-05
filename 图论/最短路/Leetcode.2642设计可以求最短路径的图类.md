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
