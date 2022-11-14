### 原题链接 -- [[805. 数组的均值分割](https://leetcode.cn/problems/split-array-with-same-average/)]

### 题目概述：
Tag : 「状态压缩」、「哈希表」、「Meet in middle」

![image](https://user-images.githubusercontent.com/99656524/201562475-4429ef84-7822-4583-966d-c93c83f5e63b.png)

### 数据范围
* $1 <= nums.length <= 30$
* $0 <= nums[i] <= 10^4$

### 解法一：状态压缩（超时）
本题大意为将一个数组分成两个平均值相同的数组

我们令两个数组A,B为分完数之后的数组。首先看数据范围，数组的长度 <= 30，说明应该使用暴力算法来枚举，刚好我们可以枚举数组中的每一种状态，每个数只有选和不选两种状态，选这个数就相当于放在A数组中，不选就相当于放到B数组中，然后利用二进制枚举每个数的状态。设原数组元素的数量为 $n$,元素总和为 $tot$ , 放到A数组中的元素数量为 $cnt1$ 个，则B数组中元素的数量为 $n - cnt1$ , A数组的和为 $sum1$ ，B数组的和为 $tot - sum1$ ，那么A数组的平均值就是 $sum1/cnt1$，B数组的平均值为 $sum1/cnt2$ ，最后只要判断两个平均值是否相等即可，这种算法的时间复杂度为 $O(2^n)$ ，会超时。

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

![image](https://user-images.githubusercontent.com/99656524/201564140-e9f21465-ec5d-4b80-8c8d-0ebdae5444c7.png)


### 优化：状态压缩 + 折半枚举
由于要枚举 $2^n$ 个状态，计算量过于庞大，这种数据只要是一点点的优化都会引起质变。我们观察这个推导式，并化简得：
![4fdd55d92b73746428908460f0cbe51](https://user-images.githubusercontent.com/99656524/201564883-fff6c672-d367-4a44-a651-0891c5a92353.jpg)
也就是说，我们需要找到一个子数组和原数组的平均值相等的数组，就可以将数组一分为二，但是计算平均数这种浮点数会有精度问题，我们可以考虑将 $n$移到左边，于是得到

$$
sum1 * n / cnt1 = tot
$$

也就是将数组的全部元素乘以 $n$ 后，找到一个数组的和为 $tot$的子数组，我们再将所有元素减去 $tot$ 也就是 $nums[i] * n - tot = 0$，我们就将问题转化为找一个和为0的子数组了。我们将数组分为两半，枚举前半段，若出现和为0的情况，就说明找到了，否则将数组和放进集合中。枚举后半段，若出现和为0的情况或者 $-sum$ 出现在集合中就说明找到了.

python代码：
```py
class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return False
        s = sum(nums)
        for i, v in enumerate(nums):
            nums[i] = v * n - s
        mid = n >> 1
        vis = set()
        for i in range(1, 1 << mid):
            t = sum(v for j, v in enumerate(nums[:mid]) if i >> j & 1)
            if t == 0:
                return True
            vis.add(t)
        for i in range(1, 1 << (n - mid)):
            t = sum(v for j, v in enumerate(nums[mid:]) if i >> j & 1)
            if t == 0 or (i != (1 << (n - mid)) - 1 and -t in vis):
                return True
        return False
```
* 时间复杂度： $O(2^N)$，其中 $N = n/2$
* 空间复杂度： $O(2^N)$ 

