### 原题链接 -- [[33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/201572227-e0f00469-b9ed-46d3-8637-11b7ea68207a.png)

### 数据范围
* $1 <= nums.length <= 5000$
* $-10^4 <= nums[i] <= 10^4$
* $nums 中的每个值都 独一无二$
* $题目数据保证 nums 在预先未知的某个下标上进行了旋转$
* $-10^4 <= target <= 10^4$

### 解法一：二分查找
题目要求 $O(logn)$ 的搜索算法，已经明示了二分查找了，我们要考虑的是怎么在看似无序的区间进行二分查找

对于旋转后的数组，我们可以考虑三个值，分别是数组左右边界和二分查找要用的中点值，我们用nums[0], nums[n-1] ,nums[mid] 表示这三个值，如果nums[0] <= nums[mid] 表示中点值落在了旋转的区间上，mid向左区间搜索时是有序的，向右区间搜索时是无序的，反之则表示中点值落在了原本的升序区间，mid向左区间搜索时时无序的，向右区间搜索时是有序的。简而言之，我们将数组一分为二，两边总有一边是有序的，一边是无序的，若目标值落在有序区间，我们就在有序区间执行二分查找，若目标值落在无序区间，我们继续将数组一分为二，继续得到一个有序区间和无序区间，往复执行之前的步骤最终得到答案。

C++代码：
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0;
        int r = n - 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid]==target)return mid;
            if(nums[0]<=nums[mid]) //mid在旋转区间
            {
                if(nums[mid]>target && nums[0]<=target) //target在有序区间
                {
                    r = mid - 1;
                }
                else //target在无序区间
                {
                    l = mid + 1;
                }
            }
            else //mid在正常升序区间
            {
                if(nums[mid]<target && nums[n - 1]>=target) //target在有序区间
                {
                    l = mid + 1;
                }
                else //target在无序区间
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

python代码：
```py
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l <= r:
            mid = (l + r)//2
            if nums[mid] == target:
                return mid
            if nums[0] <= nums[mid]:
                if nums[0] <= target and target <= nums[mid]:r = mid - 1
                else :l = mid + 1
            else :
                if nums[mid] <= target and target <= nums[n-1]:l = mid + 1
                else :r = mid - 1
        return -1
```
* 时间复杂度： $O(logn)$
* 空间复杂度： $O(1)$
