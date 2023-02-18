### 原题链接 -- [[2. 01背包问题](https://www.acwing.com/problem/content/description/2/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/197217653-0f3c2f52-cd6e-409c-b2c3-f7ffc304695e.png)

### 解法一:动态规划
背包问题是经典的动态规划类题目，很多题目也是根据背包的模型改编而成的

背包问题是一个系列，01背包是这个系列的第一章，其他的[在这里](https://github.com/na2co3hk/Alogrithm/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98)

下面是正题

对于动态规划问题，一个通用想法就是从递归开始想，设第i件物品的体积为v[i]， 价值为w[i]，由于每个物品只有选和不选两种状态，用递归的形式可以得出

$$
   dfs(i, V) = max(dfs(i+1, V), dfs(i+1, V-v[i]) + w[i])
$$


