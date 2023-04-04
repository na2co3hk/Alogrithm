### 原题链接 -- [[1000. 合并石头的最低成本](https://leetcode.cn/problems/minimum-cost-to-merge-stones/)]

### 题目概述：
Tag : 「动态规划」、「前缀和」

![image](https://user-images.githubusercontent.com/99656524/229772741-398388dd-bd7b-4b42-a2fd-6a746cf61034.png)

![image](https://user-images.githubusercontent.com/99656524/229772763-bce67742-4971-474b-8d89-41532757161d.png)

### 数据范围
* 1 <= stones.length <= 30
* 2 <= K <= 30
* 1 <= stones[i] <= 100

### 解法一：动态规划 + 前缀和
本题为[石子合并](https://github.com/na2co3hk/Alogrithm/edit/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E5%8C%BA%E9%97%B4DP/ACwing282.%E7%9F%B3%E5%AD%90%E5%90%88%E5%B9%B6.md)的进阶版，建议先复习这个

本题和经典的石子合并不同的是本题要求每次合并的石头堆数为K（之前为只用合并两堆），这样需要考虑的因素又变多了一个，就需要多进行一次枚举。不仅如此，我们还需要考虑能否合并为一堆的问题，如果需要将n堆石子合并成一堆，就需要消减n-1堆石子，而我们每次合并k堆，都需要消减k-1堆，由此可见如果n-1必须是k-1的倍数（k合1是原题目的一个子问题，原问题为n合1，动态规划就是将原问题分解成若干个性质一样的子问题，所以k-1必须是n-1的倍数）。
