#include<bits/stdc++.h>

const int N = 10010;
using namespace std;
int n = 5;

//二分查找的条件：函数具有单调性(二段性)，即使是部分的单调性也可以(初始右边界调整即可)

//1.半开区间搜索模板[l,r)
//终止条件：l == r，终止时搜索区间为[l,l)没有元素
//如果mid不一定出现在数组中，就要用半开区间的搜索
//寻找第一个大于(>)x的下标(上界)
int upperbound(int* a,int x)
{
	int l = 0;
	int r = n - 1;
	while (l < r) //结束条件，结束的时候搜索区间的元素必须为0
	{
		int mid = l + (r - l) / 2;
		if (a[mid] > x)r = mid;
		else l = mid + 1;
	}
	return l;
}

//寻找第一个大于等于(>=)x的下标(下界)
int lowerbound(int* a, int x)
{
	int l = 0;
	int r = n - 1;
	while (l < r) //结束条件，结束的时候搜索区间的元素必须为0
	{
		int mid = l + (r - l) / 2;
		if (a[mid] >= x)r = mid;
		else l = mid + 1;
	}
	return l;
}

//如果是寻找小于(<)，可以用lowerbound得到的下标-1(假设单调递增)
//如果是寻找小于等于(<=)，可以用upperbound得到的下标-1(假设单调递增)

//2.闭区间搜索[l,r]
//终止条件：l == r + 1，终止时搜索区间为[l + 1,l]没有元素
//找到有序数组中值为x的数
int Binary_Search(int* a, int x)
{
	int l = 0;
	int r = n - 1;
	while (l <= r) //结束条件，结束的时候搜索区间的元素必须为0
	{
		int mid = l + (r - l) / 2;
		if (a[mid] > x)r = mid - 1;
		else if (a[mid] == x) return mid;
		else l = mid + 1;
	}
	return -1;//没找到
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a[5] = { 3,4,5,8,10 };
	lowerbound(a, 4);
	upperbound(a, 4);
	cout << Binary_Search(a, 4) << endl;
	return 0;
}
