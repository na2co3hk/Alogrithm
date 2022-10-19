### 原题链接 -- [[5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)]

### 题目概述：
Tag : 「动态规划」、「Manacher算法」

![image](https://user-images.githubusercontent.com/99656524/196643829-0415e9f7-b822-465f-8aa6-544551afd3fa.png)

### 数据范围
* 1 <= s.length <= 1000
* s 仅由数字和英文字母组成

### 解法一：动态规划
状态表示：第i个字符到第j个字符是否为回文串，若是回文串，返回最大长度
状态转移方程如下：

$$
f[i][j] = f[i+1][j-1]  s[i] == s[j] 
$$

$$
f[i][j] = False  s[i] != s[j]
$$

python代码：
```py
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n, m, begin = len(s), 1, 0 #m为最长的子串的长度,最小长度是1,begin是最长回文子串的起始位置，起始下标为0
        if n < 2:
            return s
        f = [[False] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = True #每个字符单独拿出来都是回文串

        for l in range(2, n + 1): #枚举一下子串长度
            for i in range(n): #枚举左边界
                j = l + i - 1  #右边界
                if j >= n:
                    break  #右边界越界，直接退出循环
                if s[i]!=s[j]: #字符不匹配
                    f[i][j]=False
                else:
                    if j - i < 3: #区间只有2个字符或者1个字符,并且这两个字符时相等的
                        f[i][j] = True
                    else:
                        f[i][j] = f[i+1][j-1]#转移的条件 f[i][j] = f[i+1][j-1] and s[i] == s[j]

                if f[i][j] == True and j - i + 1 > m: #记录最长回文子串,j - i + 1是子串的长度
                    m = j - i + 1
                    begin = i

        return s[begin:begin + m]
```

### 解法二：中心扩散法
我们枚举回文串的中心，向两边扩散，返回最大长度
