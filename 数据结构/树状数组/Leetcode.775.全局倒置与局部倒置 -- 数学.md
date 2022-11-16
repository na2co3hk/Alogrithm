### 原题链接 -- [[775. 全局倒置与局部倒置](https://leetcode.cn/problems/global-and-local-inversions/)]

### 题目概述：
Tag : 「树状数组」、「数学」

![image](https://user-images.githubusercontent.com/99656524/202175371-6b02cf86-0abf-411e-bd57-22e83e0e6e9e.png)

### 数据范围
* $n == nums.length$
* $1 <= n <= 10^5$
* $0 <= nums[i] < n$
* $nums 中的所有整数 互不相同$
* $nums 是范围 [0, n - 1] 内所有数字组成的一个排列$

### 解法一：树状数组
这道题跟我们之前分析的逆序对问题是一样的，全局倒置就是逆序对，局部倒置就是在相领位置的逆序对，所以我们也可以用逆序对的分析方法去做这道题。我们用树状数组记录下每个数记录的出现次数（这里有点像计数排序），用前缀和维护小于 $nums[i]$ 的元素个数。由于这道题规定了每个数都在[1,n-1]的范围内，所以我们既不用离散化也不用逆序遍历，直接正常遍历后，第i个数表示本该有i个数, 小于 $nums[i]$ 的有 $sum[nums[i]]$ 个数，我们直接用这两个数相减就得到了大于 $nums[i]$ 的个数，然后再在遍历的过程中判断相领位置是否有逆序对即可。

* 疑点:为什么加数的时候都要 +1 ：因为树状数组的下标必须要从1开始才能进行lowbit操作，+1可以让所有下标都对其（查询也是一样的）

C++代码：
```cpp
class Solution {
public:
    using int64 = long long ;
    int n;
    vector<int>tree;
    int lowbit(int x)
    {
        return x & -x;
    }
    void add(int x, int d)
    {
        for(int i =  x;i <= n;i += lowbit(i))tree[i] += d;
    }

    int sum(int x)
    {
        int res = 0;
        for(int i = x;i;i -= lowbit(i))res += tree[i];
        return res;
    }
    bool isIdealPermutation(vector<int>& nums) {
        n = nums.size();
        tree.resize(n + 10);
        int64 sta = 0, par = 0;
        add(nums[0] + 1, 1); //疑点1
        for(int i = 1;i < n;i++)
        {
            sta += i - sum(nums[i] + 1); //sum(n) == i
            par += nums[i] < nums[i-1] ? 1 : 0;
            add(nums[i] + 1, 1);
        }
        return sta == par;
    }
};
```
* 时间复杂度： $O(nlog)$
* 空间复杂度： $O(n)$

### 解法二：数学
其实本题有个比较简单的想法，由于局部倒置属于全部倒置，局部倒置不包含全局倒置，所以必须要所有全局倒置都是局部倒置才能使全部倒置和局部倒置的数量相等，而要想判断是不是局部倒置，我们可以算一下他到他本来下标的距离，如果距离 <= 1就代表是局部倒置，> 2 则说明是全局倒置单不是局部倒置。

C++代码:
```cpp
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++)if(abs(nums[i] - i ) >= 2)return false;
        return true;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$
