### 原题链接 -- [[915. 分割数组](https://leetcode.cn/problems/partition-array-into-disjoint-intervals/)]

### 题目概述：
Tag : 「模拟」

![image](https://user-images.githubusercontent.com/99656524/197453690-07e803df-d7f3-41a4-a98b-212ac68dce2a.png)

### 数据范围
* $2 <= nums.length <= 10^5$
* $0 <= nums[i] <= 10^6$
* $可以保证至少有一种方法能够按题目所描述的那样对 nums 进行划分。$

### 解法一：两次遍历
根据题意模拟，要想找到数组的分割点，就需要找出左数组的最大值和右数组最小值的交界点，我们可以先定义一个数组 $mi$ 来记录右边数组的最小值，然后从后往前遍历，在用一个变量 $mx$记录左边数组的最大值，从前往后遍历，然后找到 $mi$ >= $mx$ 的位置，即是答案

C++代码：
```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>mi(n + 1,INT_MAX);
        for(int i = n - 1;~i;i--)mi[i] = min(nums[i],mi[i + 1]); // 相当于i>=0,当i = -1时，i的二进制代码为全1，取反后等于0
        int mx = 0;
        for(int i = 1;i <= n;i++)
        {
            mx = max(mx, nums[i - 1]);
            if(mx <= mi[i])return i;
        }
        return 0;
    }
};
```
* 时间复杂度： $O(n)$，两次遍历时间都是 $O(n)$
* 空间复杂度： $O(n)$ 

### 解法二：一次遍历
其实我们也可以用一次遍历的方法解决这个问题，我们先设定几个变量 minidx, maxidx, max代表左边数组的边界和右边数组的边界以及左边数组的最大值，注意，这里的最大值并非是整个数组的最大值，而是相对于左边数组的最大值而已

C++代码：
```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int minidx = 0, maxidx = 0, max = nums[0];//分别代表左边数组下标，右边数组下标，左边最大值
        for(int i = 0;i < n;i++)
        {
             //如果遇到比最大值还大的，记下 遇到的最大值的下标
            if(nums[i]>=max)maxidx = nums[i] > nums[maxidx] ? i : maxidx;
            else
            {
                //如果在右边遇到比最大值小的，更新最小值指针，同时将左边最大值更新
                minidx = i;
                max = nums[maxidx];
            }
        }
        return minidx + 1;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$
