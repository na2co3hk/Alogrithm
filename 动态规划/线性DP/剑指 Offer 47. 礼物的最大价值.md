### 原题链接 -- [[剑指 Offer 47. 礼物的最大价值](https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/223944881-a5027d10-bcdb-4a1d-9d8f-b55ade9538b7.png)

### 数据范围
0 < grid.length <= 200
0 < grid[0].length <= 200

### 解法一：动态规划
这道题有点类似于数字三角形，也是用动态规划来解决。由于每次只能向右或者向下移动，那么当我们走到最右边或者最下面的时候，就只能从一种方向转移，我们可以先将这些状态先预处理出来，再根据从上边转移和从左边转移两种状态得出状态转移方程。

$$
  f[i][j] = max(f[i-1][j], f[i][j-1]) + grid[i][j]
$$

其中 $f[i][j]$ 表示长和宽分别为i和j时礼物的最大价值。

C++代码：
```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>f(m, vector<int>(n));
        f[0][0] = grid[0][0];
        for(int i = 1;i < m;i++)f[i][0] = f[i-1][0] + grid[i][0];
        for(int j = 1;j < n;j++)f[0][j] = f[0][j-1] + grid[0][j];
        for(int i = 1;i < m;i++)
        {
            for(int j = 1;j < n;j++)
            {
                f[i][j] = max(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        }
        return f[m-1][n-1];
    }
};
```
* 时间复杂度： $O(nm)$ 
* 空间复杂度： $O(n)$

### 优化（原地修改）
直接用原数组充当答案数组即可，代码和上面的代码类似，可以将空间复杂度降低为 $O(1)$   
[代码来源](https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/solution/mian-shi-ti-47-li-wu-de-zui-da-jie-zhi-dong-tai-gu/)

python代码：
```py
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        for j in range(1, n): # 初始化第一行
            grid[0][j] += grid[0][j - 1]
        for i in range(1, m): # 初始化第一列
            grid[i][0] += grid[i - 1][0]
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += max(grid[i][j - 1], grid[i - 1][j])
        return grid[-1][-1]
```
* 时间复杂度： $O(nm)$ 
* 空间复杂度： $O(1)$
