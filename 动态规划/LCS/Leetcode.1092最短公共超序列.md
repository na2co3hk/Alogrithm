### 原题链接 -- [[1092. 最短公共超序列](https://leetcode.cn/problems/shortest-common-supersequence/)]

### 题目概述：
Tag : 「动态规划」、「双指针」

![image](https://user-images.githubusercontent.com/99656524/228400606-6168d64b-6c82-4a81-b8ab-dd1b17eb9ed4.png)

### 数据范围
* 1 <= str1.length, str2.length <= 1000
* str1 和 str2 都由小写英文字母组成。

### 解法一：动态规划 + 双指针
根据题目，不难想到和最长公共子序列（LCS）有关。并且，公共超序列是由三部分组成的，第一部分为两个字符串的最长公共子序列（如果不包含LCS的话就不能称之为公共超序列了），剩下两部分为s1或s2特有的部分（如题目示例的案例中，'c'由s2提供，"ab"为LCS，'ac'由s1提供）。因此，我们需要先构造出LCS的动态规划数组，然后再用两个指针分别指向两个字符串的尾部，
