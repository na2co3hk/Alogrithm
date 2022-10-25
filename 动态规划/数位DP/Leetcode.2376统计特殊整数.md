### 原题链接 -- [[2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://user-images.githubusercontent.com/99656524/196587993-b08bfd7d-468d-42f7-9b18-7daa53e2dbd0.png)

### 数据范围
* $1 <= n <= 2 * 10^9$

### 解法一：记忆化搜索
这是一道数位DP的困难题

关于[数位DP](https://github.com/na2co3hk/Alogrithm/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E6%95%B0%E4%BD%8DDP)可以根据这题的文件夹找到其他相关的题

怎么判断这题属于数位DP？给定了一个边界数字，并且与每个数字的每一个数位相关，则判定属于数位DP问题

再来看本题，题目大意为找出位于 $[1,n]$ 中每一个数位都不相同的数字

比如： 当 n == 13 时，除11（个位和十位都是1）其他都是特殊整数

根据数位DP的思路，我们依旧选择类似于填数字的方法，枚举到边界数字的位数退出，这一过程是一个状态转移的过程，我们需要上一位的状态来枚举下一位的状态。若上一位作出了受限的选择，则下一位的范围也会受到限制

前一位做出受限选择还不止数字的选择，还有选不选择数字，毕竟不选数字也是一种选法

* $islimit$ 代表数字选择的限制， $True$ 表示上一位受限， $False$ 表示上一位不受限

* $isnum$ 代表选不选数字， $True$ 代表上一位选的是数字， $False$ 表示上一位选的不是数字

除此之外，本题还需要一个集合表示之前选取的状态，我们用一个整形 $mask$ 表示（二进制表示集合），利用位运算标记该数字是否被选过

python代码：
```py
class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        s = str(n) #先转换为字符串
        @cache #记忆化搜索
        def f(i: int, mask: int, is_limit: bool, is_num: bool) -> int: #mask用二进制表示集合，表示每一位是否填了数字（可有可无看情况）
            if i == len(s): #递归到最深层
                return int(is_num)
            res = 0
            if not is_num:  # 可以跳过当前数位
                res = f(i + 1, mask, False, False)
            up = int(s[i]) if is_limit else 9 #表示能填的数字的上界（如果上一位填的已经被限制，这一位的上界也是收限制的，如果没被限制上界则是9）
            for d in range(0 if is_num else 1, up + 1):  # 枚举要填入的数字 d（如果上一位填入过数字，则下界可以从0开始，没填过数字就必须从1开始）
                if mask >> d & 1 == 0:  # d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), is_limit and d == up, True) #若d为上界（已经被限制），则下一位上界也受限制 
            return res
        return f(0, 0, True, False)
```

C++代码：
```cpp
class Solution {
public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num;
            if (!is_limit && is_num && dp[i][mask] >= 0) return dp[i][mask];//记忆化搜索
            int res = 0;
            if (!is_num) res = f(i + 1, mask, false, false); // 可以跳过当前数位
            for (int d = 1 - is_num, up = is_limit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
                if ((mask >> d & 1) == 0) // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            if (!is_limit && is_num) dp[i][mask] = res;
            return res;
        };
        return f(0, 0, true, false);
    }
};
```

