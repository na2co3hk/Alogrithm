### 原题链接 -- [[面试题 16.10. 生存人数](https://leetcode.cn/problems/living-people-lcci/)]

### 题目概述：
Tag : 「前缀和」、「差分」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/1c3eb1e6-d36d-4ef2-a0ca-da17f7a182e1)

### 数据范围
* 0 < birth.length == death.length <= 10000
* birth[i] <= death[i]

### 解法一：差分
利用差分的性质，我们可以在一段区间内快速增加和减少一个值，最后枚举总区间长度内最小的下标即可。

C++代码：
```cpp
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int n = birth.size();
        vector<int>div(2003, 0);
        for(int i = 0;i < n;i++)
        {
            int x = birth[i], y = death[i];
            div[x]++;
            div[y + 1]--;
        }
        int mx = 0, idx = 0, sum = 0;
        for(int i = 1900; i <= 2000 ;i++)
        {
            sum += div[i];
            if(mx < sum)
            {
                mx = sum;
                idx = i;
            }
        }
        return idx; 
    }
};
```
* 时间复杂度： $O(n)$ 
* 空间复杂度： $O(n)$ 
