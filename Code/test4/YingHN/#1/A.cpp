#include<bits/stdc++.h>
using namespace std;
int dp[100000], f[100000], a[100000], ord[100000], Ord[100000];
int main()
{
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		if(dp[i - 1] + a[i] > a[i])
			dp[i] = dp[i - 1] + a[i], ord[i] = ord[i - 1];
		else dp[i] = a[i], ord[i] = i;
	}
	for(int i = n; i >= 1; --i)
		if(f[i + 1] + a[i] > a[i])
			f[i] = f[i + 1] + a[i], Ord[i] = Ord[i + 1];
		else f[i] = a[i], Ord[i] = i;
	for(int i = 1; i <= n; ++i)cout<<(f[i] > dp[i] ? Ord[i] : ord[i])<<" ";
		
}

