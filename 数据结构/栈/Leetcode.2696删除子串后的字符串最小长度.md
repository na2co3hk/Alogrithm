### 原题链接 -- [[2696. 删除子串后的字符串最小长度](https://leetcode.cn/problems/lexicographically-smallest-palindrome/)]

### 题目概述：
Tag : 「栈」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/f7a562a0-dc88-444b-8418-e1a492aea5ae)

### 数据范围
* 1 <= s.length <= 100
* s 仅由大写英文字母组成

### 解法一：栈
和括号匹配一样，都是用栈结决组合后删除的问题


C++代码：
```cpp
class Solution {
public:
    int minLength(string s) {
        string stk;
        for(auto a : s)
        {
            stk.push_back(a);
            if(stk.size() >= 2)
            {
                string b = stk.substr(stk.size() - 2, 2);
                if(b == "AB" or b == "CD")stk.erase(stk.end() - 2, stk.end());  
            }
        }
        return stk.size();
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ 
