### 原题链接 -- [[790. 多米诺和托米诺平铺](https://leetcode.cn/problems/domino-and-tromino-tiling/)]

### 题目概述：
Tag : 「动态规划」、「找规律」

![image](https://user-images.githubusercontent.com/99656524/201463290-782a0850-2647-49a8-a3d1-bfe517de08a4.png)

![image](https://user-images.githubusercontent.com/99656524/201463305-8bddcb4e-35c4-4e0b-8a51-c5a2de9a1b74.png)

### 数据范围
* 1 <= n <= 1000

### 解法一：动态规划
题目大意为寻找摆满面积为 2 * n 的矩形的方案数，我们可以从n == 1开始手动推导一下:
f[1] = 1 --只有一个
f[2] = 1 + 1 = 2 --可以两个同时横着摆，两个同时竖着摆
f[3] = f[2] + f[1] + 2 = 5 --
