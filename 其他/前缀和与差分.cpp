//前缀和：存储前n个数的和的数组
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int n = 5;
//前缀和初始化
vector<int>sum(n + 1, 0);

//一维前缀和
//sum[n]为前n个元素的和
int main()
{
	vector<int>nums = { 1, 2, 3, 4, 5 };
	//前缀和输入
	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + nums[i - 1]; //下标从1开始
	return 0;
}
  
//一维前缀和求区间和
