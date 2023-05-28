### 原题链接 -- [[2560. 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv/)]

### 题目概述：
Tag : 「二分查找」、「动态规划」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/25bfe8da-7f20-453b-aa9f-6319bd052250)

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/332ab9dd-eb5f-445a-b279-767074131214)

### 数据范围
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^9$
* $1 <= k <= (nums.length + 1)/2$

### 解法一：动态规划 + 二分查找
从题目不难看出来，这是一道二分答案题目，最小化最大值是二分答案的代名词。此外，打家劫舍的常规解法是用动态规划，动态规划的状态定义为f[i]，其中f[i]为第i个房子抢或不抢时能获得的最大价值。

C++代码：
```cpp
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        vector<int>dp(n + 2);
        while(l < r)
        {
            int mid = (l + r) >> 1;
            for(int i = 2;i <= n + 1;i++)
            {
                if(nums[i-2] <= mid)dp[i] = max(dp[i-1], dp[i-2] + 1);
                else dp[i] = dp[i-1];
            }

            if(dp[n + 1] >= k)r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
```
* 时间复杂度： $O(nlogU)$ ，其中U为数组中的最大值 
* 空间复杂度： $O(n)$
