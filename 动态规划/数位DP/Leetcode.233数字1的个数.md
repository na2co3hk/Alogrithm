### 原题链接 -- [[233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://user-images.githubusercontent.com/99656524/196583577-55f2556c-a339-4d66-ae63-86ee44fedaa6.png)

### 数据范围
 * $0 <= n <= 10^9$

### 解法一：记忆化搜索
属于是数位DP的一道入门题

关于[数位DP](https://github.com/na2co3hk/Alogrithm/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E6%95%B0%E4%BD%8DDP)可以根据这题的文件夹找到其他相关的题

题目给定一个界限 $n$ 求小于等于n的所有整数中1的出现次数

例如上图实例中的 $13$ ，出现1的数字为1，10，11，12，13，其中 $11$ 这个数出现了两次1，所以要计两次，总共为6次

根据数位DP的思路，我们依旧选择类似于填数字的方法，枚举到边界数字的位数退出，这一过程是一个状态转移的过程，我们需要上一位的状态来枚举下一位的状态。若上一位作出了受限的选择，则下一位的范围也会受到限制

前一位做出受限选择还不止数字的选择，还有选不选择数字，毕竟不选数字也是一种选法（选少一位）

* $islimit$ 代表数字选择的限制， $True$ 表示上一位受限， $False$ 表示上一位不受限

* $isnum$ 代表选不选数字， $True$ 代表上一位选的是数字， $False$ 表示上一位选的不是数字

而在本题中，上一位是否是数字并不影响，因为上一位不选数字则代表少选一位数，所以这个限制可以去除

除此之外，我们还需要一个 $cnt$ 记录上一个状态1出现的个数

python代码：
```py
# 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
class Solution:
    def countDigitOne(self, n: int) -> int:
        s = str(n)

        @cache
        def f(i: int, is_limit: bool, cnt: int) -> int:
            if i == len(s):
                return cnt
            res = 0
            up = int(s[i]) if is_limit else 9 
            for d in range(up + 1): #枚举到上界
                k = 1 if d == 1 else 0 #若选取的数字为1，则要记录选取次数
                res += f(i + 1, is_limit and d == up, cnt + k) #cnt + k 代表上一个状态选取1的次数+当前状态是否选1
            return res

        return f(0, True, 0)
```

C++代码：
```cpp
class Solution {
public:
    int countDigitOne(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][m];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool)> f = [&](int i, int cnt1, bool is_limit) -> int {
            if (i == m) return cnt1;
            if (!is_limit && dp[i][cnt1] >= 0) return dp[i][cnt1];
            int res = 0;
            for (int d = 0, up = is_limit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
                res += f(i + 1, cnt1 + (d == 1), is_limit && d == up);
            if (!is_limit) dp[i][cnt1] = res;
            return res;
        };
        return f(0, 0, true);
    }
};
```
