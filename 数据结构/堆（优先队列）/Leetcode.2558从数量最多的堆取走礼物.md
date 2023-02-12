### 原题链接 -- [[2558. 从数量最多的堆取走礼物](https://leetcode.cn/problems/take-gifts-from-the-richest-pile/)]

### 题目概述：
Tag : 「优先队列」

![image](https://user-images.githubusercontent.com/99656524/218294142-2274ba59-a7ed-4900-8a5b-e8664537f6b0.png)

### 数据范围
* $1 <= gifts.length <= 10^3$
* $1 <= gifts[i] <= 10^9$
* $1 <= k <= 10^3$

### 解法一：优先队列
题目大意为将执行k次将数组最大的元素开平方的操作，然后统计元素总和。我们可以直接用堆来取出数组的最大值。

C++代码：
```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>heap;
        long long ans = 0;
        for(auto x : gifts)heap.push(x);
        while(k--)
        {
            auto x = heap.top();
            heap.pop();
            long long g = (long long)pow(x, 0.5);
            heap.push(g);
        }
        while(!heap.empty())
        {
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};
```
* 时间复杂度： $O(klogn)$ 其中n位数组长度
* 空间复杂度： $O(1)$ 
