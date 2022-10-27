### 原题链接 -- [[455. 分发饼干](https://leetcode.cn/problems/assign-cookies/)]

### 题目概述：
Tag : 「贪心」、「排序」

![image](https://user-images.githubusercontent.com/99656524/198168843-f16b02de-2e06-4657-b928-df4d8d7a240b.png)

### 数据范围：
* $1 <= g.length <= 3 * 10^4$
* $0 <= s.length <= 3 * 10^4$
* $1 <= g[i], s[j] <= 2^31 - 1$

### 解法一：贪心
题目大意为：能给多少个小孩分配符合他们胃口的糖果，我们可以先对两个数组进行排序，让胃口小的小朋友拿到尺寸刚好大于等于胃口值的饼干（也就是s[j] >= g[i]捏），这样就会有更多大尺寸的饼干留给那些胃口大的人，从而让更多小朋友符合条件

C++代码：
```cpp
const auto ios_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j = 0,cnt = 0;
        int n = s.size();
        int m = g.size();
        while(i != m && j != n)
        {
            if(s[j] >= g[i])
            {
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};
```
* 时间复杂度： $O(nlogn + mlogm)$
* 空间复杂度： $O(1)$ 
