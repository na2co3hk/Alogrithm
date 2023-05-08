### 原题链接 -- [[327. 区间和的个数](https://leetcode.cn/problems/count-of-range-sum/)]

### 题目概述：
Tag : 「树状数组」、「线段树」、「离散化」

![image](https://user-images.githubusercontent.com/99656524/236738297-5b90779e-3688-4d35-8ce3-92e2d05cb7d1.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $-2^31 <= nums[i] <= 2^31 - 1$
* $-10^5 <= lower <= upper <= 10^5$
* $题目数据保证答案是一个 32 位 的整数$

### 解法一：树状数组
题目大意为求区间和在[lower, upper] 的数目。由于题目提到了区间和，就不得不想到前缀和了，用 $pre[i]$ 表示下标i的前缀和， 则题目描述可以转化为

$$
lower <= pre[r] - pre[l] <= upper 
$$

移相，两边添加符号得

$$
pre[r] - upper <= pre[l] <= pre[r] - lower
$$

这样题目就转化为了pre[l]在区间[pre[r] - upper, pre[r] - lower]出现的次数，我们用一个数组统计pre[l]在下标l前出现的次数，求区间和就是pre[l]的出现次数，而求区间和常用的就是树状数组和线段树，下面是树状数组的做法。（另外，由于本题区间过大，需要用到哈希集合将可能出现的所有数据离散化，再用哈希表映射到离散化后的值中）

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

    void add(int x,int d)
    {
        for(int i = x;i <= n;i += lowbit(i))tree[i] += d;
    }

    int sum(int x)
    {
        int res = 0;
        for(int i = x;i ; i -= lowbit(i))res += tree[i];
        return res;        
    }

    int range(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n = nums.size();
        vector<i64>pre(n + 1);
        for(int i = 1; i <= n ; i++)pre[i] = pre[i-1] + nums[i-1];

        //统计所有可能出现的数字，用于离散化到这些数字里
        set<i64>allNumbers;
        for(i64 x : pre)
        {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }

        //哈希表紧离散
        unordered_map<i64, int>val;
        int idx = 1; //下标从1开始，与树状数组对应
        for(i64 x : allNumbers)val[x] = idx++;

        int ans = 0;
        tree.resize(val.size() + 1);
        n = val.size();
        for(int i = 0; i < pre.size() ;i++)
        {
            int l = val[pre[i] - upper], r = val[pre[i] - lower];
            ans += range(l, r);
            add(val[pre[i]], 1); //离散化下标从0开始，树状数组下标从1开始，所以要+1
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlogn)$ 
* 空间复杂度： $O(n)$
