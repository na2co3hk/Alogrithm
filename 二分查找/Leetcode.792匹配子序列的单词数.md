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
题目大意为找到 $words$ 中子序列的个数。对于本题，我们可以用一个哈希表记录 $s$ 中所有字母出现的下标，这种哈希表可以用26个元素的数组代替，这样的好处是1：我们可以通过遍历每个 $words$ 中的每个
