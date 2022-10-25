### 原题链接 -- [[752. 打开转盘锁](https://leetcode.cn/problems/open-the-lock/)]

### 题目概述：
Tag : 「广度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/197797907-9f729c93-ac7b-4339-b0a4-e9947c2b470b.png)

![image](https://user-images.githubusercontent.com/99656524/197797968-4949124f-6e0e-42e2-819d-864458722fb0.png)

### 数据范围
* 1 <= deadends.length <= 500
* deadends[i].length == 4
* target.length == 4
* target 不在 deadends 之中
* target 和 deadends[i] 仅由若干位数字组成

### 解法一：双向BFS
本题是双向BFS的一道练手题目

随着递归层数的不断深入，BFS的搜索宽度也会不断地变宽，这时候不仅要是考虑效率的问题，宽度过大也会导致MLE（Memory limit exceed）。有没有解决方法呢？是有的，如果我们同时知道搜索起点和搜索终点，我们就可以对两边一起BFS，我们用两个队列和两个map，map存的是之前走过的状态。再回到这道题，题目的初始状态为 "0000" 这个状态，题目会给出目标状态，我们可以一位一位枚举填的数字，遇到死锁就返回，死锁我们可以将用集合预处理出来，当其中一个map中出现另一个map中存在的状态，就说明找到了一条最短的路，返回之前走过的状态和对方走过的状态的步数之和即为所求。

C++代码：
```cpp
class Solution {
public:
    string start, end;
    unordered_set<string>st;
    int openLock(vector<string>& deadends, string target) {
        start = "0000"; //初始数字
        end = target; //目标数字
        if(start == end)return 0;//特判
        for(auto d : deadends)st.insert(d); //用集合存死锁
        if(st.count(start))return -1; //死锁本身带有初始数字
        int ans = bfs();
        return ans;
    }

    int bfs() //双向BFS
    {
        queue<string>d1, d2;//两个队列用于两个方向的搜索
        unordered_map<string, int>m1 ,m2;//两个map「解决相同节点重复搜索」和「记录转换次数」
        d1.push(start); m1[start] = 0;
        d2.push(end); m2[end] = 0;
        while(d1.size() and d2.size())
        {
            int t = -1;
            t = d1.size() <= d2.size() ? update(d1, m1, m2) : update(d2, m2, m1);
            if(t!=-1)return t;
        }
        return -1;
    }

    int update(queue<string>& q,unordered_map<string,int>& cur,unordered_map<string,int>& other)
    {
        int m = q.size();
        while(m-- > 0)//等价于!q.empty()
        {
            string top = q.front();
            q.pop();
            int step = cur[top]; //记录top已经转换了多少次
            for(int i = 0;i < 4;i++)
            {
                for(int j = -1;j <= 1;j++)//枚举-1和+1两种状态，遇到0直接跳过
                {
                    if(j==0)continue;
                    int orign = top[i] - '0';//枚举第i位的两种状态
                    int next = (orign + j) % 10;
                    if(next == -1)next = 9;
                    string copy = top;
                    copy[i] = '0' + next;
                    if(st.count(copy) || cur.count(copy))continue;//遇到死锁或者这种状态已经走过
                    if(other.count(copy))return step + 1 + other[copy]; //遇到和对方队列状态相同
                    else                                                //则找到答案
                    {   //否则加入队列，并且转换次数+1
                        q.push(copy);
                        cur[copy] = step + 1;
                    }                                                  
                }
            }
        }
        return -1;
    }
};
```
