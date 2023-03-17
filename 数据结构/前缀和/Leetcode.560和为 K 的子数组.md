### 原题链接 -- [[560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)]

### 题目概述：
Tag : 「前缀和」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/225880858-6d6665a5-1647-4f0b-96b7-998c10a0f025.png)

### 数据范围
* $1 <= nums.length <= 2 * 10^4$
* $-1000 <= nums[i] <= 1000$
* $-10^7 <= k <= 10^7$

### 解法一：前缀和 + 哈希表
题目可以转换为求区间和为k的子数组数目，而区间和可以转换为两个前缀和的差，而两个数的差等于目标值，是不是听着有点耳熟？没有的话就赶紧复习一下[两数之和](https://github.com/na2co3hk/Alogrithm/blob/main/%E5%93%88%E5%B8%8C%E8%A1%A8/Leetcode.1%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md)吧！

C++代码：
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n + 1);
        for(int i = 1;i <= n;i++)pre[i] = pre[i-1] + nums[i-1];
        int cnt = 0;
        unordered_map<int, int>hash;
        for(int i = 0;i <= n;i++)
        {
            auto it = hash.find(pre[i] - k);
            if(it != hash.end())cnt += it->second;//疑点
            hash[pre[i]] += 1;
        }
        return cnt;
    }
};
```
* 时间复杂度： $O(n)$ 
* 空间复杂度： $O(n)$ 
