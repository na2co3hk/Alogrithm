### 原题链接 -- [[1157. 子数组中占绝大多数的元素](https://leetcode.cn/problems/online-majority-element-in-subarray/)]

### 题目概述：
Tag : 「线段树」、「二分查找」、「摩尔投票」

![image](https://user-images.githubusercontent.com/99656524/232356152-474b6209-81a0-47d7-bee2-9e237d6ec994.png)

### 数据范围
* $1 <= arr.length <= 2 * 104$
* $1 <= arr[i] <= 2 * 104$
* $0 <= left <= right < arr.length$
* $threshold <= right - left + 1$
* $2 * threshold > right - left + 1$
* $调用 query 的次数最多为 104$ 

### 解法一：线段树 + 摩尔投票 + 二分查找
