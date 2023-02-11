### 原题链接 -- [[2335. 装满杯子需要的最短总时长](https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/)]

### 题目概述：
Tag : 「贪心」、「优先队列」

![image](https://user-images.githubusercontent.com/99656524/218266519-e59e2348-a119-4a1c-b7a6-61af97c2c564.png)

![image](https://user-images.githubusercontent.com/99656524/218266422-454d7d4e-7738-4f56-92fa-d531a7aa342e.png)


### 数据范围
* amount.length == 3
* 0 <= amount[i] <= 100

### 解法一：贪心 + 优先队列
题目大意为每次装两杯不同的水（或只装一杯水），直到所有类型的杯子都装满，返回最小步数。根据题意要求最小步数，我们必定要尽可能地多两杯两杯地装，尽量不出现只装一杯水的情况。而要想多出现装两杯水的情况，就要每次尽量装需求最大的两种类型，这样会让所有水的需求都变得平均，而不会剩下只能装一杯的情况，从而最大化装两杯水的情况。而要想知道每次装水需求最大的两个类型，就需要用到优先队列这种数据结构。

C++代码：
```cpp
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int res = 0;
        priority_queue<int>heap;
        for(auto x : amount)heap.push(x);
        while(!heap.empty())
        {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            if(!a)break;
            a--;
            b--;
            res++;
            heap.push(a);
            heap.push(b);
        }
        return res;
    }
};
```
* 时间复杂度： $O(S)$ ,其中S为三个种类需求的和
* 空间复杂度： $O(1)$ 
