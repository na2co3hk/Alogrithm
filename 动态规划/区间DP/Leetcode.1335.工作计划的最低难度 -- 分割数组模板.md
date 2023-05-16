### 原题链接 -- [[1335. 工作计划的最低难度](https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule/)]

### 题目概述：
Tag : 「动态规划」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/2899917b-b3bf-4791-8424-5ca880ef3326)

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/ed3d90e5-a8a4-4418-941e-0beb2a0b08c0)

### 数据范围
* 1 <= jobDifficulty.length <= 300
* 0 <= jobDifficulty[i] <= 1000
* 1 <= d <= 10

### 解法一：动态规划
题目大意为将数组分为d份，每份取最大值相加的最小值。这是一道分割数组的题目，而分割数组最常见的就是用动态规划来结决，状态定义f[i][j]表示为考虑前i个数组元素，分割成j份时的最小难度

C++代码
```cpp
class Solution {
public:
    const int inf = INT_MAX / 2;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>>f(n + 1, vector<int>(d + 1, inf));
        f[0][0] = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1; j <= min(i, d);j++)
            {
                int mx = 0;
                for(int k = i;k;k--)
                {
                    mx = max(mx, jobDifficulty[k-1]);
                    f[i][j] = min(f[i][j], f[k-1][j-1] + mx);
                }
            }
        }
        return f[n][d] == inf ? -1 : f[n][d];
    }
};
```
* 时间复杂度： $O(n^2d)$
* 空间复杂度： $O(nd)$
