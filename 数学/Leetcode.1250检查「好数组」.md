### 原题链接 -- [[1250. 检查「好数组」](https://leetcode.cn/problems/check-if-it-is-a-good-array/)]

### 题目概述：
Tag : 「数学」

![image](https://user-images.githubusercontent.com/99656524/219846602-d46d3c8d-c328-4946-8ea6-7cda8d446afb.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^9$

### 解法一：数学
本题涉及到数论中的扩展欧几里得定理（好像也叫裴蜀定理和贝祖定理），这个定理大概意思是a和b两个数，对于任意的整数x和y，都有ax + by = gcd(a, b)

$$
它的一个重要推论是：a,b互质的充分必要条件是存在整数x,y使ax+by=1.
$$
