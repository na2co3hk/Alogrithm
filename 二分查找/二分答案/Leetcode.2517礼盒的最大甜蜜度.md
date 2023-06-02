### 原题链接 -- [[2517. 礼盒的最大甜蜜度](https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/)]

### 题目概述：
Tag : 「二分查找」、「贪心」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/435b62d9-ffb5-4a5a-9b05-ef315fcf672a)

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/5abd5795-0c84-4910-b32a-af88020112f8)

### 数据范围
* $1 <= price.length <= 10^5$
* $1 <= price[i] <= 10^9$
* $2 <= k <= price.length$

### 解法一：贪心 + 二分查找
显然这是一道二分答案题（最大化最小值）。由于题目需要一个最小的绝对值差，而排序之后每两个数的差值就是最小的，这里就运用了贪心的思想，排除了许多不可能的答案。然后再用二分寻找答案。首先猜一个答案（答案为一个最小差值），然后
遍历数组的差值，统计大于等于猜的最小差值的个数 $cnt$ ,若 $cnt >= k$ ，则说明猜小了，向右调整，反之则是猜大了，向左调整。

C++代码：
```cpp
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0,r = price[n-1] - price[0];
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            int cnt = 0, pre = -mid;
            for(auto& cur : price)
            {
                if(cur - pre >= mid)
                {
                    pre = cur;
                    cnt++;
                }
            }
            if(cnt >= k)l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
```
* 时间复杂度： $O(nlogn + nlogU)$ ,其中U为数组最大值和最小值之间的差值 
* 空间复杂度： $O(logn)$
