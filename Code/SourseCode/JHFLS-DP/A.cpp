#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a[n + 1][n + 1], dp[n + 1][n + 1];
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= i; ++j)
    {
      cin>>a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i)
    dp[n][i] = a[n][i];
  for (int i = n - 1; i >= 1; --i)
  {
    for (int j = 1; j <= i; ++j)
    {
      dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
    }
  }
  /*
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= i; ++j)
    {
      if (i > 1)
      {
        if (j > 1)
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        else
          dp[i][j] = dp[i - 1][j] + a[i][j];
      }
      else
      {
        if (j > 1)
          dp[i][j] = dp[i][j - 1] + a[i][j];
        else
          dp[i][j] = a[i][j];
      }
    }
  }
  */

  cout << dp[1][1];
  getchar();
  getchar();
}