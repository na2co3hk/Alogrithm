### 原题链接 -- [[509.斐波那契数](https://leetcode.cn/problems/fibonacci-number/)]

### 题目概述：
Tag : 「动态规划」、「记忆化搜索」、「递归」

![image](https://user-images.githubusercontent.com/99656524/196375446-542b479b-d257-4955-a8c8-9df1cde75826.png)

![image](https://user-images.githubusercontent.com/99656524/196375507-2d4e951d-a996-462a-b36a-5b9c814d72cc.png)


### 数据范围
* 0 <= n <= 30

### 解法一：记忆化搜索
根据斐波那契数列的定义，不难得到状态转移方程：

$$
f(i) = f(i - 1) + f(i - 2)\
$$

由于这个过程会大量访问之前算出的答案，所以使用记忆化搜索优化dp的过程
```cpp
class Solution {
public:
    int dp[31] = {0};
    int fib(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n] != 0)
        {
            return dp[n];
        }
        else
        {
           dp[n] = fib(n-1) + fib(n-2);
           return dp[n];
        }

    }
};
```
* 时间复杂度： $O(n)$ 
* 空间复杂度： $O(n)$ ，主要为系统调用栈空间

### 解法二：滚动数组
由于状态转移方程只与前两个数有关，可以用滚动数组来迭代优化递归
```cpp
class Solution {
    public int fib(int n) {
        if (n < 2) {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
}
```

* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$ ，常数级变量
