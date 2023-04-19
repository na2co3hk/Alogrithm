### 原题链接 -- [[875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/233103478-811a2ef8-e3d0-4695-8fca-18feaeaff56e.png)

### 数据范围
* $1 <= piles.length <= 10^4$
* $piles.length <= h <= 10^9$
* $1 <= piles[i] <= 10^9$

### 解法一：二分查找
这题是最小化最大值的变形，题目可以转变为吃掉所有香蕉的最小时间，也是可以转变为二分答案模板的。先猜一个吃香蕉的速度，看看需要多少个小时才能吃完所有香蕉。

注意：吃掉每堆香蕉需要 $\lceil \frac{p}{mid}\ \rceil$ 个小时，但可以通过公式转换为下取整（这样就可以不用用函数，因为计算机整数除法本来就是下取整），即 $\lfloor \frac{p+mid-1}{mid}\ \rfloor$

C++代码：

上取整代码：
```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r)
        {
            int mid = l + (r - l)/2;
            int cnt = 0;
            for(auto p : piles)cnt += ceil(p * 1.0/mid); //统计吃掉这堆香蕉需要多少个小时
            if(cnt > h)l = mid + 1; 
            else r = mid;
        }
        return l;
    }
};
```

下取整代码：
```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r)
        {
            int mid = l + (r - l)/2;
            int cnt = 0;
            for(auto & p : piles)cnt += (p + mid - 1)/mid; 
            if(cnt > h)l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
```
* 时间复杂度： $O(nlog(r - l))$ ，其中 $l$ , $r$ 为上下界
* 空间复杂度： $O(1)$
