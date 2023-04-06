### 原题链接 -- [[剑指 Offer 51. 数组中的逆序对](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)]

### 题目概述：
Tag : 「树状数组」、「排序」、「离散化」

![image](https://user-images.githubusercontent.com/99656524/201452385-f2346071-7ceb-4ccd-a1b0-c7e8dccb78e6.png)

### 数据范围
* $0 <= 数组长度 <= 50000$

本题还有其他解法，等待学会后更新

### 解法一：树状数组+离散化
本题是树状数组入门题，可以通过这道题来熟悉树状数组这种数据结构。

题目大意为找到数组中每个数的逆序对总和，逆序对可以理解为 $a[i] < a[j]$ 且 $i > j$ 。先从暴力的角度来看一下这题，我们可以用两层循环，第一层枚举数组元素，第二层枚举数组左边的元素，若比当前数组元素大，则加1，不断记录左边比当前元素大的个数。但是两层循环需要 $O(n^2)$ 的复杂度，这样的复杂对对于 $10^4$ 的数据是不能接受的。因此我们需要数据结构去优化这个记录的过程。由于提到了数组和，我们应该会先想到前缀和，我们可以将所有数出现的次数记录到一个数组里，数值从小到大排序，这样数组里每个元素的左边代表比自己小的元素出现的次数，右边代表比自己大的元素出现的次数，可以看出来用普通数组是不行的，因为每个数值可能会相差很大，造成不必要的空间浪费。我们对原数组进行离散化操作就能解决这个问题。

不难看出，对离散化后的数组的每个数求前缀和就是每个数左边比当前元素小的个数，我们逆序遍历数组，得到的前缀和就是每个数比左边比当前元素大的个数了，但是我们需要动态的添加元素来模拟数组的先后顺序，也就是动态维护数组前缀和，普通前缀和无法做到这一点，这就要用到更高级的树状数组和线段树了。我们用树状数组的 $add(nums[i], 1)$ 操作添加数并且统计出现次数，用 $query(nums[i]-1)$ 操作求比nums[i]大（并且比nums[i]先出现）的元素个数，然后对每个元素的前缀和求和即可得到逆序对的个数。

疑点：
* 为什么 $query(nums[i]-1)$ 中要-1？ ：因为 $query(nums[i])$ 求的是到nums[i]的前缀和，而-1操作后就变成了求大于（本题逆序遍历，这里变成了求大于，本来应该是求小于nums[i]的前缀和）nums[i]的前缀和 

C++代码：
```cpp
class Solution {
public:
    int n;
    vector<int>tree;
    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int x,int d)
    {
        for(int i = x; i <= n; i += lowbit(i))tree[i] += d;
    }

    int sum(int x)
    {
        int res = 0;
        for(int i = x;i;i -= lowbit(i))res += tree[i];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        tree.resize(n + 5);
        int ans = 0;
        vector<int>b(nums);
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(auto& x : nums)x = lower_bound(b.begin(),b.end(),x)-b.begin() + 1; 
        for(int i = n - 1;i >= 0;i--)
        {            
            ans += sum(nums[i]-1); //疑点2
            add(nums[i], 1);
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlogn)$，$O(nlogn)$为排序和二分的时间复杂度，$O(logn)$ 为树状数组查询操作
* 空间复杂度： $O(n)$ 

 
