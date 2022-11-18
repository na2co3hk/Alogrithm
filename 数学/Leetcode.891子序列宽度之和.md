### 原题链接 -- [[891. 子序列宽度之和](https://leetcode.cn/problems/sum-of-subsequence-widths/)]

### 题目概述：
Tag : 「数学」、「快速幂」

![image](https://user-images.githubusercontent.com/99656524/202600554-5c7f3e01-a679-4d00-91b8-6ad1e943c3c3.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^5$

### 解法一：数学
有关于最大，最小字样的，就优先想排序、堆、动态规划。

本题大意为每个子序列中最大值和最小值差值的和，一看到这种子数组、子序列求和十有八九是计算贡献类，怎么样计算贡献才是关键。首先将数组排序，为什么？因为数组的顺序并不重要，我们需要关心的是最大值和最小值，并且无论顺序如何我们得出的答案都是一样的，只是排列不同。排完序后，我们考虑一个数是最小值或者最大值的贡献，在排序数组中，一个数 $a$ 可以将数组分为比 $a$  大的数和比 $a$ 小的数，而且计算出其中一边另一边也能知道（总数-其中一边的个数）。当 $nums[i]$ 作为最大值的贡献时，我们只能在小于 $nums[i]$ 的数（左边）中选择子序列，共有 $2^i$ 中选法，同理可得 $nums[i]$ 作为最小值的子序列的答案个数 $2^N ,（N = n - i - 1）$ ，最后得到 $nums[i]$对答案的贡献 $nums[i] * (2^i - 2^N)$

python代码：
```py
class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        nums.sort()
        return sum((pow(2, i, MOD) - pow(2, len(nums) - 1 - i, MOD)) * x
                   for i, x in enumerate(nums)) % MOD
```
* 时间复杂度： $O(nlogn)$ 排序时间
* 空间复杂度： $O(n)$ 
