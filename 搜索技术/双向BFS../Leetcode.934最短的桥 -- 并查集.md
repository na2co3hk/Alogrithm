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

题目大意为连接两个岛的最短距离，由于恰好只有两个岛，并且并不知道岛的位置和覆盖范围，我们先进行一次遍历，用并查集将两个岛屿的范围找出来。然后再分别对两个岛屿进行BFS，我们用两个队列和两个map进行搜索，map用来存储走过的路径，当其中一个岛map中出现了另一个岛的探索的结点，就代表找到了最短距离

python代码：
```py
import queue

class Solution:
    def shortestBridge(self, g: List[List[int]]) -> int:
        def getIdx(x, y):
            return x * n + y

        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(x, y):
            p[find(x)] = p[find(y)]

        def update(d, cur, other):
            sz = d.qsize()
            while sz != 0:
                x, y = d.get()
                idx, step = getIdx(x, y), cur.get(getIdx(x, y))
                for di in dirs:
                    nx, ny = x + di[0], y + di[1]
                    nidx = getIdx(nx, ny)
                    if nx < 0 or nx >= n or ny < 0 or ny >= n:
                        continue
                    if nidx in cur:
                        continue
                    if nidx in other:
                        return step + 1 + other.get(nidx)
                    d.put([nx, ny])
                    cur[nidx] = step + 1
                sz -= 1
            return -1

        n = len(g)
        p = [i for i in range(n * n + 10)]
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        for i in range(n):
            for j in range(n):
                if g[i][j] == 0:
                    continue
                for di in dirs:
                    x, y = i + di[0], j + di[1]
                    if x < 0 or x >= n or y < 0 or y >= n:
                        continue
                    if g[x][y] == 0:
                        continue
                    union(getIdx(i, j), getIdx(x, y))
        a, b = -1, -1
        d1, d2 = queue.Queue(), queue.Queue()
        m1, m2 = {}, {}
        for i in range(n):
            for j in range(n):
                if g[i][j] == 0:
                    continue
                idx, root = getIdx(i, j), find(getIdx(i, j))
                if a == -1:
                    a = root
                elif a != root and b == -1:
                    b = root
                if a == root:
                    d1.put([i, j])
                    m1[idx] = 0
                elif b == root:
                    d2.put([i, j])
                    m2[idx] = 0
        while not d1.empty() and not d2.empty():
            t = -1
            if d1.qsize() < d2.qsize():
                t = update(d1, m1, m2)
            else:
                t = update(d2, m2, m1)
            if t != -1:
                return t - 1
        return -1
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n^2)$ 
