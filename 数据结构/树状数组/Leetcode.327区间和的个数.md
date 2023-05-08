### 原题链接 -- [[327. 区间和的个数](https://leetcode.cn/problems/count-of-range-sum/)]

### 题目概述：
Tag : 「树状数组」、「线段树」、「离散化」

![image](https://user-images.githubusercontent.com/99656524/236738297-5b90779e-3688-4d35-8ce3-92e2d05cb7d1.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $-2^31 <= nums[i] <= 2^31 - 1$
* $-10^5 <= lower <= upper <= 10^5$
* $题目数据保证答案是一个 32 位 的整数$

### 解法一：树状数组
题目大意为求区间和在[lower, upper] 的数目。由于题目提到了区间和，就不得不想到前缀和了，用 $pre[i]$ 表示下标i的前缀和， 则题目描述可以转化为

$$
lower <= pre[r] - pre[l - 1] <= upper 
$$
