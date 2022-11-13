### 原题链接 -- [[50. Pow(x, n)](https://leetcode.cn/problems/powx-n/)]

### 题目概述：
Tag : 「快速幂」

![image](https://user-images.githubusercontent.com/99656524/201521818-4563485e-938d-4e96-ae0f-7ec758435a4b.png)

### 数据范围
* $-100.0 < x < 100.0$
* $-2^31 <= n <= 2^31-1$
* $-10^4 <= x^n <= 10^4$
* 
### 解法一：快速幂
快速幂模板就行了，原理是倍增

C++代码：
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long k;
        long long N = n;
        if(N<0)k=-N;
        else k = N;
        while(k)
        {
            if(k&1)res *=x;
            k>>=1;
            x *=x;
        }
        return n >= 0 ? res : 1/res;
    }
};
```
* 时间复杂度： $O(logn)$
* 空间复杂度： $O(1)$ ,迭代写法是常数级，递归写法的话是n
