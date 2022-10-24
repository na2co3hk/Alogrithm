### 原题链接 -- [[46. 全排列](https://leetcode.cn/problems/permutations/)][[47. 全排列 II](https://leetcode.cn/problems/permutations-ii/)]

### 题目概述：
Tag : 「回溯」、「深度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/197556303-cd0efcf8-bcd3-4478-a5f5-88f1f83f0c87.png)

### 数据范围
* 1 <= nums.length <= 6
* -10 <= nums[i] <= 10
* nums 中的所有整数 互不相同

![image](https://user-images.githubusercontent.com/99656524/197556344-e5e694c7-b5f2-4554-89eb-a4caa7b467d1.png)

### 数据范围
* 1 <= nums.length <= 8
* -10 <= nums[i] <= 10

### 解法一：回溯
根据题意，我们可以填数字的时候回溯，枚举每一种填法，若每个数都填完了，就直接返回，并撤回操作，填下一个数字，直到全部排列完成
C++代码：
```cpp
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
```
* 时间复杂度： $O(n*n!)$ 
* 空间复杂度： $O(n)$ 
