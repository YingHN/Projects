#include<bits/stdc++.h>
using namespace std;
int v[6] = {1, 2, 3, 5, 10, 20}, k[6];
bool dp[10001];
int main()
{
	int allv = 0;
	for(int i = 0; i < 6; ++i)
	{
		cin>>k[i];
		allv += k[i] * v[i];
	}
	
	dp[0] = true;
	for(int i = 0; i < 6; ++i)
		for(int j = allv; j >= 0; --j)
			for(int x = 0; x <= k[i]; ++x)
				dp[j + x * v[i]] |= dp[j];
	
	int ans = 0;
	for(int i = 1; i <= allv; ++i)
		if(dp[i])
		{
			++ans;
		}
	cout<<"Total="<<ans;
}

/**************************************************************
    Problem: 1406
    User: xz202201
    Language: C++
    Result: AC
    Time:0 ms
    Memory:2096 kb
****************************************************************/
