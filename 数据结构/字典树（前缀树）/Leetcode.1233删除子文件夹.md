### 原题链接 -- [[1233. 删除子文件夹](https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/)]

### 题目概述：
Tag : 「字典树」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/217706277-02c3329b-209a-458c-95f2-8d4c2a558cff.png)

### 数据范围
* $1 <= folder.length <= 4 * 10^4$
* $2 <= folder[i].length <= 100$
* folder[i] 只包含小写字母和 '/'
* folder[i] 总是以字符 '/' 起始
* 每个文件夹名都是 唯一 的

### 解法一：字典树
题目大意为删除所有子文件，即只保留最短前缀路径。我们先将路径的各个文件名分割出来，再在分割出来的最后的文件名上做上标记（标记为文件名在原数组Folder的下标，这样有利于记录答案），每次搜索到下标就直接返回，这样就可以找到最短前缀路径了。而需要找到最短前缀路径并且还需要对前缀结尾进行标记，又要进行搜索功能，能想到的数据结构就是字典树了。

[代码来源](https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/solution/python3javacgo-yi-ti-shuang-jie-pai-xu-z-dha2/)

C++代码:
```cpp
class Trie {
public:
    void insert(int fid, string& f) {
        Trie* node = this;
        vector<string> ps = split(f, '/');
        for (int i = 1; i < ps.size(); ++i) {
            auto& p = ps[i];
            if (!node->children.count(p)) {
                node->children[p] = new Trie();
            }
            node = node->children[p];
        }
        node->fid = fid;
    }

    vector<int> search() {
        vector<int> ans;
        function<void(Trie*)> dfs = [&](Trie* root) {
            if (root->fid != -1) {
                ans.push_back(root->fid);
                return;
            }
            for (auto& [_, child] : root->children) {
                dfs(child);
            }
        };
        dfs(this);
        return ans;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }

private:
    unordered_map<string, Trie*> children;
    int fid = -1;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* trie = new Trie();
        for (int i = 0; i < folder.size(); ++i) {
            trie->insert(i, folder[i]);
        }
        vector<string> ans;
        for (int i : trie->search()) {
            ans.emplace_back(folder[i]);
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nm)$，其中 $n$ 和 $m$ 分别为数组Folder的长度和Folder中最长的文件名的长度
* 空间复杂度： $O(nm)$，其中 $n$ 和 $m$ 分别为数组Folder的长度和Folder中最长的文件名的长度

