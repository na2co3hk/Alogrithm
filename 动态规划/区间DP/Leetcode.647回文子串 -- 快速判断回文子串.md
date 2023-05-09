### 原题链接 -- [[647. 回文子串](https://leetcode.cn/problems/palindromic-substrings/)]

### 题目概述：
Tag : 「回文」、「动态规划」

![image](https://user-images.githubusercontent.com/99656524/236971578-4e98ebdf-794a-403c-9323-f1434487392c.png)

### 数据范围
* 1 <= s.length <= 1000
* s 由小写英文字母组成

### 解法一：动态规划
先预处理所有回文子串，再用一个二重循环计数，这个预处理回文子串是模板，可以记一下。

C++代码：
```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        //预处理回文子串，g[i][j]表示s[i:j]是否为回文串
        vector<vector<bool>>g(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = i; j < n;j++)
            {
                ans += g[i][j];
            }
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n^2)$
