### 原题链接 -- [[3. 完全背包问题](https://www.acwing.com/problem/content/description/3/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/225010647-ad6ebb64-acf9-430b-a974-b7e79d489f12.png)

### 解法一:动态规划
背包问题是一个系列，01背包是这个系列的第一章，其他的[在这里](https://github.com/na2co3hk/Alogrithm/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98)

下面是正题

本题是01背包的一道进阶版本，唯一的改动是每件物品都可以装无限次，仍然是求能装物品价值的最大值。

和01背包一样，从递推开始想，设第i件物品的体积为v[i]， 价值为w[i]，设第i件物品总共选择k次，用递归的形式可以得出：

$$
       dfs(i, V) = max(dfs(i-1, V), dfs(i-1, V-k * v[i]) + k * w[i]) ( i, V = N,N-1...2,1 )
$$

其中dfs(i, V)代表第i件物品选k次，重量不超过V的价值

然后转换成递推式：

$$
   f[i,j] = max(f[i-1][j], f[i-1][j - k * v[i]] + k * w[i]) ( i, j = 1, 2, 3...N )
$$

这是最基本的表达式，我们可以试着像01背包那样优化一下，将数组降为一维，这样就可以得出一个基本的表达式

$$
   f[j]=max(f[j],f[j-k * v[i]]+k * w[i]); 
$$

C++代码：
```cpp
#include<iostream>
using namespace std;

const int maxn = 1010;
int n,m;
int v[maxn],w[maxn];
int dp[maxn];

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            for(int k = 0;k*v[i]<=j;k++ )
            {
                dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}
```
* 时间复杂度： $O(nm^2)$ 可能有错
* 空间复杂度： $O(m)$ 

### 优化（重点）
从上面的代码可以看出，代码枚举需要用到三重循环，显然这样的时间复杂度是不能接受的，我们可以考虑优化掉一层循环。

优化总是从状态转移方程开始考虑，若将第i件物品只选择一次的表达式和原本的表达式结合在一起看，如下图所示

![image](https://user-images.githubusercontent.com/99656524/225027827-a2525866-1893-49e0-ae8c-3b6273312d66.png)

从上图不难看出：

$$
  f[i][j]=max(f[i,j-v]+w , f[i-1][j])
$$

这样就得到了完全背包的一个优化方程，并且这个式子和01背包的转移方程十分相识

f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);//01背包

f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);//完全背包问题

两个式子只差了一个i-1，因此完全背包也可以使用01背包的优化方法即可得出完全背包问题的最终表达式

$$
 f[j]=max(f[j],f[j-v[i]]+w[i])
$$

但是这次由于是需要同一层的数据，所以直接顺序遍历即可

C++代码：
```cpp
#include<iostream>
using namespace std;

const int maxn = 1010;
int n,m;
int v[maxn],w[maxn];
int dp[maxn];

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = v[i];j<=m;j++)
        {
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
```
* 时间复杂度： $O(nm)$ 可能有错
* 空间复杂度： $O(m)$ 

