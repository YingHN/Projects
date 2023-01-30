#include <bits/stdc++.h>
using namespace std;
#define MAXN 30
#define MAXV 20000
int V, a[MAXN], n, dp[MAXV];
int main()
{
  cin >> V >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  sort(a, a + n - 1, [](int x, int y)
       { return x > y; });
  for (int i = 0; i < n; ++i)
  {
    for (int v = V; v >= a[i]; --v)
    {
      dp[v] = max(
          dp[v - a[i]] + a[i] // get
          ,
          dp[v] // don't get
      );
    }
  }
  cout << V - dp[V];
  getchar();
  getchar();
}