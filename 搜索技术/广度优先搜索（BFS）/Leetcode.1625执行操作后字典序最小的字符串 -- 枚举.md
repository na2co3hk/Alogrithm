### 原题链接 -- [[1625. 执行操作后字典序最小的字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/)]

### 题目概述：
Tag : 「广度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/226158493-b1787a8a-10af-4151-ad9c-62c253671f1f.png)

![image](https://user-images.githubusercontent.com/99656524/226158513-c97e8395-9c69-41c7-a746-734b6d43abd1.png)

![image](https://user-images.githubusercontent.com/99656524/226158518-f4012092-ac7c-4e65-9a38-62fc5c185952.png)

### 数据范围
* $2 <= s.length <= 100$
* $s.length 是偶数$
* $s 仅由数字 0 到 9 组成$
* $1 <= a <= 9$
* $1 <= b <= s.length - 1$

### 解法一：广度优先搜索
题目大意为将原数组进行若干次加数和旋转操作后得到一个字典序最小的字符串。对于这种题目，一般都是搜索出所有的答案后取最小的即可。

代码来源：[ylb大佬](https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/solution/python3javacgo-yi-ti-shuang-jie-bfs-bao-xl8n2/)

C++代码：
```cpp
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q{{s}};
        unordered_set<string> vis{{s}};
        string ans = s;
        int n = s.size();
        while (!q.empty()) {
            s = q.front();
            q.pop();
            ans = min(ans, s);
            string t1 = s;
            for (int i = 1; i < n; i += 2) {
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            }
            string t2 = s.substr(n - b) + s.substr(0, n - b);
            for (auto& t : {t1, t2}) {
                if (!vis.count(t)) {
                    vis.insert(t);
                    q.emplace(t);
                }
            }
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n^210^2)$
* 空间复杂度： $O(n)$

### 解法二：枚举
其实细想一步就可以发现，只要重复加数操作10次，就可以恢复到原来的状态，同理只要旋转n次，也能恢复到原来的状态。所以，枚举所有状态即可。

C++代码：
```cpp
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n; ++i) {
            s = s.substr(n - b) + s.substr(0, n - b);
            for (int j = 0; j < 10; ++j) {
                for (int k = 1; k < n; k += 2) {
                    s[k] = (s[k] - '0' + a) % 10 + '0';
                }
                if (b & 1) {
                    for (int p = 0; p < 10; ++p) {
                        for (int k = 0; k < n; k += 2) {
                            s[k] = (s[k] - '0' + a) % 10 + '0';
                        }
                        ans = min(ans, s);
                    }
                } else {
                    ans = min(ans, s);
                }
            }
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n^210^2)$
* 空间复杂度： $O(n)$
