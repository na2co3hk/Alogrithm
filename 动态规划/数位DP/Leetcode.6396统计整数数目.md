### 原题链接 -- [[6396. 统计整数数目](https://leetcode.cn/problems/count-of-integers/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/f10ef463-1aea-4adc-9b71-6b845b0c838f)

### 数据范围
* $1 <= num1 <= num2 <= 10^22$
* $1 <= min_sum <= max_sum <= 400$

### 解法一：记忆化搜索
关于[数位DP](https://github.com/na2co3hk/Alogrithm/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E6%95%B0%E4%BD%8DDP)可以根据这题的文件夹找到其他相关的题

怎么判断这题属于数位DP？给定了一个边界数字，并且与每个数字的每一个数位相关，则判定属于数位DP问题

根据数位DP的思路，我们依旧选择类似于填数字的方法，枚举到边界数字的位数退出，这一过程是一个状态转移的过程，我们需要上一位的状态来枚举下一位的状态。若上一位作出了受限的选择，则下一位的范围也会受到限制

前一位做出受限选择还不止数字的选择，还有选不选择数字，毕竟不选数字也是一种选法

回到本题，本题要求统计 $num1$ 到 $num2$ 之间并且每个数位和都在 $min_sum$ 到 $max_sum$ 之间，我们只需要枚举每位填的数字，确定填的数字的上界和下界，并且查看填的数字是否被限制即可。此外，递归出口就判断数位和是否在 $min_sum$ 到 $max_sum$ 之间。

python代码
```py
class Solution:
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        L1 = len(num1)
        L2 = len(num2)
        num1 = '0' * (L2 - L1) + num1
        MOD = int(1e9 + 7)

        @cache
        def dfs(idx, isMax, isMin, dSum):
            if idx == L2: return min_sum <= dSum <= max_sum
            n1, n2 = int(num1[idx]), int(num2[idx])
            lo, hi = n1 if isMin else 0, n2 if isMax else 9
            ans = 0
            for i in range(lo, hi + 1):
                ans += dfs(idx + 1, isMax and i == hi, isMin and i == lo, dSum + i)
                ans %= MOD
            return ans

        return dfs(0, True, True, 0)
```
* 时间复杂度： $O(10nm)$
* 空间复杂度： $$(nm)$
