#include<bits/stdc++.h>

const int N = 10010;
using namespace std;

void Display1()//静态数组
{
	int n = 6;
	int a[N] = { 10, 23, 35, 3, -40, 3 };
	int c[N], L[N];

	//离散化
	memcpy(c, a, sizeof a);
	sort(c, c + n);
	int i = unique(c, c + n) - c;
	for (int i = 0; i < n; i++)
		L[i] = lower_bound(c, c + n, a[i]) - c + 1;
}

void Display2()
{
	int n = 6;
	vector<int>a;
	a.push_back(10);
	a.push_back(23);
	a.push_back(35);
	a.push_back(3);
	a.push_back(-40);
	a.push_back(3);

	//离散化
	auto c = a;
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	vector<int>L(n);
	for (int i = 0; i < n; i++)L[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Display1();
	Display2();
	return 0;
}
