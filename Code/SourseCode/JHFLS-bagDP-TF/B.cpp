#include<bits/stdc++.h>
using namespace std;
bool dp[350001];
int v[35001];
int main()
{
	int allv, n;
	cin>>allv>>n;
	for(int i = 0; i < n; ++i)
		cin>>v[i];
	
	dp[0] = true;
	for(int i = 0; i < n; ++i)
		for(int j = allv; j >= 0; --j)
			dp[j + v[i]] |= dp[j];
	
	for(int i = allv; i >= 0; --i)
		if(dp[i])
		{
			cout<<i;
			return 0;
		}
} 

/**************************************************************
    Problem: 1434
    User: xz202201
    Language: C++
    Result: AC
    Time:7 ms
    Memory:2564 kb
****************************************************************/
