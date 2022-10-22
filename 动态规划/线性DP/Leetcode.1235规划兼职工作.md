### 原题链接 -- [[1235. 规划兼职工作](https://leetcode.cn/problems/maximum-profit-in-job-scheduling/)]

### 题目概述：
Tag : 「动态规划」、「二分查找」

![image](https://user-images.githubusercontent.com/99656524/197314940-dd81f28e-7ebf-41ca-acae-4448fe44138b.png)

![image](https://user-images.githubusercontent.com/99656524/197314947-59b42d5c-b640-4ae2-90c4-de43f22a458f.png)

### 数据范围：
* $1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4$
* $1 <= startTime[i] < endTime[i] <= 10^9$
* $1 <= profit[i] <= 10^4$


### 解法一：动态规划 + 二分查找：
根据题目大意，我们可以知道，我们要找出最大的赚取价值，则需要上一步的做出最优的选择，也就是每一步都做出当前的最优选择，这看起来很像贪心，但是实际上他还是个动态规划，从上一步的最优选择转移到下一步

我们先将 $startTime$ ， $endTime$ ， $profit$ 整合到一个数组，方便一同处理。

状态表示为：以i为结束时间的最大价值，我们先将 $endTime$ 从小到大排序，这样就可以知道小于等于i最近的 $endTime$ 是多少了，这个过程有点类似于插入排序，并且和插入排序一样可以用二分查找代替线性查找

C++代码：
```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs(n,vector<int>(3)); 
        for(int i = 0;i < n;i++)
        {
            jobs[i] = {startTime[i], endTime[i], profit[i]}; //整合
        }
        sort(jobs.begin(),jobs.end(),[](const vector<int>&jobs1, const vector<int>&jobs2) -> bool{return jobs1[1] < jobs2[1];}); //按照endTime排序
        vector<int>dp(n + 1);
        for(int i = 1;i <= n;i++)
        {
            int j = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int> &job) -> bool {
                return st < job[1];
            }) - jobs.begin(); //upper_bound返回的是迭代器，减去jobs.begin()可以返回一个int，也就是返回下标
            dp[i] = max(dp[i-1], dp[j] + jobs[i-1][2]);
        }
        return dp[n];
    }
};
```
