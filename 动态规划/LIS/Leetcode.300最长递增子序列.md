### 原题链接 -- [[300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)]

### 题目概述：
Tag : 「动态规划」、「二分查找」

![image](https://user-images.githubusercontent.com/99656524/226795988-95c69b4e-ca01-47b7-819b-a8f93e8a6ae8.png)

### 数据范围
* $1 <= nums.length <= 2500$
* $-10^4 <= nums[i] <= 10^4$

### 解法一：动态规划
题目大意为找到一个最大长度的上升子序列。由于数组中的每个元素只有选和不选两种状态，并且每一次的选择和上一次的选择有关，我们考虑用动态规划去解决。先将数组全部初始化成1，因为每个子数组都是一个长度为1的子序列。由于是线性DP，可以考虑用两个指针去遍历数组，一个指针向前一个指针向后，如果向前指针的值大于向后指针的值时，说明向前的指针可以作为上升序列的一个元素，因此长度+1。不断循环求最大值，这样我们就可以得到递推公式

%%
  f[i] = max(f[i], f[j]+1)
%%

其中f[i]为向前的指针，f[j]为向后的指针

C++代码：
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = 1;
        for(int i = 0;i < n;i++)
        {
            dp[i]=1;
            for(int j = 0;j < i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n^2)$ 
