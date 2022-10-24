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

下面是II题代码，和I题区别就是可以出现了重复数字，必须进行判重操作

C++代码
```cpp
class Solution {
    vector<int> vis;//判重
    
    /* vis[i]：当前数字是否出现过
    * 如果当前数字与前一个数字相同（nums[i] == nums[i - 1]），
    * 并且前一个数字还没有出现的话（vis[i - 1] == false），
    * 那么就不能选择当前数字（continue），
    * 如果前面的数字已经出现过（vis[i] == true），则可以
    * 选择当前数字
    */

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};
```
* 时间复杂度： $O(n*n!)$ 
* 空间复杂度： $O(n)$ 

### 解法二：Next_permulation
在STL的算法中有Next_permulation函数可以求下一个排列，直到全部逆序为止，但是使用前需要先排序，这里直接实现了Next_permulation函数

C++代码：
```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(begin(nums), end(nums));
        do {
            ret.emplace_back(nums);
        } while (Next_permutation(nums));
        return ret;
    }

    bool Next_permutation(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = n - 1;i>=0;i--)
        {
            for(int j = n - 1;j>i;j--)
            {
                if(nums[j]>nums[i])
                {
                    swap(nums[j],nums[i]);
                    reverse(nums.begin()+i+1,nums.end());
                    return true;
                }
            }
        }
        reverse(nums.begin(),nums.end());
        return false;
    }
};
```
