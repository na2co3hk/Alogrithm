### 原题链接 -- [[792. 匹配子序列的单词数](https://leetcode.cn/problems/number-of-matching-subsequences/)]

### 题目概述：
Tag : 「二分查找」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/202332481-e9da99dc-7c64-4b5b-bb11-c436e6a2e93b.png)


### 数据范围
* $1 <= s.length <= 5 * 10^4$
* $1 <= words.length <= 5000$
* $1 <= words[i].length <= 50$
* $words[i]和 s 都只由小写字母组成。$

### 解法一：哈希表 + 二分查找
题目大意为找到 $words$ 中子序列的个数。对于本题，我们可以用一个哈希表记录 $s$ 中所有字母出现的下标，这种哈希表可以用26个元素的数组代替，这样的好处是1：我们可以通过找下标来判断是否有这个序列，2：每个放入哈希表的字母的下标都是递增的，所以我们可以用二分查找来优化这一个过程，如果没有找到，说明没有这种子序列。

C++代码：
```cpp
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size(), res = 0;
        vector<vector<int>>hash(26);
        for(int i = 0;i < n;i++)hash[s[i] - 'a'].push_back(i); //每个字母存放下标有单调性
        auto f = [&](string &c)
        {
            int idx = -1;
            for(char x : c)
            {   //找到第一个比idx大的下标
                auto it = upper_bound(hash[x - 'a'].begin(), hash[x - 'a'].end(), idx);
                if(it == hash[x - 'a'].end())return false; //没找到
                idx = *it;
            }
            return true;
        };
        for(auto word : words)res += f(word);
        return res;
    }
};
```
* 时间复杂度： $O(m * size * logn)$,其中 $size$ 为每个 $word$ 的长度, $m$ 为字典的长度
* 空间复杂度： $O()$
