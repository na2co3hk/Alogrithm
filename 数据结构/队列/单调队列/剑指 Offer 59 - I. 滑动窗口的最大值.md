### 原题链接 -- [[剑指 Offer 59 - I. 滑动窗口的最大值](https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)]

### 题目概述：
Tag : 「队列」、「线段树」、「堆」

![image](https://user-images.githubusercontent.com/99656524/233755267-d3783189-fd4e-41b0-bf14-049d6de05255.png)

### 解法一：单调队列
本题是单调队列的模板题

利用单调队列能维护局部的最大或最小值的特性，非常用来适合解决RMQ问题（Range Maximum/Minimum Query）。回到题目，题目要求找到一个固定长度滑动窗口的最大值，滑动窗口每次更新时，都是从右边元素进，右边元素出。对于右边进入滑动窗
口的元素（记作 $r$ ），可以像单调栈一样，将队列中比 $r$ 小的元素弹出（这些必然不是答案，因为现在有了更好的选择），再加入到队列中，这样整个队列就是单调递减的了，此时可以将队列看作一个排名，排名最高的也就是滑动窗口的最大值。
对于左边退出窗口的元素（记作 $l$ ），如果 $l$ 是排名不是最高的，那么就不用进行操作，因为该元素在更大的 $r$ 加入的时候就已经被弹出了，如果 $l$ 是排名最高的，那么就将 $l$ 出队。最后每次 $l$ 出窗口时记录答案即可。

* 对于单调队列和单调栈异同，我想了一个不太恰当的比喻来描述（别笑）：单调队列就是在一个只认可强者的世界中，实力最强的排在最前面，后面来的人会干掉实力比他弱的人，对于比他强的只能排在他后面。但是实力再强也抵不过时间的磨损，最强的人始终会变老，然后死去，这个时候那些排在后面的人就会成为实力最强的人，而那些实力弱的人甚至没有等到变老就被实力强的人干掉了。

C++代码：
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int>res;
        for(int i = 0;i < n;i++)
        {
            //干掉实力弱的
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
            dq.push_back(i);
            if(i - k + 1 >= 0) //形成窗口了
            {
                //队列中最大的元素不在窗口了
                while(!dq.empty() && dq.front() <= i-k)dq.pop_front();
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用队列



