### 原题链接 -- [[41. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/)]

### 题目概述：
Tag : 「哈希表」

![image](https://user-images.githubusercontent.com/99656524/227960576-aa05f8e4-df0d-4a48-996d-d39e85b59811.png)

### 数据范围
* 1 <= nums.length <= 5 * 105
* -2的31次方 <= nums[i] <= 2的31次方 - 1

### 解法一：哈希表
根据题目不难想到用哈希表来记录是否出现对应数字，但是如此之大的数据范围并不好处理。因此我们可以利用原数组作为哈希表，数组元素的每一个数都有其对应本身的下标，除了没出现的那个数字。因此我们只需要把n个数组元素恢复至其原来的下标（nums[nums[i] - 1] = nums[i]），然后再从小到大遍历一遍即可知道缺失的第一个正数。

C++代码：
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```
* 时间复杂度： $O(n)$ ，两次遍历都是 $O(n)$
* 空间复杂度： $O(1)$ 
