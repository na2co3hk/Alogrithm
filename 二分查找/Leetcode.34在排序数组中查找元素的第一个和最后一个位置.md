### 原题链接 -- [[34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/201576903-a14a3f7c-420d-4f21-bba5-61b915039c8a.png)

### 数据范围
* $0 <= nums.length <= 10^5$
* $-10^9 <= nums[i] <= 10^9$
* $nums 是一个非递减数组$
* $-10^9 <= target <= 10^9$

### 解法一：二分查找
题目明示用二分查找，然后就是二分查找找上下界的问题，部分语言可以用自带的二分查找函数，具体看二分查找模板

C++代码：
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin(); //>=x
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin(); // >x
        if(l == n || nums[l]!=target)return {-1, -1};
        else return {l, r-1};// >=x and <=x
    }
};
```

python代码：
```py
class Solution(object):
    def searchRange(self,nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def left_func(nums,target): # >= x的最小下标
            n = len(nums)-1
            left = 0
            right = n
            while(left<=right):
                mid = (left+right)//2
                if nums[mid] >= target:
                    right = mid-1
                if nums[mid] < target:
                    left = mid+1
            return left
        a =  left_func(nums,target)
        b = left_func(nums,target+1) # > x的最小下标
        if  a == len(nums) or nums[a] != target: 
            return [-1,-1]
        else:
            return [a,b-1] #-1变成 <= x的最大下标
```
* 时间复杂度： $O(logn)$
* 空间复杂度： $O(1)$
