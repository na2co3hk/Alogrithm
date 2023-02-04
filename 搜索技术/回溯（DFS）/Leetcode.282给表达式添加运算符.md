### 原题链接 -- [[282. 给表达式添加运算符](https://leetcode.cn/problems/expression-add-operators/)]

### 题目概述：
Tag : 「回溯」、「深度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/216761671-83a25349-2101-4cea-a29a-0dcb85f4feb7.png)

### 数据范围
* 1 <= num.length <= 10
* num 仅含数字
* -2^31 <= target <= 2^31 - 1

### 解法一：回溯
根据题意，我们需要用不同的符号组成 $target$，只需要将 "+" "-" "x" 三种符号排列组合即可，也就是回溯

C++代码：
```cpp
class Solution {
public:
    vector<string>res;
    int n;
    int target_;
    string num_;
    vector<string> addOperators(string num, int target) {
        num_ = num;
        n = num.size();
        target_ = target;
        dfs(0, 0, 0, "");
        return res;
    }

    void dfs(int l, long long pre, long long sum, string p)
    {
        if(l == n)
        {
            if(target_ == sum)res.push_back(p);
            return ;
        }

        long long val = 0;
        for(int i = l; i < n; i++)
        {
            if(i!=l && num_[l]=='0')break;//不能有前导0
            val = val*10 + num_[i]-'0';
            if(l == 0)dfs(i + 1, val, val, to_string(val));
            else
            {
                dfs(i + 1, pre*val, sum-pre+pre*val, p+'*'+to_string(val));
                dfs(i + 1,val, sum + val, p+'+'+to_string(val));
                dfs(i + 1,-val, sum - val, p+'-'+to_string(val));
            }
        }
    }
};
```
* 时间复杂度： $O(4^n)$ 
* 空间复杂度： $O(n)$ 

