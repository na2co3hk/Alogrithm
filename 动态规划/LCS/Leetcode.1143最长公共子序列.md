### 原题链接 -- [[1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/226866856-eccf34cc-9e4a-4def-ae53-3e9cb507b6b7.png)

![image](https://user-images.githubusercontent.com/99656524/226866881-31e195e8-5902-49b4-8176-c3a973f2cb3c.png)

### 数据范围
* 1 <= text1.length, text2.length <= 1000
* text1 和 text2 仅由小写英文字符组成。

### 解法一：动态规划
题目大意和题目的名字一样，找到最长公共子序列，由于子序列中的每个元素只有选和不选两种状态，并且每次的选择都和上次的选择有关，所以可以考虑用动态规划来做。用两重循环去枚举两个字符串，f[i][j]表示第一个字符串以i结尾，第二个字符串以j结尾时的最长公共子序列长度，如果text[i]与text[j]相同，则代表这个字符是两个字符串共有的，可以将上一个状态 + 1。若不同，则考虑
