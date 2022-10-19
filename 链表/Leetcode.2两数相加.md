### 原题链接 -- [[2.两数相加](https://leetcode.cn/problems/add-two-numbers/)]

### 题目概述：
Tag : 「链表」、「高精度运算」

![image](https://user-images.githubusercontent.com/99656524/196448792-437e37ce-0d13-441f-a8b9-b47eb460f074.png)

![image](https://user-images.githubusercontent.com/99656524/196448865-f8ff3ee8-ba4b-4f20-bec0-3547fb8b8cda.png)

![image](https://user-images.githubusercontent.com/99656524/196448897-fc7c7524-28db-436b-9dfc-9444c7ac6393.png)


### 数据范围
* 每个链表中的节点数在范围 [1, 100] 内
* 0 <= Node.val <= 9
* 题目数据保证列表表示的数字不含前导零

### 解法一：高精度运算
本题为高精度运算在链表上的应用，没有过多的算法技巧，要注意进位是要从链表头部补
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr,*tail = nullptr;
        int t = 0;//进位
        while(l1||l2)
        {
            t += l1 ? l1->val : 0;//如果其中一个有高位不存在，就变成0
            t += l2 ? l2->val : 0;
            if (!head) {//如果头节点为空
                head = tail = new ListNode(t % 10);
            } else {//不是头节点的情况
                tail->next = new ListNode(t % 10);
                tail = tail->next;
            }
            t /=10;
            if(l1)l1 = l1->next;//l1存在就后移
            if(l2)l2 = l2->next;//l2存在就后移
        }
        if(t)tail->next = new ListNode(t);//最高位有进位
        return head;
    }
};
```
* 时间复杂度： $O(max(m,n))$ 其中 mm 和 nn 分别为两个链表的长度。我们要遍历两个链表的全部位置，而处理每个位置只需要 $O(1)$ 的时间。
* 空间复杂度： $O(1)$ 

附赠高精度运算模板
高精度加法
```cpp
//高精度加法，适用于数很大的情况（大于1e6)
vector<int> add(vector<int> &A, vector<int> &B)//此时数组都是逆序存储（个位在下标0的位置）
{
    if (A.size() < B.size()) return add(B, A);//默认A的位数大于B的位数好运算一些

    vector<int> C;//结果数组
    int t = 0;//进位
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);//取两个相加的个位
        t /= 10;//取两个数相加的十位，如果没有十位则变成0
    }

    if (t) C.push_back(t);//剩余的t判断最高位是否存在进位
    return C;
}
```

高精度减法
```cpp
//高精度减法
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);//+10判断借位，如果不需要借位，则刚好%10抵消
        if (t < 0) t = 1;//有借位
        else t = 0;//没有借位
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();//得到的结果前面如果有不需要的0比如数组存储300000（代表的是数字3）则要把前面的0消掉
    return C;
}
```

高精度乘法
```cpp
//高精度乘法
vector<int> mul(vector<int> &A, int b)//高精度整数乘以低精度整数
{
    vector<int> C;

    int t = 0;//进位
    for (int i = 0; i < A.size() || t; i ++ )//当A中还有位数或者还有进位（没乘完）
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}
```

高精度除法
```cpp
//高精度除法
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;//余数
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());//除法运算是从高位开始，所以结果数组也是从高位开始，需要反转一下
    while (C.size() > 1 && C.back() == 0) C.pop_back();//去除前面无用的0
    return C;
}
```
