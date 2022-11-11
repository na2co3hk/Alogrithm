#include<bits/stdc++.h>

const int N = 10010;
using namespace std;

//只关心数据的大小关系，用排名代替原数据进行处理
//原理：通过建立一个映射数组来存储所有要进行操作的下标X，然后将其排序去重，每次操作X位置元素时用二分法查找X在映射数组中的位置Y。操作X位置元素改为操作Y位置元素。
//排序是为了方便二分查找，排序后去重比较方便，去重是为了建立X与Y的一一映射，不去重则会导致一个X可以对应多个Y（可以不去重，每次查询X只返回特定的Y就行了，但是这样时间复杂度更慢，所以最好还是去重）。
//离散化后只需要开大小为X的个数的数组了（这里是6个）
//时间复杂度：O（nlogn），为排序和二分查找的时间复杂度
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
		L[i] = lower_bound(c, c + n, a[i]) - c + 1; //查询
}

void Display2()//动态数组
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
	for (int i = 0; i < n; i++)L[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1; //查询
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
