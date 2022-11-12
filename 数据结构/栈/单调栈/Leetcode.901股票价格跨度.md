### 原题链接 -- [[901. 股票价格跨度](https://leetcode.cn/problems/online-stock-span/)]

### 题目概述：
Tag : 「单调栈」

![image](https://user-images.githubusercontent.com/99656524/197205419-de93522e-40e5-4afc-b7e1-257e31445a59.png)

### 提示
* $调用 StockSpanner.next(int price) 时，将有1 <= price <= 10^5$ 。
* 每个测试用例最多可以调用  10000 次 StockSpanner.next。
* 在所有测试用例中，最多调用 150000 次 StockSpanner.next。
* 此问题的总时间限制减少了 50%。

### 解法一：单调栈
这题本来是打算用动态规划做的，但是发现没有具体的元素数量，但是通过这一点，以及找数组中左边或右边最近的最大值这一点可以看出来，这题该用单调栈

题目要求我们找出比第i个元素小的连续元素的个数，我们维护一个单调最小栈，若遇到比栈顶大的元素，弹出栈顶并记录连续弹出的元素个数，由于 $int$ 类型无法记录两个信息，我们需要用到 $pair$ 来存储他的股票价格和连续弹出栈顶的元素个数（包括他自己），下次我们遇到比这个元素大的时候就弹出并加上他连续弹出元素的个数

C++代码
```cpp
class StockSpanner {
public:
    stack<pair<int,int>>stk;
    StockSpanner() {

    }
    
    int next(int price) {
        int ans = 1;
        while(!stk.empty() && stk.top().first <= price)
        {
            auto x = stk.top();
            ans += x.second;
            stk.pop();
        }
        stk.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用栈
