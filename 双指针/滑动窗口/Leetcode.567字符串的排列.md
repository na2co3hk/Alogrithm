### 原题链接 -- [[567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/)]

### 题目概述：
Tag : 「滑动窗口」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/227968582-e6484cad-0305-46ea-a431-36bd6a180118.png)

### 数据范围
* 1 <= s1.length, s2.length <= 104
* s1 和 s2 仅包含小写字母

### 解法一：滑动窗口 + 哈希表
题目要求在s2中找一个包含s1排列的字串，由于连续且字串长度必须要与s1相等，可以考虑用滑动窗口寻找，并用哈希表记录是否出现s1中的所有字符。由于长度与s1相同，每次移动窗口大小不变。

C++代码：
```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int l = 0, r = m;
        vector<int> cnt1(26), cnt2(26);
        if(m > n)return false;
        for(int i = 0;i < m;i++)
        {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if(cnt1 == cnt2)return true;
        while(r < n)
        {
            cnt2[s2[r] - 'a'] += 1;
            cnt2[s2[l] - 'a'] -= 1;
            if(cnt1 == cnt2)return true;
            l++;
            r++;
        }
        return false;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ 
