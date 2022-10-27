### 原题链接 -- [[179. 最大数](https://leetcode.cn/problems/largest-number/)]

### 题目概述：
Tag : 「贪心」、「排序」

![image](https://user-images.githubusercontent.com/99656524/198170612-b9c77b27-818c-4c04-8538-455554e7df9a.png)

### 数据范围
* $1 <= nums.length <= 100$
* $0 <= nums[i] <= 10^9$

### 解法一：贪心
本题的大意为用已有的数字组合成一个最大的数字，要想组合成一个最大的数字，就要先将数字从大到小排序，但是并不是普通排序。
