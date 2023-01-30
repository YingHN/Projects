#include<bits/stdc++.h>
using namespace std;
int getArea(int a, int b, int c)
{
	int p = (a + b + c) >> 1;
	double area = sprt(p * (p - a) * (p - b) * (p - c));
	return (int)(area * 100);
}
int v[100];
bool dp[100000], f[100000];
int main()
{
	int n, allv = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>v[i];
		allv += v[i];
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = allv / 3; j >= 0; --j)
		{
			for(int ii = 0; ii < n; ++ii)
			{
				for(int jj = allv * 2 / 3; jj >= 0; --jj)
				{
					f[jj + v[ii]] |= f[jj];
				}
			}
			
		}
	}
}

