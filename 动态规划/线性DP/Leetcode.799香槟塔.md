### 原题链接 -- [[799. 香槟塔](https://leetcode.cn/problems/champagne-tower/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/202887402-e8252aa2-d9f4-4572-967c-e00b8647ad88.png)

![image](https://user-images.githubusercontent.com/99656524/202887405-e22dfd9b-2668-4295-999d-b72f0c75c8c3.png)

### 数据范围
* $0 <= poured <= 10^9$
* $0 <= query_glass <= query_row < 100$

### 解法一：动态规划
说实话一开始没看出来是个DP，以为是数学推导题，然后突然想起来数字三角形这道题目。

题目大意为查询某行的某个杯子装香槟的状态。而这就需要之前装香槟杯子的状态转移过来。已经知道装满杯子的香槟会向左和右溢出，下面一层的香槟有一半来自正上方的香槟，一半来自左上方的香槟（数字三角形）。
