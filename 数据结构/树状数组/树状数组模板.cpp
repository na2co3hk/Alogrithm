//注意：数组下标必须从1开始直到n,树状数组初始化大小为n+1
//单点修改，区间查询
#include<bits/stdc++.h>
#define lowbit(x) (x) & (-x)

using namespace std;

const int N = 10010;
int n;
vector<int>a(N);
vector<int>tree(N);

//单点更新
void add(int i, int d)
{
	for (int x = i; x <= n; x += lowbit(x))tree[x] += d;
}

//区间查询
int sum(int i)
{
	int ans = 0;
	for (int x = i; x; x -= lowbit(x))ans += tree[x];
	return ans;
}

//普通建树
void build()
{
	for (int i = 1; i <= n; i++)add(i, a[i]);
}
//------------------------------------------------------------------------------
//区间修改，单点查询
#include<bits/stdc++.h>
#define lowbit(x) (x) & (-x)

using namespace std;

const int N = 10010;
int n;
vector<int>a(N);
vector<int>tree(N);

//单点更新
void add(int i, int d)
{
	for (int x = i; x <= n; x += lowbit(x))tree[x] += d;
}

//单点查询(查询原数组的值)
int sum(int i)
{
	int ans = 0;
	for (int x = i; x; x -= lowbit(x))ans += tree[x];
	return ans;
}

//差分建树
void build()
{
	for (int i = 1; i <= n; i++)add(i, a[i] - a[i - 1]);
}

//区间修改(更新[x,y]的值)
void update(int x, int y, int d)
{
	add(x, d);
	add(y + 1, -d);
}
//------------------------------------------------------------------------------
//区间修改，区间查询
#include<bits/stdc++.h>
#define lowbit(x) (x) & (-x)

using namespace std;

const int N = 10010;
int n;
vector<int>a(N);
vector<int>sum1(N);
vector<int>sum2(N);

//单点更新
void add(int i, int d)
{
	for (int x = i; x <= n; x += lowbit(x))
	{
		sum1[x] += d;
		sum2[x] += d * (i - 1);
	}
}

//求前缀和
int sum(int i)
{
	int ans = 0;
	for (int x = i; x; x -= lowbit(x))ans += i * sum1[x] - sum2[x];
	return ans;
}

//差分建树
void build()
{
	for (int i = 1; i <= n; i++)add(i, a[i] - a[i - 1]);
}

//区间修改(更新[x,y]的值)
void update(int x, int y, int d)
{
	add(x, d);
	add(y + 1, -d);
}

//区间求和(求[x,y]的和)
int range(int x, int y)
{
	return sum(y) - sum(x - 1);//求区间和
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	n = 5;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(i, a[i] - a[i - 1]);
	}

	update(1, 1, 5); //单点修改
	cout << "区间和为：" << range(1, 4) << endl;

	return 0;
}
