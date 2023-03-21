### 原题链接 -- [[2594. 修车的最少时间](https://leetcode.cn/problems/minimum-time-to-repair-cars/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/226532550-8b94c56f-f248-4122-b2b1-7bfdb336a70b.png)

![image](https://user-images.githubusercontent.com/99656524/226532581-943eead4-fda3-4433-b799-8e741b5fbfdd.png)

### 数据范围
* $1 <= ranks.length <= 10^5$
* $1 <= ranks[i] <= 100$
* $1 <= cars <= 10^6$

### 解法一：二分查找
这题中文翻译有点逆天，所以用了英文翻译，题目大意为有 $n$ 个工人，工人能力值的排名为 $ranks$ ，总共有 $cars$ 量车，一个工人能在 $r * n^2$ 时间内修理一辆车，求修理所有车的最短时间。根据题意可得：

$$
  t = r * n^2
$$

其中，n为该工人要修的车的数目，t为工人的工作时长。t是n的一个函数，且t为单调函数，我们不难想到要用二分查找来做。

将式子转化一下就变成了 $n = sqrt(t / r)$ 当所有工人 $n$ 的总和大于 $cars$ 时，代表工人能在t时间内修理大于等于车的数目（若小于则代表在t时间内不能修理数量为 $cars$ 的车），根据二段性不断循环求得等于 $cars$ 的最短修车时间

C++代码：
```cpp
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        auto check = [&](long long t)
        {
            long long s = 0;
            for(long long r : ranks)s += sqrt(t / r);
            return s >= cars;
        };

        int m = *min_element(ranks.begin(), ranks.end());
        long long l = 0;
        long long  r = 1LL * m * cars * cars;

        while(l < r)
        {
            long long mid = l + (r - l) / 2;
            if(check(mid))r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
```
* 时间复杂度： $O(nlogn)$
* 空间复杂度： $O(1)$

