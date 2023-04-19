### 原题链接 -- [[1552. 两球之间的磁力](https://leetcode.cn/problems/magnetic-force-between-two-balls/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/233099889-0c169ed6-2ec6-46ad-9e4e-1e9c7681ad57.png)

![image](https://user-images.githubusercontent.com/99656524/233099924-97e63410-fc85-435c-9adb-1c61d4b5307c.png)

### 数据范围
* $n == position.length$
* $2 <= n <= 10^5$
* $1 <= position[i] <= 10^9$
* $所有 position 中的整数 互不相同 。$
* $2 <= m <= position.length$

### 解法一：二分查找
一看到最小化最大值或者最大化最小值，就知道是二分答案了。先猜一个磁力，然后看看需要多少个球，看不懂的可以先去看看之前的入门题。

C++代码：
```cpp
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 1, r = position[n - 1] - position[0];
        while(l < r)
        {
            int mid = l + (r - l + 1) / 2; //猜一个磁力，看看需要最多多少个球
            int cnt = 1, p = position[0];
            for(auto c : position) //统计需要多少个球
            {
                if(c - p >= mid)
                {
                    p = c;
                    cnt++;
                }
            }
            if(cnt < m)r = mid - 1;
            else l = mid;
        }
        return r;
    }
};
```
* 时间复杂度： $O(nlog(r - l))$ ，其中 $l$ , $r$ 为上下界
* 空间复杂度： $O(1)$
