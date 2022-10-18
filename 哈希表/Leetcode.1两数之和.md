### 原题链接 -- [[1.两数之和](https://leetcode.cn/problems/two-sum/)]

### 题目概述：
Tag : 「暴力」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/196387747-861e15eb-477f-45f8-8bc4-4f4441fa41f6.png)

![image](https://user-images.githubusercontent.com/99656524/196387802-7284024f-4430-4bae-b4dd-6819efb66a87.png)

### 数据范围
* 2 <= nums.length <= 104
* -109 <= nums[i] <= 109
* -109 <= target <= 109
* 只会存在一个有效答案

### 解法一：暴力
两层循环遍历数组，第一层搜索第一个数，第二层搜索第二个数，若等于 $target$ 则直接返回两个数的下标
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
               int length = nums.size();
               for(int i = 0;i<length;++i)
               {
                   for(int j =i+1;j<length;++j)
                   {
                       if(nums[i]+nums[j]==target)
                       {
                            return {i, j};
                       }
                   }
               }
               return {};
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(1)$ 

### 解法二：哈希表
创建一个哈希映射，将已经遍历过的数组元素和下标以 $key-value$ 形式保存下来，若能在映射中找到 $target - num$ 则表示找到了两数之和



