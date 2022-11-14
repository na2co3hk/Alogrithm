//前缀和：存储前n个数的和的数组
#include<bits/stdc++.h>

using namespace std;

int n = 5;
//前缀和初始化
vector<int>sum(n + 1, 0);

int range(int l, int r) //前缀和求区间和[l,r]
{
	return sum[r] - sum[l - 1];
}

int main()
{
	vector<int>nums = { 1, 2, 3, 4, 5 };
	//前缀和输入
	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + nums[i - 1];
	for (auto x : sum)cout << x << ' ';
	cout << endl;
	cout << range(1, 5);
	return 0;
}
