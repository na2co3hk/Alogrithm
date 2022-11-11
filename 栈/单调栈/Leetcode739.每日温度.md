### 原题链接 -- [[739. 每日温度](https://leetcode.cn/problems/daily-temperatures/)]

### 题目概述：
Tag : 「单调栈」

![image](https://user-images.githubusercontent.com/99656524/201316277-79a2eeb8-9155-424b-b29d-f4095cdf6b39.png)

### 提示
* $1 <= temperatures.length <= 10^5$
* $30 <= temperatures[i] <= 100$

### 解法一：单调栈
本题是单调栈的究极入门题，非常好的一道练手题

题目大意可以简化为寻找下一个比当前温度大的下标，根据单调栈的性质，找出大于当前温度的第一个下标后与当前下标相减即可得出答案

python代码：
```py
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        stk, ans = [], [0]*n
        for i, x in enumerate(temperatures):
            while stk and temperatures[stk[-1]] < x:
                ans[stk[-1]] = i - stk[-1]
                stk.pop()
            stk.append(i)
        return ans
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用栈
