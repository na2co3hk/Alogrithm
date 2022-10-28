### 原题链接 -- [[907. 子数组的最小值之和](https://leetcode.cn/problems/sum-of-subarray-minimums/)]

### 题目概述：
Tag : 「单调栈」

![image](https://user-images.githubusercontent.com/99656524/198457518-b5600870-fd49-4cef-b32a-aab558cf1db9.png)

### 数据范围
* $1 <= arr.length <= 3 * 10^4$
* $1 <= arr[i] <= 3 * 10^4$

### 解法一：单调栈
题解和思路来自灵神，以下是我的理解，没想到用单调栈就只能抄了

求每个子数组的最小值之和，我们首先要求出每个子数组的最小值。与此同时，我们发现有些子数组的最小值是同一个，因此我们可以根据最小值 $min$ 找出一个区间，这个区间的子数组最小值都是
$min$ ，这样我们就将问题转化为了求最小值的左右区间，区间元素最小值的和就等于  区间元素的个数 * 区间最小值，即是最小元素对答案的贡献。假设 $arr[i]$ 是某个区间的最小值，区间左右边界为 $L$， $R$，那么arr[i]对答案的贡献为： 

$$
arr[i] * (i-L) * (R-i)
$$

需要注意的是，要是有相同元素的最小元素的话，边界的设定就要小于等于最小值了，这样才能防止重复计算。接下来就是解释如何高效计算左右边界

![image](https://user-images.githubusercontent.com/99656524/198478175-1ca041b6-85b5-44f9-b81f-ac206ae351ab.png)（图片来自灵神）

我们可以用一个单调栈维护左右区间。循环变量为区间右边界，当弹出一个元素的时候，弹出值的左边界即是弹出之后的栈顶这样就可以在弹出元素时候顺便计算贡献，然后再将贡献求和得出答案

py代码：
```py
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        arr.append(-1)
        ans, st = 0, [-1]  # 哨兵
        for r, x in enumerate(arr):
            # 也可以 while arr[st[-1]] > x，效率略高一点
            while len(st) > 1 and arr[st[-1]] >= x:
                i = st.pop()
                ans += arr[i] * (i - st[-1]) * (r - i)  # 累加贡献
            st.append(r)
        return ans % (10 ** 9 + 7)
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用栈
