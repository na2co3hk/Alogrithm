### 原题链接 -- [[2426. 满足不等式的数对数目](https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/)]

### 题目概述：
Tag : 「树状数组」、「排序」、「离散化」

![image](https://user-images.githubusercontent.com/99656524/230422348-e5f8ea43-8fb9-409d-9db7-d4cf48562538.png)

### 数据范围
* $n == nums1.length == nums2.length$
* $2 <= n <= 10^5$
* $-10^4 <= nums1[i], nums2[i] <= 10^4$
* $-10^4 <= diff <= 10^4$

### 解法一：树状数组
本题和[逆序对](https://github.com/na2co3hk/Alogrithm/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84/%E5%89%91%E6%8C%87%20Offer%2051.%20%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%80%86%E5%BA%8F%E5%AF%B9(%E5%A4%9A%E8%A7%A3%E6%B3%95).md)的做法一致，有什么不懂的可以先看看逆序对怎么做

题目的条件可以转换为 $nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff$ ，设 $nums1[i] - nums2[i]$ 为一个新的组合 $nums[i]$ ，这样原式就变成了 $nums[i] <= nums[j] + diff$ 。而题目要求了 $i <= j$ ，就相当于求"顺序对"的个数（其实没有这个定义，自己乱说的哈哈），即数组从小到大排列的数对数。剩下的就和逆序对的做法差不多，值得一提的是本题数组元素的范围是 $10^4$ ，比 $n$ 要小，是不用进行离散化的（当然离散化也没错，而且代码就是用离散化做的），以及本题不用和逆序对一样逆序求前缀和，因为本题是求"顺序对"，若 $i <= j && nums[i] <= nums[j]$ ，则i必然在树状数组中j的左边，统计j左边元素的前缀和即可（寻找j的下标用二分进行优化，因为树状数组已经是有序的了）。

C++代码：
```cpp
class Solution {
public:
    using i64 = long long;
    int n;
    vector<int>tree;
    int lowbit(int x)
    {
        return x & -x;
    }
    void add(int x, int d)
    {
        for(int i = x;i <= n; i += lowbit(i))tree[i] += d;
    }
    i64 sum(int x)
    {
        int res = 0;
        for(int i = x;i; i -= lowbit(i))res += tree[i];
        return res;
    }
    i64 numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        n = nums1.size();
        vector<int>nums(n);
        for(int i = 0 ;i < n;i++)nums[i] = (nums1[i] - nums2[i]);
        tree.resize(n + 5);
        i64 ans = 0L;
        vector<int>b(nums);
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for(int x : nums)
        {
            ans += sum(upper_bound(b.begin(), b.end(), x + diff) - b.begin());
            add(lower_bound(b.begin(), b.end(), x) - b.begin() + 1, 1);
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlogn)$， $O(nlogn)$ 为排序和二分的时间复杂度， $O(logn)$ 为树状数组查询操作
* 空间复杂度： $O(n)$ 

 
