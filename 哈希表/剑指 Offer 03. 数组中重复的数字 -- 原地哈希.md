### 原题链接 -- [[剑指 Offer 03. 数组中重复的数字](https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)]

### 题目概述：
Tag : 「哈希表」

![image](https://user-images.githubusercontent.com/99656524/227964421-0065c1d7-f823-4c4b-ae80-a5a11669498b.png)

### 数据范围
* 2 <= n <= 100000

### 解法一：哈希表
由于题目数组中数字的范围只有 0 ~ n - 1，而数组长度是n，因此我们可以将数组元素作为下标，并与当前位置交换（相当于放回了原来的位置，如nums[3] = 3），如果在过程中遇到了已经放回原来
数组的数字（已经有人回到了对的位置），那说明该元素就是重复的数字。

C++代码:
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i]==i)
            {
                i++;
                continue;//恢复到了自己对应的下标
            }

            if(nums[nums[i]]==nums[i])return nums[i]; //已经有人回到了对的位置
            swap(nums[nums[i]],nums[i]); //恢复到原来的下标
        }
        return -1;
    }
};
```
* 时间复杂度： $O(n)$ 
* 空间复杂度： $O(1)$ 
