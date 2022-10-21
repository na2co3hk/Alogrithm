### 原题链接 -- [[9. 回文数](https://leetcode.cn/problems/palindrome-number/)]

### 题目概述：
Tag : 「数学」、「模拟」

![image](https://user-images.githubusercontent.com/99656524/197209637-333bb8e2-943a-4413-af24-a0ea5858f7ad.png)

* $-2^31 <= x <= 2^31 - 1$

### 解法一：反转全部数字
根据回文串左右对称的性质，将字符串完全反转后判断是否完全相同

C++代码：
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long cur = 0;
        int num = x;
        while(num)
        {
            cur = cur*10+num%10;
            num /=10;
        }
        return cur==x;
    }
};
```
* 时间复杂度： $O(n)$ 
* 空间复杂度： $O(1)$ 

### 解法二：反转一半数字
根据回文串左右对称的性质，将字符串反转一半也是可以的
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
```
* 时间复杂度： $O(logn)$ 
* 空间复杂度： $O(1)$ 
