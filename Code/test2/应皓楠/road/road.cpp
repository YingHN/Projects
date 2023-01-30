#include<bits/stdc++.h>
using namespace std;

int k;
int main()
{
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	int n;
	cin>>n>>k;
	if(n <= k)
	{
		cout<<k;
		return 0;
	}
	int ans = 0, times;
	for(times = 1; n > k / times + 1e-10; times += 2)ans += n, n -= k / times;
	cout<<ceil(ans + n * times);
	//15 11 -> 24
	
//	
//	for(int dis = 0; dis <= n; ++dis)
//	{
//		for(int k = 0; k <= K; ++k)
//		{
//			if(dis <= k)
//			{
//				dp[dis][k] = dis;
//				continue;
//			}
//			dp[dis][k] = INF;
//			int l = 0, r = dis - 1;
////			while(l < r)
////			{
////				int m = (r - l) >> 1 + l;
////				if(dp[dis - i][2*k - 3*m] > dp[dis][k])
////				{
////					dp[dis][k] = dp[dis - m][2*k - 3*m];
////					l = m;
////				}
////				else
////				{
////					r = 
////				}
////			}
//			for(int i = 0; i <= dis; ++i)//²¹¸øµã 
//			{
//				dp[dis][k] = min(dp[dis - i][2*k - 3*i] + 2*i, dp[dis][k]);
//			}
//		}
//	}
//	for(int dis = 0; dis <= n; ++dis)
//	{
//		for(int k = 0; k <= K; ++k)
//		{
//			cout<<dp[dis][k]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<dp[n][K];
}

