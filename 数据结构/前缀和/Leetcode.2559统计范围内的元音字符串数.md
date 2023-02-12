### 原题链接 -- [[2559. 统计范围内的元音字符串数](https://leetcode.cn/problems/count-vowel-strings-in-ranges/)]

### 题目概述：
Tag : 「前缀和」

![image](https://user-images.githubusercontent.com/99656524/218294355-fc387ea7-201b-4115-a00a-bb0cd37621e4.png)

### 数据范围
* $1 <= words.length <= 10^5$
* 1 <= words[i].length <= 40
* words[i] 仅由小写英文字母组成
* $sum(words[i].length) <= 3 * 10^5$
* $1 <= queries.length <= 10^5$
* 0 <= queries[j][0] <= queries[j][1] < words.length

### 解法一：前缀和
题目要求区间查询，不用进行修改，优先想到用前缀和这种数据结构。先统计数组前n个数以前的，以元音开头和结尾的个数，然后再进行查询操作，将时间复杂度降低至 $O(n + q)$

python代码：
```py
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        a = ['a', 'e', 'i', 'o', 'u']
        s = set(a)
        pre, idx = [], 0
        ans = []
        for word in words:
            if word[0] in s and word[-1] in s:
                idx += 1
            pre.append(idx)
        for ran in queries:
            l, r, cnt = ran[0], ran[1], 0
            cnt = pre[r] if l == 0 else pre[r] - pre[l-1] 
            ans.append(cnt)
        return ans
```
* 时间复杂度： $O(n + q)$
* 空间复杂度： $O(n)$
