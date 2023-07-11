### 原题链接 -- [[1206. 设计跳表](https://leetcode.cn/problems/design-skiplist/)]

### 题目概述：
Tag : 「数据结构」

![image](https://user-images.githubusercontent.com/99656524/236863037-ca264df4-1b64-4d9c-b365-65778afa1fcc.png)

![image](https://user-images.githubusercontent.com/99656524/236863086-4dbb76c7-5f92-4ba3-a086-b052d2c260e6.png)

![image](https://user-images.githubusercontent.com/99656524/236863131-a2463345-67d2-4f38-ae50-83efecb546a4.png)

### 数据范围
* $0 <= num, target <= 2 * 10^4$
* $调用search, add,  erase操作次数不大于 5 * 10^4$ 

### 解法一：跳表
当作是一个模板，原理就和链表基本差不多，详细看看官解吧（掩盖不会的事实）

C++代码
```cpp
const int MAX_LEVEL = 32;
const double P_FACTOR = 0.25;

struct SkiplistNode
{
    int val;
    vector<SkiplistNode*>forward;
    SkiplistNode(int val, int maxLevel = MAX_LEVEL):val(val), forward(maxLevel, nullptr) {}
};

class Skiplist {
public:
    Skiplist():head(new SkiplistNode(-1)), level(0), dis(0, 1) {

    }
    
    bool search(int target) {
        SkiplistNode* cur = this->head;
        for(int i = level - 1;i >= 0;i--)//找到第i层小于且最接近target的元素
        {
            while(cur->forward[i] and cur->forward[i]->val < target)cur = cur->forward[i];
        }
        cur = cur->forward[0]; //下一个元素
        return cur and (cur->val == target); //下一个元素存在且是目标值
    }
    
    void add(int num) {
        vector<SkiplistNode*>update(MAX_LEVEL, head); //生成一个MAX_LEVEL层的空指针
        SkiplistNode* cur = this->head;
        for(int i = level - 1;i >= 0;i--)//找到第i层小于且最接近num的元素
        {
            while(cur->forward[i] and cur->forward[i]->val < num)cur = cur->forward[i];
            update[i] = cur; //和普通链表一样，先保存上一个链表节点
        }
        int lv = randomLevl();
        level = max(level, lv);
        SkiplistNode* newNode = new SkiplistNode(num, lv);
        for(int i = 0;i < lv;i++)
        {
            newNode->forward[i] = update[i]->forward[i]; //设置新节点的节点域
            update[i]->forward[i] = newNode; //设置当前节点的节点域
        }
    }
    
    bool erase(int num) {
        vector<SkiplistNode*>update(MAX_LEVEL, nullptr);
        SkiplistNode* cur = this->head;
        for(int i = level - 1; i >= 0;i--)//找到第i层小于且最接近num的元素
        {
            while(cur->forward[i] and cur->forward[i]->val < num)cur = cur->forward[i];
            update[i] = cur; //和普通链表一样，先保存上一个链表节点
        }
        cur = cur->forward[0];
        if(!cur or cur->val != num)return false; //没有这个节点
        for(int i = 0; i < level ;i++)
        {
            if(update[i]->forward[i] != cur)break; //不是同一个节点了（比如层数比设置的高之后就不需要管了）
            update[i]->forward[i] = cur->forward[i];//直接覆盖
        }
        delete cur;
        while(level > 1 and head->forward[level - 1] == nullptr)level--; //更新当前最高层
        return true;
    }
private:
    int randomLevl() //随机生成一个高度
    {
        int lv = 1;
        while(dis(gen) < P_FACTOR and lv < MAX_LEVEL)lv++;
        return lv;
    }
    
    SkiplistNode* head;
    int level;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis; //(0, 1)区间内的均匀分布
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```
* 时间复杂度： $O(logn)$
* 空间复杂度： $O(n)$ 
