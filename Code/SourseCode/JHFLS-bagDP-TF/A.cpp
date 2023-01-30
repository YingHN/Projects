#include<bits/stdc++.h>
using namespace std;
int v[20010];
bitset<20010> dp;
int main()
{
	int allv, n;
	cin>>allv>>n;
	for(int i = 0; i < n; ++i)cin>>v[i];
	dp[0]=1;
	for(int i = 0; i < n; ++i)
		for(int j = allv; j >= 0; --j)
			dp[j + v[i]] = dp[j + v[i]] | dp[j]; 
	
	for(int i = allv; i >= 0; --i)
	{
		if(dp[i])
		{
			cout<<allv - i;
			return 0;
		}
	}
}

/**************************************************************
    Problem: 1407
    User: xz202201
    Language: C++
    Result: AC
    Time:50 ms
    Memory:2168 kb
****************************************************************/
