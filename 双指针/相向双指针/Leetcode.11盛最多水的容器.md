### 原题链接 -- [[11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)]

### 题目概述：
Tag : 「双指针」

![image](https://user-images.githubusercontent.com/99656524/202191117-4fed3085-a958-4a7c-8485-57a035ced5bb.png)

![image](https://user-images.githubusercontent.com/99656524/202191242-6a9d329f-e0af-4eb7-94e3-4a3e923c1fd2.png)

### 数据范围
* $n == height.length$
* $2 <= n <= 10^5$
* $0 <= height[i] <= 10^4$

### 解法一：双指针
这题解法和接雨水差不多，这个相当于是弱化版的接雨水。

我们用两个指针来模拟接雨水的“容器”的左右两边，要想接到的雨水多，根据面积公式，就要长和宽都要大，我们可以每次先记录最大面积，优化较小的那条边，然后用双向双指针不断缩小规模。

C++代码：
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, res = 0;
        while(l < r)
        {
            res = height[l] < height[r] ? max(res, (r - l)*height[l++]) : max(res, (r - l)*height[r--]);
        }
        return res;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$ 
