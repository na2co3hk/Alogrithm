### 原题链接 -- [[2563. 统计公平数对的数目](https://leetcode.cn/problems/count-the-number-of-fair-pairs/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/219923166-c2a99b30-74cb-47b4-ad07-5e5cee403189.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $nums.length == n$
* $-10^9 <= nums[i] <= 10^9$
* $-10^9 <= lower <= upper <= 10^9$

### 解法一：二分查找
题目大意为在数组内找两个数的和在范围之间，我们可以将题目的范围化简成 $[lower - nums[j], upper-nums[j]] $ ，这样相当于将一个点定下来，然后再求另外一个数符合条件的区间，区间内数组元素的个数就是组合的个数。需要求一个数的上下界（范围），并且排序对数组无影响的情况下，可以考虑用排序 + 二分查找求出一个数的上下界。

C++代码：
```cpp
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int j = 0;j < n;j++)
        {
            auto l = lower_bound(nums.begin(), nums.begin()+j, lower-nums[j]);
            auto r = upper_bound(nums.begin(), nums.begin()+j, upper-nums[j]);
            ans += r - l;
        }
        return ans;
    }
};
```
