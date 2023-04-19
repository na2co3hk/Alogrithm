### 原题链接 -- [[410. 分割数组的最大值](https://leetcode.cn/problems/split-array-largest-sum/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/233092868-84ca4a39-cbcc-46fd-8b69-0a0ffaf57684.png)

### 数据范围
* $1 <= nums.length <= 1000$
* $0 <= nums[i] <= 10^6$
* $1 <= m <= min(50, nums.length)$

### 解法一：二分查找

$最小化最大值和最大化最小值是二分答案的标志，并且通常需要在二分查找的过程中遍历数组一次$

本题为用二分查找寻找答案的模板题。题目大意为将原数组分割为 $m$ 个数组，并使子数组和最小。而子数组和属于一个有范围的整数（答案的下界为分割成一个数组的情况，上界为不分割数组的情况，即求整个数组的和），我们可以根据二分查找的 $mid$ 值，根据反馈不断调整数答案范围直到满足条件为止。这个过程可以类比猜数字游戏，比如需要猜一个区间为0~100之间的数字 $target$ ，我门会先随机先猜一个数字，然后根据这个数比 $target$ 大还是比 $target$ 小（这个就是反馈）来调整我们下一次猜的数字。回到题目，我们可以先猜一个答案，这个猜的数值就是二分查找的中点 $mid$ ，然后根据这个猜的答案，看看我们需要分成多少个子数组，若比 $m$ 大则说明答案太小，反之则说明答案太大，直到得到分成 $m$ 个数组的答案。

$一言以蔽之就是，先猜一个答案，直到满足输入的条件（这里输入的条件为分成m个数组）$

C++代码：
```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int l, r = 0;
        for(auto num : nums)
        {
            l = max(l, num);
            r += num;
        }
        while(l < r)
        {
            int mid = (l + r) >> 1;
            int tmp = 0, cnt = 1;
            for(auto num : nums)
            {
                tmp += num;
                if(tmp > mid)
                {
                    tmp = num;
                    cnt++;
                }
            }
            if(cnt > m) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
```
* 时间复杂度： $O(nlogr - l)$ ，其中l, r为上下界
* 空间复杂度： $O(1)$

