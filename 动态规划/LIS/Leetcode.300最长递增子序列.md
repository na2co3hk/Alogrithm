### 原题链接 -- [[300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)]

### 题目概述：
Tag : 「动态规划」、「二分查找」

![image](https://user-images.githubusercontent.com/99656524/226795988-95c69b4e-ca01-47b7-819b-a8f93e8a6ae8.png)

### 数据范围
* $1 <= nums.length <= 2500$
* $-10^4 <= nums[i] <= 10^4$

### 解法一：动态规划
题目大意为找到一个最大长度的上升子序列。由于数组中的每个元素只有选和不选两种状态，并且每一次的选择和上一次的选择有关，我们考虑用动态规划去解决。
