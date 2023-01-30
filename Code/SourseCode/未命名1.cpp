#include<bits/stdc++.h>
#include<vector>
#include<utility>
using namespace std;
void TRLS(int node, vector<pair<int, int> >& dp, vector<vector<pair<int, int> > > trarr)
{
	if(trarr[node].size() == 0)
	{
		dp[node].first = 1;
		dp[node].second = 0;
		return;
	}
	if(dp[node].first != -1) return;
	
	pair<int, int> temp;
	for(int i = 1; i <= trarr[node].size(); i++)
	{
		TRLS(i, dp, trarr, n); 
		
		int child = trarr[node][i].first;
		int f = dp[child].first + trarr[node][i].second;
		
		if(temp.first < f)temp.second = temp.first, temp.first = f;
		else if(temp.second < f)temp.second = f;
	}
	dp[node] = temp;
	return;
}
int TrLS(int root, vector<vector<pair<int, int> > > trarr, int n)
{
	vector<pair<int, int> > dp(n + 1, pair<int, int> (-1, -1));
	TRLS(root, dp, trarr, n);
	
	int ans = -1;
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[i].first + dp[i].second);
	
	return ans;
}
int main()
{
	
}
