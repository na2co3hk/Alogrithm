### 原题链接 -- [[20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)]

### 题目概述：
Tag : 「单调栈」

![image](https://user-images.githubusercontent.com/99656524/235833763-39d925e4-6feb-427e-8f51-bf944d173bd0.png)

### 数据范围
* $1 <= s.length <= 104$
* $s 仅由括号 '()[]{}' 组成$

### 解法一：栈
括号匹配就是栈的代名词，每次取出两个栈顶元素，查看是否匹配，若匹配则出栈，最后统计栈是否为空即可。

C++代码：
```cpp
class Solution {
public:
    unordered_set<string>bracket{
        "()", "[]", "{}"
    };
    bool isValid(string s) {
        string stk;
        for(auto c : s)
        {
            stk.push_back(c);
            if(stk.size() >= 2)
            {
                string b = stk.substr(stk.size() - 2, 2);
                if(bracket.count(b))stk.erase(stk.end() - 2, stk.end());
            }
        }
        return stk.empty();
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n + C)$ ,C = 6
