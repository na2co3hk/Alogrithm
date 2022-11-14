### 原题链接 -- [[33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/)]

### 题目概述：
Tag : 「二分查找」、「滑动窗口」、「前缀和」

![image](https://user-images.githubusercontent.com/99656524/201601720-26c07f3b-4164-4ac3-825a-2e813e4e9d00.png)

### 数据范围
* $1 <= target <= 10^9$
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^5$

### 解法一：滑动窗口
根据题意，我们需要找到一段连续的区间，其区间和大于 $target$ ，一想到区间和我们应该要想到前缀和，连续区间我们可以考虑用滑动窗口，这里先讲一下滑动窗口的解法。关于滑动窗口的机制可以去看第三题的题解。

python代码：
```py
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        inf = 10**5+10
        n, l, r, ans, tot = len(nums), 0, 0, inf, 0
        while r < n:
            tot += nums[r]
            while tot >= target:
                ans = min(ans, r - l + 1)
                tot -= nums[l]
                l += 1
            r += 1
        return ans if ans != inf else 0
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$ 

### 解法二：前缀和+二分查找
我们可以求数组的前缀和，然后二重循环枚举左右端点，但是这样太慢了。由于数组全是正整数，其前缀和满足单调条件，我们可以用二分查找枚举其中一个端点。

我们需要找到一个区间 $sum[r] - sum[l-1] >= target$ ，移项一下： $sum[r] >= target + sum[l-i]$ ,利用 >= 类的二分查找模板枚举右端点即可

C++代码：
```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int>sum(n+1, 0);
        for(int i = 1;i <= n;i++)sum[i] = sum[i-1] + nums[i-1];
        for(int l = 1;l <= n;l++)
        {
            int sumr = target + sum[l-1];
            int r = lower_bound(sum.begin(), sum.end(), sumr) - sum.begin();
            if(r!=n+1)ans = min(ans, r - l + 1);
        }
        return ans != INT_MAX ? ans : 0;
    }
};
```
* 时间复杂度： $O(nlogm)$，二分logn * 枚举左端点n
* 空间复杂度： $O(n)$，前缀和 



