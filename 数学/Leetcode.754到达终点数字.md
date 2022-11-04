### 原题链接 -- [[754. 到达终点数字](https://leetcode.cn/problems/reach-a-number/)]

### 题目概述：
Tag : 「二分查找」、「数学」

![image](https://user-images.githubusercontent.com/99656524/199866966-4f25acbd-4eb9-4c0b-9042-767aeea0c870.png)

### 数据范围
* $-10^9 <= target <= 10^9$
* $target != 0$

### 解法一：数学
根据题意，我们需要移动最小的N步到达目标，并且有往前走和往后走两种选择。记 $s$ 为当前位置，我们可以先找到大于等于 $target$ 的 $s$ ，若 $s-target$ 为奇数，那么得往回走一步，若 $s-target$ 为偶数，我们前面走的必有1步是往回走的( s - target / 2)，只要那步往回走就行，
