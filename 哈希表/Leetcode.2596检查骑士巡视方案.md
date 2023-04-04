### 原题链接 -- [[2596. 检查骑士巡视方案](https://leetcode.cn/problems/check-knight-tour-configuration/)]

### 题目概述：
Tag : 「哈希表」

![image](https://user-images.githubusercontent.com/99656524/229829196-14aacd82-3ba7-45e4-b9c8-ac2ae94a8962.png)

![image](https://user-images.githubusercontent.com/99656524/229829275-db29587b-18b4-492f-8e5a-b9ef16fb24a2.png)

### 数据范围
* n == grid.length == grid[i].length
* 3 <= n <= 7
* 0 <= grid[row][col] < n * n
* grid 中的所有整数 互不相同

### 解法一：哈希表 + 模拟
题目大意为判断骑士的行动是否符合其移动规则。先用哈希表记录骑士走的每一步，再从[0,0]开始模拟骑士走的每一步，审视该下标是否与哈希表记录的步数符合，若出现一个不符合则代表不符合移动规则，返回 $False$ ，否则遍历完哈希表后返回 $True$

python代码：
```py
class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        st = dict()
        for i in range(n):
            for j in range(n):
                st[grid[i][j]] = [i, j]
        if st[0] != [0, 0]:
            return False
        for i in range(1, len(st)):
            c, d = st[i]
            a, b = st[i-1]
            x, y = abs(c-a), abs(d-b)
            if(x == 2 and y == 1 or x == 1 and y == 2):
                continue
            else:
                return False
        return True
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n^2)$
