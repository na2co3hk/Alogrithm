//找到数组中出现次数大于n / 2的元素
//如果它与计数器所记录的元素相同，则计数器加一，否则计数器减  一。当计数器减到 0 时，就重新选择一个元素作为候选元素，直到遍历完整个数组。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, can = 0;
        for(int num : nums)
        {
            if(cnt == 0)can = num; //初始化
            cnt += (num == can) ? 1 : -1; 
        }
        return can;
    }
};


