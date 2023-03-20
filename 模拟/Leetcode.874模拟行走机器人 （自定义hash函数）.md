### 原题链接 -- [[874. 模拟行走机器人](https://leetcode.cn/problems/walking-robot-simulation/)]

### 题目概述：
Tag : 「模拟」

![image](https://user-images.githubusercontent.com/99656524/226376596-529a202d-6597-4c99-8cb4-d4c84eb9c379.png)

![image](https://user-images.githubusercontent.com/99656524/226376668-7ce52a3d-0f84-447f-b06a-e14e302e703d.png)

### 数据范围
* $1 <= commands.length <= 10^4$
* commands[i] is one of the values in the list [-2,-1,1,2,3,4,5,6,7,8,9].
* $0 <= obstacles.length <= 10^4$
* $-3 * 10^4 <= xi, yi <= 3 * 10^4$
* 答案保证小于 231

### 解法一：模拟
按照题意模拟走的每一步即可，注意C++中的unordered_set并不支持pair的比较，需要自己定义hash函数

附上一点set和unordered_set的区别:（源自chatgpt）

![image](https://user-images.githubusercontent.com/99656524/226379906-57ed9e0d-644d-4db2-a089-0394db57e0a5.png)


C++代码:
```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        unordered_set<pair<int, int>, pair_hash> obstacleSet;
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));

        int ans = 0;
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;//左转
            else if (cmd == -1)
                di = (di + 1) % 4;//右转
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }

        return ans;
    }

private:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);
    
            return h1 ^ h2;
        }
    };
};

/*
set 和 unordered_set 底层分别是用红黑树和哈希表实现的。
unordered_set 不能用来保存 pair<int, int>，但是 set 可以。
因为 unordered_set 是基于哈希的，而 C++ 并没有给 pair 事先写好哈希方法。
set 是基于比较的树结构，所以 pair 里的数据结构只要都支持比较就能储存。
*/
```
* 时间复杂度： $O(n + k)$ ，其中n为commands的长度，k为obstacles的长度
* 空间复杂度： $O(k)$
