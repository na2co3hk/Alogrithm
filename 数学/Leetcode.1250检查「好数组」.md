### 原题链接 -- [[1250. 检查「好数组」](https://leetcode.cn/problems/check-if-it-is-a-good-array/)]

### 题目概述：
Tag : 「数学」

![image](https://user-images.githubusercontent.com/99656524/219846602-d46d3c8d-c328-4946-8ea6-7cda8d446afb.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^9$

### 解法一：数学
本题涉及到数论中的扩展欧几里得定理（好像也叫裴蜀定理和贝祖定理），这个定理大概意思是a和b两个数，对于任意的整数x和y，都有ax + by = gcd(a, b)；它的一个重要推论是：a,b互质的充分必要条件是存在整数x,y使ax + by = 1。回到本题，题目大意为在数组中找出两个数，分别乘以一个整数使得结果等于1。而从刚才说的定理可知，ax + by = gcd(a, b)，所以可以推出gcd(a, b）==1。因此我们只需要判断整个数组的最小公约数是否等于1即可。

C++代码：
```cpp
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int d = nums[0];
        for(auto x : nums) //对整个数组求gcd
        {
            d = gcd(d, x);
            if(d == 1)break;
        }
        return d == 1;
    }

    int gcd(int a,int b)
    {
        return b ? gcd(b, a % b) : a;
    }
};
```
* 时间复杂度： $O(n + logm)$ ，其中n和m分别为数组元素和数组最大值于在每次求两个数的最大公约数时其中一个数保持单调不增，所以求总的公约数的时间复杂度为 $O(logm)$。
* 空间复杂度： $O(1)$ 
