### 原题链接 -- [[1481. 不同整数的最少数目](https://leetcode.cn/problems/least-number-of-unique-integers-after-k-removals/)]

### 题目概述：
Tag : 「贪心」、「优先队列」、「哈希表」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/1f0a3758-c9fa-4bc8-8068-eeee9a6f2882)

### 数据范围
* $1 <= arr.length <= 10^5$
* $1 <= arr[i] <= 10^9$
* $0 <= k <= arr.length$

### 解法一：哈希表 + 优先队列
题目大意为删除k个元素后，数组剩下的种类最少。我们可以先用一个哈希表统计每个数出现的次数，再用一个pair存储每个数字以及数字对应的次数，然后放入堆中，每次取出堆顶，即为出现次数最少的元素。每次删除堆顶的元素直到k无法完全删除该数字为止。

C++代码：
```cpp
class Solution {
public:
    using PII = pair<int, int>;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>hash;
        for(auto a : arr)hash[a]++;
        priority_queue<PII, vector<PII>, greater<PII>>pq;
        for(auto x : hash)pq.push({x.second, x.first});
        while(k and pq.size())
        {
            auto t = pq.top();
            if(k >= t.first)k -= t.first;
            else break;
            pq.pop();
        }
        return pq.size();
    }
};
```
* 时间复杂度： $O(nlogn)$ 
* 空间复杂度： $O(n)$ 
