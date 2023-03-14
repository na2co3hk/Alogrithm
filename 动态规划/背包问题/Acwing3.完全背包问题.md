### 原题链接 -- [[3. 完全背包问题](https://www.acwing.com/problem/content/description/3/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/225010647-ad6ebb64-acf9-430b-a974-b7e79d489f12.png)

背包问题是一个系列，01背包是这个系列的第一章，其他的[在这里](https://github.com/na2co3hk/Alogrithm/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98)

下面是正题

本题是01背包的一道进阶版本，唯一的改动是每件物品都可以装无限次，仍然是求能装物品价值的最大值。

和01背包一样，从递推开始想，设第i件物品的体积为v[i]， 价值为w[i]，设第i件物品总共选择k次，用递归的形式可以得出：

$$
       dfs(i, V) = max(dfs(i-1, V), dfs(i-1, V-k * v[i]) + k * w[i]) ( i = N,N-1...2,1 )
$$

其中dfs(i, V)代表第i件物品选k次，重量不超过V的价值
