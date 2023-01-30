#include<bits/stdc++.h>
using namespace std;
long long int dp[20][20] = {0};
int main()
{
	for(int i = 0; i <= 15; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			if(i == j || i == 0 || j == 1 || i == 1)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j - 1] + j * dp[i - 1][j];
		}
	}
	int n;
	while(cin>>n)
	{
		if(n == 0)
		{
			cout<<1<<endl;
			continue;
		}
		long long int ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			ans += dp[n][i];
		}
		cout<<ans<<endl;
	}
}

