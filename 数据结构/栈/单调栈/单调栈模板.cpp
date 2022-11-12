#include<bits/stdc++.h>

using namespace std;

const int N = 10010;
using int64 = long long;
using int128 = unsigned long long;

int n;
int a[N];

void mototonestack1() //三次遍历版本
{
	vector<int>left(n);
	vector<int>right(n);
	stack<int>stk;
	//计算右边比a[i]小的第一个数的下标
	// 求右侧严格小于 a[i] 的最近位置 right[i]，这样 a[i] 就是区间 [i,right[i]-1] 内最小的元素（之一）
	for (int i = n - 1; i >= 0; i--)
	{
		while (!stk.empty() && a[stk.top()] >= a[i])stk.pop(); //弹出比 a[i] 大的，结束后栈顶都小于 a[i]
		if (!stk.empty())right[i] = stk.top();
		stk.push(i);
	}
	for (int i = 0; i < n; i++)cout << right[i] << ' ';
	cout << endl;
	while (!stk.empty())stk.pop(); //清空栈
	//计算左边边比a[i]小的第一个数的下标
	// 求左侧严格小于 a[i] 的最近位置 left[i]，这样 a[i] 就是区间 [left[i]+1,i] 内最小的元素（之一）
	for (int i = 0; i < n; i++)
	{
		while (!stk.empty() && a[stk.top()] >= a[i])stk.pop();
		if (!stk.empty())left[i] = stk.top();
		stk.push(i);
	}
	for (int i = 0; i < n; i++)cout << left[i] << ' ';

	vector<int>pre(n + 1, 0);
	for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i];

	//计算贡献
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l = left[i] + 1; //[l,r)看最小值或者最大值包不包括自己
		int r = right[i];
		int tot = (pre[r] - pre[l]);
		ans = ans + a[i] * tot;
	}

}

void mototonestack2()//两次遍历版本
{
	vector<int>left(n);
	vector<int>right(n, n);//这里要初始化成n，如果不包括自身就初始化成n-1
	stack<int>stk;
	for (int i = 0; i < n; i++)
	{
		while (!stk.empty() && a[stk.top()] >= a[i])
		{
			right[stk.top()] = i; //如果不包括自身，就-1
			stk.pop();
		}
		if (!stk.empty())left[i] = stk.top();//如果不包括自身，就+1
		stk.push(i);
	}
	for (int i = 0; i < n; i++)cout << right[i] << ' ';
	cout << endl;
	for (int i = 0; i < n; i++)cout << left[i] << ' ';
}

void mototonestack3()//一次遍历版本(出栈就更新)
{
	stack<int>stk;
	for (int r = 0; r < n; r++)
	{
		while (!stk.empty() && a[stk.top()] >= a[r])
		{
			int i = stk.top();
			stk.pop();
			int l = stk.top();
		}
		stk.push(r);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	//mototonestack1();
	mototonestack2();
	//mototonestack3();
	return 0;
}

