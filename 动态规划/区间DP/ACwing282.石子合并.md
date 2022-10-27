### 原题链接 -- [[282. 石子合并](https://www.acwing.com/problem/content/description/284/)]

### 题目概述：
Tag : 「动态规划」、「前缀和」

![image](https://user-images.githubusercontent.com/99656524/198271576-38ea3395-d683-42ff-94a3-941d6c506a70.png)

![image](https://user-images.githubusercontent.com/99656524/198271826-cb505415-79d1-4427-861d-db5f04e122c7.png)

### 解法一：动态规划
本题是区间DP的入门题

大意为求合并1到n区间的最小代价，由于每次合并的代价都和上一次有关，我们就需要用到状态转移了，而因此想到了动态规划的办法。先定义一下动态规划的状态，dp[i][j]表示第i到第j堆合并的最小代价，每次合并都要加上之前合并的区间和，我们就还需要用到前缀和数组。又因为我们是两堆两堆的合共，所以到最后我们必然只剩下两堆，但是我们并不知道怎么样合并才能使两堆合成最小，所以我们只能枚举合并的分割点，然后取最小值。dp[1][n]就是最后的答案。

C++代码：
```cpp
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

const int N = 310;
int n;
int s[N];
int a[N];
int dp[N][N];

int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    
    memset(dp, 0, sizeof dp);
    for(int len = 2;len <= n; len++)
    {
        for(int i = 1;i + len - 1 <= n;i++)
        {
            int l = i,r = len + i - 1;
            dp[l][r] = 0x3f3f3f3f;
            for(int k = l;k <= r;k++)
            {
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}
```
