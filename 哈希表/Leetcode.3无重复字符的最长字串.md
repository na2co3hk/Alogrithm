### 原题链接 -- [[3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)]

### 题目概述：
Tag : 「滑动窗口」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/196451209-0de334aa-0b75-48d6-a190-e607f265cef0.png)

![image](https://user-images.githubusercontent.com/99656524/196451285-80a12bb3-e870-491b-8475-aeec7a0bab64.png)

### 数据范围
* 0 <= s.length <= 5 * 104
* s 由英文字母、数字、符号和空格组成

### 解法一：哈希表
先遍历数组，将遍历的每个字母放到哈希表中，如果遇到重复的，就回到字母上一次出现的位置的下一个位置，并清空哈希表重新开始计数，更新ans
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==1)return 1;
        int count = 0;
        int res = 0;
        unordered_map<int,int>hash;
        for(int i = 0;i<n;i++)
        {
            if(hash.find(s[i])!=hash.end())//有重复
            {
                res = max(count,res);
                i = hash[s[i]]+1;//回溯
                count = 0;
                hash.clear();
            }
            hash[s[i]] = i;//哈希表存字符上一次出现的位置
            count++;
            
        }
        return max(count,res);//如果字符一直没有重复，count就不会归0
    }
};
```

