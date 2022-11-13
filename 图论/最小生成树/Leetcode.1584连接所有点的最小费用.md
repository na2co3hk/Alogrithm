### 原题链接 -- [[1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/)]

### 题目概述：
Tag : 「最小生成树」

![image](https://user-images.githubusercontent.com/99656524/201503569-87e59ce3-8b74-4bb2-ba4e-43f772edbf55.png)

![image](https://user-images.githubusercontent.com/99656524/201503584-03bb37f7-4f5e-4a20-ad72-7b47d529e5e5.png)

![image](https://user-images.githubusercontent.com/99656524/201503592-4f9b34bd-44f0-4315-ac6c-e715242c0aa6.png)

### 解法一：克鲁斯卡尔算法
本题是最小生成树的入门题，可以当作一个模板来看

题目大意为找出链接所有点的最小代价，十分类似于最小生成树的性质，生成树的性质如下：
* 一个连通图可以有多个生成树；
* 一个连通图的所有生成树都包含相同的顶点个数和边数；
* 生成树当中不存在环；
* 移除生成树中的任意一条边都会导致图的不连通， 生成树的边最少特性；
* 在生成树中添加一条边会构成环。
* 对于包含n个顶点的连通图，生成树包含n个顶点和n-1条边；
* 对于包含n个顶点的无向完全图最多包含 $n^n/n^2$ 颗生成树。

而最小生成树，就是在原有的图上给每条边加上权重，查找链接所有点的最小总权重
