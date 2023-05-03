### 原题链接 -- [[1003. 检查替换后的词是否有效](https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/)]

### 题目概述：
Tag : 「栈」

![image](https://user-images.githubusercontent.com/99656524/235834488-a60c73ed-6e4d-4618-bbe9-76b55f8c0962.png)

![image](https://user-images.githubusercontent.com/99656524/235834508-26c49f92-7870-479f-a9bd-7d43a458def1.png)

### 数据范围
* $1 <= s.length <= 2 * 10^4$
* $s 由字母 'a'、'b' 和 'c' 组成$

### 解法一：栈
括号匹配的变形，将括号转换成了字母。改一下[括号匹配](https://github.com/na2co3hk/Alogrithm/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%88/Leetcode.20%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.md)的做法即可。

C++代码：
```cpp
class Solution {
public:
    bool isValid(string s) {
        string stk;
        for(auto c : s)
        {
            stk.push_back(c);
            if(stk.size() >= 3 and stk.substr(stk.size() - 3, 3) == "abc")
                    stk.erase(stk.end() - 3, stk.end());
        }
        return stk.empty();
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用栈
