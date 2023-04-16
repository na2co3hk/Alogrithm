//找到数组中出现次数大于n / 2的元素
//如果它与计数器所记录的元素相同，则计数器加一，否则计数器减  一。当计数器减到 0 时，就重新选择一个元素作为候选元素，直到遍历完整个数组。
int majorityElement(vector<int>& nums) 
{
     int cnt = 0, can = 0;
     for(int num : nums)
     {
         if(cnt == 0)can = num; //初始化
         cnt += (num == can) ? 1 : -1; 
     }
     return can;
}

//--------------------------------------------------------//
//更加一般的摩尔投票（用于线段树）
//定义一个节点node保存数组元素和出现次数
//出现次数比他多的元素则重新选择一个元素作为答案
struct node
{
    int val;
    int cnt;
    node(int val = 0,int cnt = 0):val(val), cnt(cnt) {}
    node& operator+=(const node& that)
    {
        if(val == that.val)cnt += that.cnt;
        else if(cnt >= that.cnt)cnt -= that.cnt;
        else 
        {
            val = that.val;
            cnt = that.cnt - cnt;
        }
        return *this;
    }
};
int majorityElement(vector<int>& nums) 
{
    vector<node>t(nums.size());
    for(int num : nums)
    {
        node a(num, 1);
        t.push_back(a);
    }
    node ans(0, 0);
    for(auto a : t)ans += a;
    return ans.val;
}
