### 原题链接 -- [[878. 第 N 个神奇数字](https://leetcode.cn/problems/nth-magical-number/)]

### 题目概述：
Tag : 「二分查找」、「容斥原理」

![image](https://user-images.githubusercontent.com/99656524/203226102-2c1d0a6e-2e05-4649-91c6-07e33c79d440.png)

### 数据范围
* $1 <= n <= 109$
* $2 <= a, b <= 4 * 10^4$

### 解法一：二分查找
题目大意为找到第n个能被a或者b整除的数，这题跟丑数III是一样的，根据容斥原理可以得到，能被a或b整除的数为被a整除的数 + 被b整除的数 - ab的最小公倍数（重叠部分），又因为这个函数具有单调性，我们就可以在函数区间内进行二分查找让时间复杂度降低到 $O(logn)$ 级别

C++代码：
```cpp
class Solution {
public:
    using int64 = long long;
    int MOD = 1e9 + 7;
    int64 gcd(int a, int b)
    {
        return b ? gcd(b, a%b) : a;
    }

    int64 lcm(int a, int b)
    {
        return (a * b) / gcd(a, b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        int64 ab = lcm(a, b);
        int64 l = min(a, b)-1, r = (int64)n*min(a, b);
        while(l + 1 != r)
        {
            int64 mid = l + r >> 1;
            int64 cnt = mid/a + mid/b - mid/ab; //容斥原理
            if(cnt < n)l = mid;
            else r = mid;
        }
        return r % MOD;
    }
};
```
* 时间复杂度： $O(logn * min(a,b))$ 
* 空间复杂度： $O(1)$ 
