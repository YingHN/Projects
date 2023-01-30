#include<bits/stdc++.h>
#include<vector>
#include<utility>
using namespace std;

void TRCT(int node, vector<int>& dp, vector<vector<pair<int, int> > > trarr)
{
	if(trarr[node].size() == 0)
	{
		dp[node] = 1;
		return;
	}
	if(dp[node] != -1) return;
	
	int temp;
	for(int i = 1; i <= trarr[node].size(); i++)
	{
		TRCT(i, dp, trarr, n); 
		
		int child = trarr[node][i].first;
		int f = dp[child] + trarr[node][i].second;
		
		if(temp < f)temp = f;
	}
	dp[node] = temp;
	return;
}
pair<int, int> TrCt(int root, vector<vector<pair<int, int> > > trarr, int n)
{
	vector<int> dp(n + 1, -1);
	TRCT(root, dp, trarr);
	
	int l = 0xffffff, ord;
	for(int i = 1; i <= n; i++)
		if(dp[i] < l)l = dp[i], ord = i;
	pair<int, int> ans;
	ans.first = l;
	ans.second = ord;
	return ans;
}
int main()
{
}

