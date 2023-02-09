//标准版本
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
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for(char x : prefix){
            int cur = x - 'a';
            if(root->son[cur] == nullptr) return false;
            root = root->son[cur];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
  ---------------------------------------------------------------------------------------------
//数组模拟字典树
//字典树
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
