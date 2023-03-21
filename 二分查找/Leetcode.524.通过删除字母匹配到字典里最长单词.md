### 原题链接 -- [[524. 通过删除字母匹配到字典里最长单词](https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/)]

### 题目概述：
Tag : 「二分查找」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/226523659-0d75b37c-7e0a-491d-9019-e63b022631ce.png)

### 数据范围
* 1 <= s.length <= 1000
* 1 <= dictionary.length <= 1000
* 1 <= dictionary[i].length <= 1000
* s 和 dictionary[i] 仅由小写英文字母组成

### 解法一：哈希表 + 二分查找
本题和[792. 匹配子序列的单词数](https://leetcode.cn/problems/number-of-matching-subsequences/)的做法一摸一样，[题解看这里](https://github.com/na2co3hk/Alogrithm/edit/main/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE/Leetcode.792%E5%8C%B9%E9%85%8D%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E5%8D%95%E8%AF%8D%E6%95%B0.md)

可以将问题转换为求一个能够匹配字典中任意一个字符串的子序列，并返回最长的能够匹配的字符串。用一个哈希表存原字符串中所有字母出现的下标，这种哈希表可以用26个元素的数组代替，这样的好处是1：我们可以通过找下标来判断是否有这个序列，2：每个放入哈希表的字母的下标都是递增的，所以我们可以用二分查找来优化这一个过程，如果没有找到，说明没有这种子序列。

$后来才知道这种方法原来叫子序列自动机，用来进行子序列匹配的$

C++代码：
```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        string ans = "";
        vector<vector<int>>hash(26);
        for(int i = 0;i < n ;i++)hash[s[i] - 'a'].push_back(i);
        auto f = [&](string &c)
        {
            int idx = -1;
            for(auto x : c)
            {
                auto it = upper_bound(hash[x - 'a'].begin(), hash[x - 'a'].end(), idx);
                if(it == hash[x - 'a'].end())return false;
                idx = *it;
            }
            return true;
        };
        for(auto word : dictionary)
        {
            bool flag = f(word);
            if(flag && ans.size() == word.size())ans = min(ans, word); //长度相等，返回字典序小的
            else if(flag && max(ans.size(), word.size()) == word.size())ans = word;
        }
        return ans;
    }
};
```
* 时间复杂度： $O(m * size * logn)$,其中 $size$ 为每个 $word$ 的长度, $m$ 为字典的长度
* 空间复杂度： $O(n)$

