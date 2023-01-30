#include<bits/stdc++.h>
using namespace std;
int s[5];
const int MAXS = 100000, INF = 1e9 + 1;
int v[MAXS], tot;
bitset<MAXS> dp[5];
int main()
{
	int ans = 0;
    cin>>s[1]>>s[2]>>s[3]>>s[4];
    for(int k = 1; k <= 4; ++k)
    {
    	int tot = 0;
        for(int i = 1; i <= s[k]; ++i)
        {
            cin>>v[i];
            tot += v[i];
        }
        dp[k][0] = 1;
        for(int i = 1; i <= s[k]; ++i)
        {
        	for(int vv = tot; vv >= v[i]; --vv)
        	{
        			dp[k][vv] |= dp[k][vv - v[i]];
			}
		}
		int tmp = INF, res = -1;
		for(int i = tot; i >= 0; --i)
		{
			if(dp[k][i])
			{
				if(abs(tot - 2 * i) < tmp)
					tmp = abs(tot - 2 * i), res = max(i, tot - i);
			}
		}
		ans += res;
    }
    cout<<ans;
}
/**************************************************************
    Problem: 1373
    User: xz202201
    Language: C++
    Result: AC
    Time:7 ms
    Memory:2540 kb
****************************************************************/
