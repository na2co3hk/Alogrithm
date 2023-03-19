### 原题链接 -- [[1625. 执行操作后字典序最小的字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/)]

### 题目概述：
Tag : 「广度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/226158493-b1787a8a-10af-4151-ad9c-62c253671f1f.png)

![image](https://user-images.githubusercontent.com/99656524/226158513-c97e8395-9c69-41c7-a746-734b6d43abd1.png)

![image](https://user-images.githubusercontent.com/99656524/226158518-f4012092-ac7c-4e65-9a38-62fc5c185952.png)

### 数据范围
* $2 <= s.length <= 100$
* $s.length 是偶数$
* $s 仅由数字 0 到 9 组成$
* $1 <= a <= 9$
* $1 <= b <= s.length - 1$

### 解法一：广度优先搜索
题目大意为将原数组进行若干次加数和旋转操作后得到一个字典序最小的字符串。
