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
