### 原题链接 -- [[1710. 卡车上的最大单元数](https://leetcode.cn/problems/maximum-units-on-a-truck/)]

### 题目概述：
Tag : 「贪心」

![image](https://user-images.githubusercontent.com/99656524/201812453-030fc72e-6201-4ef0-903a-ed6207d5ca4b.png)

![image](https://user-images.githubusercontent.com/99656524/201812471-307f3524-39cc-4088-93d1-ccca0a1e9e60.png)

### 数据范围
* $1 <= boxTypes.length <= 1000$
* $1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000$
* $1 <= truckSize <= 10^6$

### 解法一：贪心
简单贪心题，只需要将数组按照能装载的最大单元数排序即可，就好比一个背包肯定要选容量越大越好，并且好东西越多越好，少也没关系，我们只需要最大的装载容量。

C++代码：
```cpp
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size(), ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {return a[1] > b[1]; });
        for (int i = 0; i < n && truckSize; i++)
        {
            auto x = boxTypes[i];
            if (truckSize > x[0])
            {
                ans += x[1] * x[0];
                truckSize -= x[0];
            }
            else
            {
                ans += truckSize * x[1];
                break;
            }
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlogn)$ ,排序的时间nlog
* 空间复杂度： $O(1)$ 
