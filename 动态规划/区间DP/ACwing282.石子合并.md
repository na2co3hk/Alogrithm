### 原题链接 -- [[282. 石子合并](https://www.acwing.com/problem/content/description/284/)]

### 题目概述：
Tag : 「动态规划」、「前缀和」

![image](https://user-images.githubusercontent.com/99656524/198271576-38ea3395-d683-42ff-94a3-941d6c506a70.png)

![image](https://user-images.githubusercontent.com/99656524/198271826-cb505415-79d1-4427-861d-db5f04e122c7.png)

### 解法一：动态规划
本题是区间DP的入门题

大意为求合并1到n区间的最小代价，由于每次合并的代价都和上一次有关，我们就需要用到状态转移了，而因此想到了动态规划的办法。先定义一下动态规划的状态，dp[i][j]表示第i到第j堆合并的最小代价，
