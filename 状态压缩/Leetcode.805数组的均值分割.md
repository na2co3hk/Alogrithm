### 原题链接 -- [[805. 数组的均值分割](https://leetcode.cn/problems/split-array-with-same-average/)]

### 题目概述：
Tag : 「状态压缩」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/201562475-4429ef84-7822-4583-966d-c93c83f5e63b.png)

### 数据范围
* $1 <= nums.length <= 30$
* $0 <= nums[i] <= 10^4$

### 解法一：状态压缩 + 折半枚举
本题大意为将一个数组分成两个平均值相同的数组

我们令两个数组A,B为分完数之后的数组。首先看数据范围，数组的长度 <= 30，说明应该使用暴力算法来枚举，刚好我们可以枚举数组中的每一种状态，每个数只有选和不选两种状态，选这个数就相当于放在A数组中，不选就相当于放到B数组中，然后利用二进制枚举每个数的状态。设原数组元素的数量为 $n$,元素总和为 $tot$ , 放到A数组中的元素数量为 $cnt1$ 个，则B数组中元素的数量为 $n - cnt1$ , A数组的和为 $sum1$ ，B数组的和为 $tot - sum1$ 那么A数组的平均值就是 $sum1/cnt1$，B数组的平均值为 $sum1/cnt2$ ，最后只要判断两个平均值是否相等即可，这种算法的时间复杂度为 $O(2^n)$ ，会超时。

python代码：（TLE）
```py
class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        n, tot, cnt1, sum1 = len(nums), sum(nums), 0, 0
        for mask in range(1, 1 << n):
            for i in range(n):
                if (1 << i) & mask:
                    cnt1 += 1
                    sum1 += nums[i]
            cnt2, sum2 = n - cnt1, tot - sum1
            if cnt1 and cnt2 :
                avg1, avg2 = sum1/cnt1, sum2/cnt2
            else : continue
            if avg1 == avg2:
                return True
            cnt1, sum1, cnt2, sum2 = 0, 0, 0, 0
        return False
```
* 时间复杂度： $O(2^n)$ 
* 空间复杂度： $O(2^n)$ 
