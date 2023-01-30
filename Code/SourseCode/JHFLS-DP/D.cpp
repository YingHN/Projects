#include<bits/stdc++.h>
using namespace std;
int a[100], tot, dp[10001];
// dp[wt]: 表示在石子重量容量为wt时最大的的石子重量
// 此题思路是将石子均分为2份, 每一份的石子重量越接近石子总重量的一半, 
// 则差值最小. 
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>a[i];
        tot = tot + a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int wt = tot / 2; wt >= a[i]; --wt)
        {
            dp[wt] = max(dp[wt], dp[wt - a[i]] + a[i]);
        }
    }
    cout<<tot - 2 * dp[tot / 2];
}
