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
   dfs(i, V) = max(dfs(i-1, V), dfs(i-1, V-v[i]) + w[i]) ( i = N,N-1...2,1 )
$$

其中

$dfs(i, V)代表前i件物品重量不超过V能够得到的最大价值$

$dfs(i-1, V)代表不选择第i件物品时不超过V能得到的最大价值$

$dfs(i-1, V-v[i]) + w[i]代表选择第i件物品时不超过V能得到的最大价值$

上述的式子也可以转换成用数组的递推式

$$
   f[i,V] = max(f[i-1][V], f[i-1][V-v[i]] + w[i]) ( i = N,N-1...2,1 )
$$

接着就要考虑递推式的初始化问题，但是这题求的是最大值，可以直接全部默认初始化为0

最后用循环枚举各种状态，最终的状态为 f[N][V]

C++代码：
```cpp
#include<iostream>

using namespace std;
const int MAX = 1010;
int N,V;//物品数量，背包容量
int v[MAX],w[MAX];//体积，价值

int main()
{
    cin>>N>>V;
    for(int i = 1;i <= N;i++)
    {
        cin>>v[i]>>w[i];
    }
    int dp[MAX+1][MAX+1];
    for(int i = 1;i <= N;i++)
    {
        for(int j = 0;j <= V;j++)
        {
            if(j<v[i])//背包剩余重量不够
            {
                dp[i][j]=dp[i-1][j];//只能不选
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            }
        }
    }
    cout<<dp[N][V];
    return 0;
}
```
