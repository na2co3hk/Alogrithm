### 原题链接 -- [[84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/)]

### 题目概述：
Tag : 「单调栈」、「计算贡献」

![image](https://user-images.githubusercontent.com/99656524/201008840-5da54a6a-adbc-40ab-9488-58dfcdabeaba.png)

![image](https://user-images.githubusercontent.com/99656524/201008862-aa825f6f-c9cf-4bd4-aab9-db667865c939.png)

### 数据范围
* 1 <= heights.length <=10^5
* 0 <= heights[i] <= 10^4

### 解法一：单调栈
题目大意为找柱状图中的最大矩形面积，由于必须是连续区间，且要找最大值，就首先要想到单调栈了。我们枚举每一个横坐标，当横坐标为部分区间最小值的时候做出的贡献，接下来只要找以横坐标为最小值的左右边界就可以了

python代码：（两次遍历）
```py
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        left, right = [0]*n, [n]*n
        stk = []
        for i, x in enumerate(heights):
            while stk and heights[stk[-1]] >= x:
                right[stk.pop()] = i
            left[i] = stk[-1] if stk else -1 #栈底哨兵，避免第一个运算错误
            stk.append(i)

        ans = 0
        for i in range(n):
            ans = max(ans, heights[i]*(right[i] - left[i] - 1))
        return ans
```

C++代码：（一次遍历，即出栈就遍历）
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
{
    int ans = 0;
    vector<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.back()] > heights[i])
        {
            int cur = st.back();
            st.pop_back();
            int left = st.back() + 1;
            int right = i - 1;
            ans = max(ans, (right - left + 1) * heights[cur]);
        }
        st.push_back(i);
    }
    return ans;
}  
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用栈
