### 原题链接 -- [[18. 四数之和](https://leetcode.cn/problems/4sum/)]

### 题目概述：
Tag : 「双指针」

![image](https://user-images.githubusercontent.com/99656524/229824244-8cb0de49-40b2-4c7a-b988-30ba38098ce4.png)

### 数据范围
* $1 <= nums.length <= 200$
* $-10^9 <= nums[i] <= 10^9$
* $-10^9 <= target <= 10^9$

### 解法一：双指针
和[三数之和](https://github.com/na2co3hk/Alogrithm/blob/main/%E5%8F%8C%E6%8C%87%E9%92%88/%E7%9B%B8%E5%90%91%E5%8F%8C%E6%8C%87%E9%92%88/Leetcode.15%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md)解法一致，只需要再加一层循环枚举一个指针即可

```py
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans = set()
        for i in range(n - 3):
            for j in range(i + 1, n - 2):
                x = j + 1
                y = n - 1
                pre = nums[i] + nums[j]
                while x < y:
                    cur = pre + nums[x] + nums[y]
                    if cur == target:
                        ans.add((nums[i], nums[j], nums[x], nums[y]))
                        x += 1
                        y -= 1
                    elif cur > target:
                        y -= 1
                    else:
                        x += 1
        return [list(a) for a in ans]
```
* 时间复杂度： $O(n^3)$
* 空间复杂度： $O(1)$ ， 取决于排序是否使用额外空间 
