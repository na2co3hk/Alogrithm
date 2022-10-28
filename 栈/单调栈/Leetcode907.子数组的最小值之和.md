### 原题链接 -- [[907. 子数组的最小值之和](https://leetcode.cn/problems/sum-of-subarray-minimums/)]

### 题目概述：
Tag : 「单调栈」

![image](https://user-images.githubusercontent.com/99656524/198457518-b5600870-fd49-4cef-b32a-aab558cf1db9.png)

### 数据范围
* $1 <= arr.length <= 3 * 10^4$
* $1 <= arr[i] <= 3 * 10^4$

### 解法一：单调栈
题解和思路来自灵神，以下是我的理解，没想到用单调栈

求每个子数组的最小值之和，我们首先要求出每个子数组的最小值。与此同时，我们发现有些区间的最小值是同一个，因此我们可以根据最小值找出
