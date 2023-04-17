### 原题链接 -- [[1679. K 和数对的最大数目](https://leetcode.cn/problems/max-number-of-k-sum-pairs/)]

### 题目概述：
Tag : 「双指针」

![image](https://user-images.githubusercontent.com/99656524/232378490-a311418f-d8d7-4092-8a2b-4d686f20b092.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^9$
* $1 <= k <= 10^9$

### 解法一：双指针
进化版的两数之和，因为答案和顺序无关可以先排个序，而两个数之和等于k的组合是唯一的，我们只需要用两个指针的和来和k对比，若比k大，则左移右指针，使两数之和变小，若比k小则右移左指针使两数之和变大，直到两数之和等于k。

C++代码：
```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1, ans = 0;
        while(l < r)
        {
            int s = nums[l] + nums[r];
            if(s > k)r--;
            else if(s == k)
            {
                ans++;
                l++;
                r--;
            }
            else if(s < k)l++;
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlogn)$ ，主要为排序的时间复杂度
* 空间复杂度： $O(1)$
