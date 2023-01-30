#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 1, MAXM = 9 + 1;
string v = "0255456376", dp[MAXN];
string f[MAXM];
string Max(string a, string b)
{
	int n = a.size(), m = b.size();
	if(n == m)
	{
		for(int i = 0; i < n; ++i)
		{
			if(a[i] > b[i])return a;
			else return b;
		}
		return a;
	}
	else
	{
		if(n > m)return a;
		else return b;
	}
}
int main()
{
	// freopen("match.in", "r", stdin);
	// freopen("match.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	dp[0] = "";
	for (int i = 1; i <= m; ++i)
	{
		cin >> f[i];
		
	}sort(f + 1, f + 1 + m);
	
	for (int i = 1; i <= m; ++i)
	{// using f[i] as this number.
		
		for(int vv = v[f[i][0] - '0'] - '0'; vv <= n; ++vv)
		{
			
			if((!dp[vv - v[f[i][0] - '0'] + '0'].empty()) || vv - v[f[i][0] - '0'] + '0' == 0)
			{
				dp[vv] = Max(f[i] + dp[vv - v[f[i][0] - '0'] + '0'], dp[vv]);
				//cout<<dp[vv]<<" ";
			}
		}
	}
	cout << dp[n];
}
