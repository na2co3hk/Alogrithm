### 原题链接 -- [[648. 单词替换](https://leetcode.cn/problems/replace-words/)]

### 题目概述：
Tag : 「字典树」

![image](https://user-images.githubusercontent.com/99656524/235633787-f29faa6a-6265-4a4c-b738-63eab7edeafb.png)


### 数据范围
* $1 <= dictionary.length <= 1000$
* $1 <= dictionary[i].length <= 100$
* $dictionary[i] 仅由小写字母组成。$
* $1 <= sentence.length <= 10^6$
* $sentence 仅由小写字母和空格组成。$
* $sentence 中单词的总量在范围 [1, 1000] 内。$
* $sentence 中每个单词的长度在范围 [1, 1000] 内。$
* $sentence 中单词之间由一个空格隔开。$
* $sentence 没有前导或尾随空格。$

### 解法一：字典树
题目大意为将句子中的所有单词都替换成他们的词根。而转化为词根就相当于转换为他们对应的前缀，因此可以通过建一颗前缀（字典）树存储所有 $dictionary$ 的单词，然后对分割后的句子进行前缀匹配替换即可。

C++代码：
```cpp
class Trie {
private:
    Trie* son[26];
    bool isWord;
public:
    Trie() {
        isWord = false;//标记是否有这个单词
        for(int i = 0; i < 26; i++) son[i] = nullptr;
    }
    
    ~Trie(){
        for(int i = 0; i < 26 ; i++){
            if(son[i] != nullptr) delete son[i];
        }
    }

    void insert(string word) {
        Trie* root = this;
        for(char x: word){
            int cur = x - 'a';
            if(root->son[cur] == nullptr) root->son[cur] = new Trie();
            root = root->son[cur];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        Trie* root = this;
        for(char x : word){
            int cur = x - 'a';
            if(root->son[cur] == nullptr) return false;
            root = root->son[cur];
        }
        return root->isWord;
    }
    
    string startsWith(string prefix) {//改模板
        Trie* root = this;
        string s;
        for(char x : prefix){
            int cur = x - 'a';
            if(root->isWord)return s;//有前缀
            if(root->son[cur] == nullptr)return prefix; //没这个前缀就返回完整的单词
            s.push_back(x);
            root = root->son[cur];
        }
        return s;
    }
};

class Solution {
public:
    vector<string> split(const string& s, const string& c) {
        size_t pos1, pos2;
        vector<string>v;
        pos2 = s.find(c);
        pos1 = 0;
        while (string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())v.push_back(s.substr(pos1));
        return v;
   }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>words = split(sentence, " ");
        string ans = "";
        Trie* t = new Trie();
        for(auto d : dictionary)t->insert(d);
        for(auto& word : words)word = t->startsWith(word);
        for(int i = 0;i < words.size() - 1;i++)
        {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back()); //最后一个单词后面没有空格需要独自处理
        return ans;
    }
};
```
* 时间复杂度： $O(d + s)$，其中 $d$ 和 $s$ 分别为数组dictionary的长度和sentence的长度
* 空间复杂度： $O(d + s)$，其中 $d$ 和 $s$ 分别为数组dictionary的长度和sentence的长度
