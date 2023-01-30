#include<bits/stdc++.h>
using namespace std;
int v[1000];
bool dp[10000];
int main()
{
	int n, allv = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>v[i];
		allv += v[i];
	}
	
	dp[0] = true;
	for(int i = 0; i < n; ++i)
	{
		for(int j = allv / 2; j >= 0; --j)
			dp[j + v[i]] |= dp[j];
	}
	
	for(int i = allv / 2; i >= 0; --i)
		if(dp[i])
		{
			cout<<abs(allv - 2 * i);
			return 0;
		}
}

/**************************************************************
    Problem: 1435
    User: xz202201
    Language: C++
    Result: AC
    Time:8 ms
    Memory:2100 kb
****************************************************************/
