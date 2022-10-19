### 原题链接 -- [[2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://user-images.githubusercontent.com/99656524/196587993-b08bfd7d-468d-42f7-9b18-7daa53e2dbd0.png)

### 数据范围
* $1 <= n <= 2 * 10^9$

### 解法一：记忆化搜索
这是一道数位DP的困难题

怎么判断这题属于数位DP？给定了一个边界数字，并且与每个数字的每一个数位相关，则判定属于数位DP问题

再来看本题，题目大意为找出位于 $[1,n]$
