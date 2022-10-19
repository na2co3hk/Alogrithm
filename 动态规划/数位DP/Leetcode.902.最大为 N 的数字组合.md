### 原题链接 -- [[902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://user-images.githubusercontent.com/99656524/196468443-b1336bb3-5349-46f4-b5ea-c9aa9237ff99.png)

![image](https://user-images.githubusercontent.com/99656524/196468554-8e7eef88-b6aa-4f95-8941-8d3d36419a3a.png)

### 数据范围
* $1 <= digits.length <= 9$
* $digits[i].length == 1$
* digits[i] 是从 '1' 到 '9' 的数
* digits 中的所有值都 不同 
* digits 按 非递减顺序 排列
* $1 <= n <= 10^9$

### 解法一：记忆化搜索
解题思路和题解来自灵神，以下都是自己的理解

关于[数位DP](https://github.com/na2co3hk/Alogrithm/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E6%95%B0%E4%BD%8DDP)可以根据这题的文件夹找到其他相关的题

本题是leetcode上经典的一道数位DP的题目，难度为困难

题目大意为给出一个字符数组 $digits$，和整数 $N$，求用给定字符数组构成数字小于 $N$ 的数字组合的个数

我们可以从数字的位数出发，枚举每一位到边界数字的位数，这一过程是一个状态转移的过程，我们需要上一位的状态来枚举下一位的状态。若上一位作出了受限的选择，则下一位的范围也会受到限制

比如： $digits = ['1','2','3']$     $N = 123$ 

若第一位选择了1，则第二位的选择就不能大于2（如果大于2了就超过N了）。同样第二位的选择也影响到了第三位，若第二位选择是1，则第三位可以选1, 2, 3中的任意一个数字 ; 若第二位选择是2，则第三位的选择不能超过3

前一位做出受限选择还不止数字的选择，还有选不选择数字，毕竟不选数字也是一种选法（比如上一个例子，第一位不选，剩下随便组合都是答案，毕竟都少了一位）

我们用两个参数来代表这两个限制

* $islimit$ 代表数字选择的限制， $True$ 表示上一位受限， $False$ 表示上一位不受限

* $isnum$ 代表选不选数字， $True$ 代表上一位选的是数字， $False$ 表示上一位选的不是数字

枚举到和边界数字的位数就是递归终点

python的代码如下：
```py
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        s = str(n)
        @cache #记忆化搜索
        def f(i: int, is_limit: bool, is_num: bool) -> int:
            if i == len(s): #搜索终点
                return int(is_num) #如果最后一位是数字，则返回1，不是数字则代表一直都不选取数字，返回0
            res = 0
            if not is_num: #上一位不是数字
                res = f(i + 1, False, False) #跳过
            up = s[i] if is_limit else '9' #确定上界
            for d in digits: #在digits中选取
                if d > up:
                    break
                res += f(i + 1, is_limit and d == up, True) #若上一位选择了限制条件，下一位也会被限制
            return res
        return f(0, True, False) #第1位数也是受到限制的，不能随便选
```

C++代码（注释为原帖注释）：
```cpp
class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m];
        memset(dp, -1, sizeof(dp)); // dp[i] = -1 表示 i 这个状态还没被计算出来
        function<int(int, bool, bool)> f = [&](int i, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num; // 如果填了数字，则为 1 种合法方案
            if (!is_limit && is_num && dp[i] >= 0) return dp[i]; // 在不受到任何约束的情况下，返回记录的结果，避免重复运算
            int res = 0;
            if (!is_num) // 前面不填数字，那么可以跳过当前数位，也不填数字
                // is_limit 改为 false，因为没有填数字，位数都比 n 要短，自然不会受到 n 的约束
                // is_num 仍然为 false，因为没有填任何数字
                res = f(i + 1, false, false);
            char up = is_limit ? s[i] : '9'; // 根据是否受到约束，决定可以填的数字的上限
            // 注意：对于一般的题目而言，如果这里 is_num 为 false，则必须从 1 开始枚举，由于本题 digits 没有 0，所以无需处理这种情况
            for (auto &d : digits) { // 枚举要填入的数字 d
                if (d[0] > up) break; // d 超过上限，由于 digits 是有序的，后面的 d 都会超过上限，故退出循环
                // is_limit：如果当前受到 n 的约束，且填的数字等于上限，那么后面仍然会受到 n 的约束
                // is_num 为 true，因为填了数字
                res += f(i + 1, is_limit && d[0] == up, true);
            }
            if (!is_limit && is_num) dp[i] = res; // 在不受到任何约束的情况下，记录结果
            return res;
        };
        return f(0, true, false);
    }
};
```
* 时间复杂度： $O(dlogn)$ ，其中 d 是 $digits$ 的长度。动态规划的时间复杂度 == 状态个数 * 单个状态的转移个数，本题中状态个数等于 n 转成字符串后的长度，即 $O(logn)$ ，而单个状态的转移个数为 $d$，因此时间复杂度为 $O(dlogn)$。
* 空间复杂度： $O(logn)$ 
