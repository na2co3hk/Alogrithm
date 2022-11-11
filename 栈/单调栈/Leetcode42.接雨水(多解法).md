### 原题链接 -- [[42. 接雨水](https://leetcode.cn/problems/largest-rectangle-in-histogram/)]

### 题目概述：
Tag : 「单调栈」、「计算贡献」、「动态规划」、「双指针」

![image](https://user-images.githubusercontent.com/99656524/201313235-017b5231-6254-497e-9406-47bf51ea17e3.png)

### 提示：
* $n == height.length$
* $1 <= n <= 2 * 10^4$
* $0 <= height[i] <= 10^5$

本题解法过多，先针对单调栈这个解法先写一个题解，其他的解法待补充

### 解法一：单调栈
题目大意为能接到多少个雨水。根据题意，我们需要找到所有能接到雨水的“容器”，这个容器必然要两边高中间低，而经过考虑之后不难发现，单调栈就是最适合当这个“容器”的数据结构，我们可以遍历每一个“容器”的底部，也就是枚举每一个值，然后往两边寻找第一个比底部大的数计算贡献即可。需要注意的是，根据“木桶原理”，一个桶最大的装水量取决于最短的那个木板，，所以我们必须要对比“容器”的两边谁更小，这样才能计算他最多的装水量，并且还要减去原本底部的高度

python代码：
```py
class Solution:
    def trap(self, height: List[int]) -> int:
        n, ans = len(height), 0
        stk = []
        for r, x in enumerate(height):
            while stk and height[stk[-1]] < x: #疑点1
                cur = stk.pop()
                if stk : l = stk[-1]
                else : break
                wid = r - l - 1
                hei = min(height[l], height[r]) - height[cur] #疑点2
                ans += wid*hei
            stk.append(r)
        return ans

```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用栈
