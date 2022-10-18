### 原题链接 -- [[902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://user-images.githubusercontent.com/99656524/196468443-b1336bb3-5349-46f4-b5ea-c9aa9237ff99.png)

![image](https://user-images.githubusercontent.com/99656524/196468554-8e7eef88-b6aa-4f95-8941-8d3d36419a3a.png)

### 数据范围
* 1 <= digits.length <= 9
* digits[i].length == 1
* digits[i] 是从 '1' 到 '9' 的数
* digits 中的所有值都 不同 
* digits 按 非递减顺序 排列
* 1 <= n <= 109

### 解法一：记忆化搜索
本题是leetcode上经典的一道数位DP的题目，难度为困难

题目大意为给出一个字符数组 $digits$，和整数 $N$，求用给定字符数组构成数字小于 $N$ 的数字组合的个数

我们可以从数字的位数出发，枚举每一位到边界数字的位数，这一过程是一个状态转移的过程，我们需要上一位的状态来枚举下一位的状态。若上一位作出了受限的选择，则下一位的范围也会受到限制

比如： $digits = { '1', '2', '3' }$  $N = 123$ 
