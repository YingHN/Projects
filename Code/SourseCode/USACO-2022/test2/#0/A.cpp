#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+7;
int n;
char cows[MAXN];
int lead[MAXN];
int e[MAXN];
int main()
{
  cin >> n >> cows+1;
  
  for (int i = 1; i <= n; ++i)
  {
    cin >> e[i];
    for (int j = 1; j <= n; ++j)
    {
      if(i<=j&&j<=e[i])continue;
      if (cows[j] == cows[i])
      {
          lead[i] = -1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
  {
    cout<<lead[i]<<" ";
    if (lead[i] != -1 && (lead[lead[i]] == i || lead[lead[i]]==0))
      ++ans;
  }
  cout << ans;
}