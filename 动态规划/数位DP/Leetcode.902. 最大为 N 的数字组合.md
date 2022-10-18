### 原题链接 -- [[902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://user-images.githubusercontent.com/99656524/196468443-b1336bb3-5349-46f4-b5ea-c9aa9237ff99.png)

![image](https://user-images.githubusercontent.com/99656524/196468554-8e7eef88-b6aa-4f95-8941-8d3d36419a3a.png)

### 数据范围
* 1 <= digits.length <= 9
* digits[i].length == 1
* digits[i] 是从 '1' 到 '9' 的数
* digits 中的所有值都 不同 
* digits 按 非递减顺序 排列
* 1 <= n <= 109

### 解法一：记忆化搜索
解题思路和题解来自灵神，以下都是自己的理解

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

代码如下：
```py
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        s = str(n)
        @cache
        def f(i: int, is_limit: bool, is_num: bool) -> int:
            if i == len(s):
                return int(is_num)
            res = 0
            if not is_num:
                res = f(i + 1, False, False)
            up = s[i] if is_limit else '9' #确定上界
            for d in digits:
                if d > up:
                    break
                res += f(i + 1, is_limit and d == up, True)
            return res
        return f(0, True, False)
```
