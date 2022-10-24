### 原题链接 -- [[915. 分割数组](https://leetcode.cn/problems/partition-array-into-disjoint-intervals/)]

### 题目概述：
Tag : 「模拟」

![image](https://user-images.githubusercontent.com/99656524/197453690-07e803df-d7f3-41a4-a98b-212ac68dce2a.png)

### 数据范围
* $2 <= nums.length <= 10^5$
* $0 <= nums[i] <= 10^6$
* $可以保证至少有一种方法能够按题目所描述的那样对 nums 进行划分。$

### 解法一：遍历
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
