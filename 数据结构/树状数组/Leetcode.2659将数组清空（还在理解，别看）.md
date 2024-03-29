### 原题链接 -- [[2659. 将数组清空](https://leetcode.cn/problems/make-array-empty/)]

### 题目概述：
Tag : 「树状数组」、「排序」、「离散化」

![image](https://user-images.githubusercontent.com/99656524/236623456-b6e86fda-babc-4ff7-a9fc-4df755fc1448.png)

![image](https://user-images.githubusercontent.com/99656524/236623465-b63c9460-7155-40c3-a01c-e7d4f71f223a.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $-10^9 <= nums[i] <= 10^9$

### 解法一：树状数组
题目大意为判断一个队列的首位元素是否为队列中最小的元素，如果是则弹出元素，否则移动到最后，直到队列为空。

从最基础的模拟开始想，用一个队列和堆去模拟这个清空的过程，但是当队列的元素完全逆序的时候，每次取出最小的元素都要 $O(n)$ 的时间复杂度，总体时间复杂度为 $O(n^2)$ ，这对于 $10^5$ 的数据来说是不能接受的。

对于 $10^5$ 的数据，一般是需要用到 $O(nlogn)$ 复杂度的算法，因此我们可以朝二分，树状数组和线段树想。由于在前面中，我们提到了"逆序"这个词，进而可以想到，每次我们需要移动的情况都是移动前面比他大的数字，这似乎有点像逆序对，而逆序对的一个通用的解法就是用树状数组。先对原数组进行一个离散化操作，即用排名代替原数组的位置，然后用树状数组维护被删除了的元素（这样求区间和就可以知道区间已经被删除了的元素的个数），然后再结合当前元素和最小元素的位置之间的元素个数，即可求得每次删除最小元素的移动次数。

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

    void add(int x, int d)
    {
        for(int i = x;i <= n; i += lowbit(i))tree[i] += d;
    }

    int sum(int x)
    {
        int res = 0;
        for(int i = x;i ;i -= lowbit(i))res += tree[i];
        return res;
    }

    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
    long long countOperationsToEmptyArray(vector<int>& nums) {
        n = nums.size();
        vector<int>a(n);
        for(int i = 0;i < n;i++)a[i] = i; //用名次代替
        sort(a.begin(), a.end(), [&](int i,int j)
        {
            return nums[i] < nums[j];
        });
        long long ans = n;
        tree.resize(n + 1);
        int pre = 1; //树状数组下标从1开始
        for(int k = 0;k < n;k++)
        {
            int i = a[k] + 1; //要删除的数
            ans += i >= pre ? i - pre - query(pre, i) : n - pre + i - k + query(i, pre - 1);
            add(i, 1);
            pre = i;
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlogn)$， $O(nlogn)$ 为排序时间复杂度， $O(logn)$ 为树状数组查询操作
* 空间复杂度： $O(n)$ 
