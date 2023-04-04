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

本题和经典的石子合并不同的是本题要求每次合并的石头堆数为K（之前为只用合并两堆），这样需要考虑的因素又变多了一个，就需要多进行一次枚举。不仅如此，我们还需要考虑能否合并为一堆的问题，如果需要将n堆石子合并成一堆，就需要消减n-1堆石子，而我们每次合并k堆，都需要消减k-1堆，由此可见如果n-1必须是k-1的倍数（k合1是原题目的一个子问题，原问题为n合1，动态规划就是将原问题分解成若干个性质一样的子问题，所以n-1必须是k-1的倍数）。

定义 $dp[i][j][k]$ 表示第i到第j堆石头合并成k堆的最小代价，接下来就是将问题分解，我们可以将k堆石子合并分解为求1堆石子的最小代价和合并成k-1堆石子的最小代价（子问题为合成k-1堆，这样到最后就可以k合1了），为什么只用考虑分出1堆合k-1的情况？因为当问题进一步缩小的时候，k-1堆又会分出1堆和k-2堆，这样和前面分出的1堆组合一下就能表达出分2堆和k-2堆的情况了。剩下的做法和经典石子合并是一样的，只需加上区间和即可。

C++代码：
```cpp
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n - 1) % (K - 1))return -1;
        vector<int>s(n + 1);
        for(int i = 1;i <= n;i++)s[i] = s[i-1] + stones[i-1]; //前缀和
        int f[n + 1][n + 1][K + 1];
        memset(f, 0x3f, sizeof(f));
        for(int i = 1;i <= n;i++)f[i][i][1] = 0;
        for(int len = 2;len <= n;len++)
        {
            for(int i = 1;i + len - 1 <= n;i++)
            {
                int l = i, r = i + len - 1;
                for(int k = 1;k <= K ;k++) 
                {
                    for(int h = l;h < r;h++)
                    {
                        f[l][r][k] = min(f[l][r][k], f[l][h][1] + f[h + 1][r][k - 1]); //将问题分解为子问题
                    }
                }
                f[l][r][1] = f[l][r][K] + s[r] - s[l - 1];
            }
        }
        return f[1][n][1];
    }
};
```
* 时间复杂度： $O(n^3*K)$
* 空间复杂度： $O(n^3)$ 

