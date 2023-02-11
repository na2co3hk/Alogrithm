### 原题链接 -- [[1138. 字母板上的路径](https://leetcode.cn/problems/alphabet-board-path/)]

### 题目概述：
Tag : 「哈希表」

![image](https://user-images.githubusercontent.com/99656524/218270213-43bc7ad7-4c97-4868-a70a-bc86ef6c2091.png)

![image](https://user-images.githubusercontent.com/99656524/218270216-11451510-4c4f-43e7-9484-a0719d54f942.png)

### 数据范围
* 1 <= target.length <= 100
* target 仅含有小写英文字母。

### 解法一：哈希表
由于字母表的长宽是固定的，而且刚好和26字母的顺序一致，我们可以直接算出字母所在的位置，然后再统计当前位置和目标字母的曼哈顿距离就行。另外要注意的是，如果要求字母'z'的时候，计算曼哈顿距离的话要先计算横向距离再计算纵向距离
C++代码：
```cpp
class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int x = 0, y = 0;
        for (char c : target) {
            int nx = (c - 'a') / 5, ny = (c - 'a') % 5; // 目标位置
            string v(abs(nx - x), "UD"[nx > x]); // 竖直
            string h(abs(ny - y), "LR"[ny > y]); // 水平
            ans += (c != 'z' ? v + h : h + v) + "!";
            x = nx, y = ny;
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n)$ 
* 空间复杂度： $O(1)$
