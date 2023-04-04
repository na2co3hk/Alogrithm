### 原题链接 -- [[15. 三数之和](https://leetcode.cn/problems/3sum/)]

### 题目概述：
Tag : 「双指针」、「排序」

![image](https://user-images.githubusercontent.com/99656524/229812545-581435e9-2de1-47c9-9ab6-708e67c28b82.png)

![image](https://user-images.githubusercontent.com/99656524/229812597-f63e8ad3-94a7-42c0-b16e-51dbc76ddd46.png)

### 数据范围
* $3 <= nums.length <= 3000$
* $-10^5 <= nums[i] <= 10^5$

### 解法一：双指针
本题为两数之和的进阶版，三个数需要三重循环，然而对于 $10^3$ 来说是无法接受的，我们需要用算法进行优化。由于数组元素的顺序和答案无关，只需要保证取三个数各不相同，我们可以先对数组进行排序，排完序后就可以利用有序这个性质解决问题。在有序的情况下优化多重循环，首先想到的应该是双指针，我们可以先将一个指针定下来，剩下只有两个指针需要选择，将指针放置在第一个指针的位置和数组最右边的位置。由于三个数的和等于目标值 $target$ ，我们可以根据三数之和与目标值大小来调整指针的方向，若算得三数之和比目标值大，根据数组有序的性质，我们只需要将右指针向左移（从小到大排序，右指针左移会变小），若比目标值小，则将左指针右移。

python代码：
```py
class Solution:
    def threeSum(self, nums: [int]) -> [[int]]:
        nums.sort()
        res, k = [], 0
        for k in range(len(nums) - 2): #定住一个k，然后剩下两个指针向同一个方向移动
            if nums[k] > 0: break # 1. because of j > i > k.
            if k > 0 and nums[k] == nums[k - 1]: continue # 2. skip the same `nums[k]`.
            i, j = k + 1, len(nums) - 1
            while i < j: # 3. double pointer
                s = nums[k] + nums[i] + nums[j]
                if s < 0:
                    i += 1
                    while i < j and nums[i] == nums[i - 1]: i += 1
                elif s > 0:
                    j -= 1
                    while i < j and nums[j] == nums[j + 1]: j -= 1
                else:
                    res.append([nums[k], nums[i], nums[j]]) #等于target，记录答案并将左右指针同时移动
                    i += 1
                    j -= 1
                    while i < j and nums[i] == nums[i - 1]: i += 1
                    while i < j and nums[j] == nums[j + 1]: j -= 1
        return res
```
* 时间复杂度： $O(n^2)$
* 空间复杂度： $O(1)$ 
