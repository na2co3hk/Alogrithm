### 原题链接 -- [[905. 按奇偶排序数组](https://leetcode.cn/problems/sort-array-by-parity/)]

### 题目概述：
Tag : 「双指针」

![image](https://user-images.githubusercontent.com/99656524/201588038-e58aa9fd-200e-4082-b645-0f06134b29cc.png)

### 数据范围
* 1 <= nums.length <= 5000
* 0 <= nums[i] <= 5000

### 解法一：双指针
根据题意，我们可以用类似于快速排序的方法，一个指针从左往右扫，一个指针从右往左扫，偶数留在左指针部分，奇数留在右指针部分。

C++代码：
```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
          int n = nums.size();
          int left = 0;
          int right = n - 1;
          while(left<right)
          {
              while(left < right && nums[right]%2!=0)
              {
                  right--;
              }
              swap(nums[left],nums[right]);
              while(left < right && nums[left]%2==0)
              {
                  left++;
              }
          }
          return nums;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$
