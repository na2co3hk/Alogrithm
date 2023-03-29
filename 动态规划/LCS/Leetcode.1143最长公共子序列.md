### 原题链接 -- [[1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/226866856-eccf34cc-9e4a-4def-ae53-3e9cb507b6b7.png)

![image](https://user-images.githubusercontent.com/99656524/226866881-31e195e8-5902-49b4-8176-c3a973f2cb3c.png)

### 数据范围
* 1 <= text1.length, text2.length <= 1000
* text1 和 text2 仅由小写英文字符组成。

### 解法一：动态规划
看注释

C++代码：
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);//代表必然不使用text2[j-1]（但可能使用text1[i-1]）时和必然不使用text1[i-1]（但可能使用text2[j-1]）时的LCS长度
                if(text1[i-1]==text2[j-1])dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);//是公共字符
            }
        }
        return dp[n][m];
    }
};
```
* 时间复杂度： $O(nm)$ 
* 空间复杂度： $O(nm)$ 

