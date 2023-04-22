### 原题链接 -- [[1027. 最长等差数列](https://leetcode.cn/problems/longest-arithmetic-subsequence/)]

### 题目概述：
Tag : 「动态规划」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/233753496-92c54166-93c6-4af8-9cca-c8e091dec0e1.png)

### 数据范围
* 2 <= nums.length <= 1000
* 0 <= nums[i] <= 500

### 解法一：动态规划
本题和最长上升子序列的模板一样，不过需要考虑的变量还多了一个公差，因此状态定义为考虑前i个数，公差为j的最长等差子序列。

C++代码：
```cpp
class Solution {
public:
    const int d = 1000; //因为公差有负数，需要加上一个offset使得下标都为正
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        //考虑前i个数，公差为j的最长等差子序列长度
        vector<vector<int>>f(n + 1, vector<int>(2*d));
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < i;j++) //a[1] - a[0]先判断,因此下标从0开始
            {
                int diff = nums[i] - nums[j] + d;
                f[i][diff] = f[j][diff] + 1;
                mx = max(mx, f[i][diff]);
            }
        }
        return mx + 1; //每个元素单独都是公差为0的等差数列
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n^2)$ 
