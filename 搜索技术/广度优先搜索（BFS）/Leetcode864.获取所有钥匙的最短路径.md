### 原题链接 -- [[864. 获取所有钥匙的最短路径](https://leetcode.cn/problems/shortest-path-to-get-all-keys/)]

### 题目概述：
Tag : 「广度优先搜索」、「状态压缩」

![image](https://user-images.githubusercontent.com/99656524/200996259-fb612e66-aff7-4456-9c1d-5a4ad6095f06.png)

![image](https://user-images.githubusercontent.com/99656524/200996294-25c18eaf-1f24-4287-8302-e5de9b26721d.png)

![image](https://user-images.githubusercontent.com/99656524/200996318-3f412870-392e-4dc7-8af6-8f2b6c2a7c16.png)

### 数据范围
* $m == grid.length$
* $n == grid[i].length$
* $1 <= m, n <= 30$
* grid[i][j] 只含有 '.', '#', '@', 'a'-'f' 以及 'A'-'F'
* 钥匙的数目范围是 [1, 6] 
* 每个钥匙都对应一个 不同 的字母
* 每个钥匙正好打开一个对应的锁

### 解法一：广度优先搜索 + 状态压缩
这是一道搜索题

由于要找到所有钥匙才算结束，所以并不能确定终点，只能闷头找。由于钥匙的数量只有 1~6 把，我们可以直接用二进制的集合代替set。首先搜索起点和钥匙，统计钥匙的总体数量，然后BFS，用元组记录上个状态的坐标和钥匙统计的状态，钥匙找齐了就是最终答案

python代码：
```py
class Solution:
    def shortestPathAllKeys(self, g: List[str]) -> int:
        dirs = [[0,1], [0,-1], [1,0], [-1,0]]
        n, m, cnt = len(g), len(g[0]), 0
        dist = defaultdict(lambda : 0x3f3f3f3f)
        for i in range(n):
            for j in range(m):
                c = g[i][j]
                if c == '@':
                    d = deque([(i, j, 0)])
                    dist[(i, j, 0)] = 0
                elif 'a' <= c <= 'z':
                    cnt += 1
        while d:
            x, y, cur = d.popleft()
            step = dist[(x, y, cur)]
            for di in dirs:
                nx, ny = x + di[0], y + di[1]
                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    continue
                c = g[nx][ny]
                if c == '#':
                    continue
                if 'A' <= c <= 'Z' and (cur >> (ord(c) - ord('A')) & 1) == 0:
                    continue
                ncur = cur
                if 'a' <= c <= 'z':
                    ncur |= (1 << (ord(c) - ord('a')))
                if ncur == (1 << cnt) - 1:
                    return step + 1
                if step + 1 >= dist[(nx, ny, ncur)]:
                    continue
                dist[(nx, ny, ncur)] = step + 1
                d.append((nx, ny, ncur))
        return -1
```
* 时间复杂度： $O(n * m * 2^k)$
* 空间复杂度： $O(n * m * 2^k)$
