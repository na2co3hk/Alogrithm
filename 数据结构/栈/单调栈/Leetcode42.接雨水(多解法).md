### 原题链接 -- [[42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/)]

### 题目概述：
Tag : 「单调栈」、「计算贡献」、「动态规划」、「双指针」

![image](https://user-images.githubusercontent.com/99656524/201313235-017b5231-6254-497e-9406-47bf51ea17e3.png)

### 提示：
* $n == height.length$
* $1 <= n <= 2 * 10^4$
* $0 <= height[i] <= 10^5$

本题解法过多，先针对单调栈这个解法先写一个题解，其他的解法待补充

### 解法一：单调栈
题目大意为能接到多少个雨水。根据题意，我们需要找到所有能接到雨水的“容器”，这个容器必然要两边高中间低，而经过考虑之后不难发现，单调栈就是最适合当这个“容器”的数据结构，我们可以遍历每一个“容器”的底部，也就是枚举每一个值，然后往两边寻找第一个比底部大的数计算贡献即可。需要注意的是，根据“木桶原理”，一个桶最大的装水量取决于最短的那个木板，所以我们必须要对比“容器”的两边谁更小，这样才能计算他最多的装水量，并且还要减去原本底部的高度

* 疑点1：为什么是 < ? ：因为要寻找左右两边第一个比他大的数，所以我们单调栈要将所有小于x的数弹出（必然不符合条件），剩下的就是大于等于（符合条件）的了

* 疑点2：为什么要减去height[cur] ？ 因为“容器”底部本身是有高度的，这部分不能接到雨水，于是要减去

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

### 解法二：双指针
这题我们还可以用双指针的做法，我们用左右两个相向指针同时维护数组的前缀最大值和后缀最大值，来作为“容器”的两边，然后再在两个边之中选最小的作为盛水量。（注意“容器”底部本身也有高度，所以要减去）

C++代码:
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = 0, r = n - 1;
        int pre = 0, suf = 0;
        while(l <= r)
        {
            pre = max(pre, height[l]);
            suf = max(suf ,height[r]);
            ans += pre < suf ? pre - height[l++] : suf - height[r--];
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$
