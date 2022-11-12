#include<bits/stdc++.h>

using namespace std;

const int N = 100;

//堆
class heap
{
public:
	int len;
	int h[N];

	heap(int* nums,int n)
	{
		this->len = n;
		for (int i = 1; i <= n; i++)h[i] = nums[i-1];
		for (int i = len / 2; i; --i)down(i); //建堆
	}

	void down(int u)
	{
		int t = u;
		if (u * 2 <= len && h[u * 2] < h[t])t = u * 2;
		if (u * 2 + 1 <= len && h[u * 2 + 1] < h[t])t = u * 2 + 1;
		if (t != u)
		{
			swap(h[u], h[t]);
			down(t);
		}
	}

	void up(int u)
	{
		while (u / 2 && h[u] < h[u / 2])
		{
			swap(h[u], h[u / 2]);
			u >>= 1;
		}
	}

	void add(int u)
	{
		h[++len] = u;
		up(len);
	}

	int top()
	{
		return h[1];
	}

	int del()
	{
		int top = h[1];
		h[1] = h[len--];
		down(1);
		return top;
	}
};
