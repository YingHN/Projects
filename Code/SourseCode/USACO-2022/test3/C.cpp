#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = 1e14 + 1;
int n, k, a[2], ans;
signed main()
{
  cin >> n >> k;
  int now,lst;bool flag=1;
  for (int i = 0; i < n; ++i)
  {
    now = i & 1, lst = (i + 1) & 1;
    cin >> a[now];
    int days = a[now] - a[lst] + 1;
    if (i == 0)
      days = 1;

    if (days > k)
    {
      // if(i==0)continue;
      ans += 1,flag=1;
      //cout << "s" << a[lst] << "s";
    }
    else
    {
      if (i == 0)
        continue;
      ans += days - k,flag=0;
      //cout << "o" << days << "o";
    }
    ans += k;
  }
  if(flag)++ans;
  cout << ans + k;
}