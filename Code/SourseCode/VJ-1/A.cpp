#include<bits/stdc++.h>
using namespace std;
int dp[100];
int main()
{
	int n;
	while(cin>>n)
	{
		dp[0] = 1, dp[1] = 1; 
		for(int i = 2; i <= n; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		cout<<dp[n]<<endl;
	}
}

