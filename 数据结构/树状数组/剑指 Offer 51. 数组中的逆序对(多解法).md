### 原题链接 -- [[剑指 Offer 51. 数组中的逆序对](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)]

### 题目概述：
Tag : 「树状数组」、「排序」、「离散化」

![image](https://user-images.githubusercontent.com/99656524/201452385-f2346071-7ceb-4ccd-a1b0-c7e8dccb78e6.png)

### 数据范围
* $0 <= 数组长度 <= 50000$

本题还有其他解法，等待学会后更新

### 解法一：树状数组+离散化
本题是树状数组入门题，可以通过这道题来熟悉树状数组这种数据结构。

题目大意为找到数组中每个数的逆序对总和，逆序对可以理解为 $a[i] < a[j]$ 且 $i > j$ 。先从暴力的角度来看一下这题，我们可以用两层循环，第一层枚举数组元素，第二层枚举数组左边的元素，若比当前数组元素大，则加1，不断记录左边比当前元素大的个数。但是两层循环需要 $O(n^2)$ 的复杂度，这样的复杂对对于 $10^4$ 的数据是不能接受的。因此我们需要数据结构去优化这个记录的过程。由于提到了数组和，我们应该会先想到前缀和，我们可以将左边比自己大的数的个数记录到一个数组里，然后动态维护这个数组的前缀和。而普通前缀和不能及时地记录和查询左边比自己大的数，所以我们只能用更高级的树状数组和线段树。树状数组的两个操作 $add$ 和 $query$ 刚好非常适合记录和查询这两个功能， 我们记nums[i]是当前遍历到的元素， $add(nums[i], 1)$操作相当于让数组中所有大于nums[i]的所有数++，然后用 %query% 操作记录 nums[i] 的前缀和 ，这里有个细节，用$query(nums[i]-1)$ 代表左边比nums[i]小的数元素的个数，我们逆序遍历数组，就可以让   $query(nums[i]-1)$ 操作记录左边比nums[i]大的元素的个数，最后将他们累加起来就能得出答案。需要注意的是，数据可能会太过于分散，开数组空间消耗过大，我们需要用离散化操作将原本的数值映射到只有n个元素大小的空间。

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
        for(auto& x : nums)x = lower_bound(b.begin(),b.end(),x)-b.begin() + 1; //疑点1
        for(int i = n - 1;i >= 0;i--)
        {            
            ans += sum(nums[i]-1); //疑点2
            add(nums[i], 1);
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlogn)$，$O(nlogn)$为排序和二分的时间复杂度，$O(logn)$为树状数组查询操作
* 空间复杂度： $O(n)$ 

 
