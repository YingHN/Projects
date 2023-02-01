/*
## [Problem](http://usaco.org/index.php?page=viewproblem&cpid=1263)

## Hint

本题是**哲学**题. 

### 核心性质

对于"管辖到同品种的所有奶牛"的领袖, 

! 每个品种只有一个且定是从左到右第一个该品种奶牛. 

(可能不存在)

> 例如(SimpleInput1): 品种H的领袖"管辖到同品种的所有奶牛", 这位领袖一定唯一(id=2)

因此统计能管辖到所有奶牛的领袖对(p,q)共有两种情况:

1. p,q均能管辖到同品种的所有奶牛(只有一对);
2. q能管辖同品种的所有奶牛, p能管辖到q(有很多对); 

*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int n, totG, totH, leaderG = -1, leaderH = -1, ans = 0;
char cow[MAXN];
int e[MAXN], preG[MAXN], preH[MAXN];
void Input()
{
  cin >> n >> cow + 1;
  for (int i = 1; i <= n; ++i)
    cin >> e[i];
}
inline void MakePre()
{
  for (int i = 1; i <= n; ++i)
  {
    preG[i] = preG[i - 1], preH[i] = preH[i - 1];
    if (cow[i] == 'G')
      preG[i]++;
    if (cow[i] == 'H')
      preH[i]++;
  }
  totG = preG[n], totH = preH[n];
}
inline int GetSumG(int l, int r)
{
  return preG[r] - preG[l - 1];
}
inline int GetSumH(int l, int r)
{
  return preH[r] - preH[l - 1];
}
inline int Find(int id)
{
  int __ans = 0;
  for (int i = 1; i < id; ++i)
  {
    if (cow[i] == cow[id])
      continue;
    if (e[i] >= id)
      ++__ans;
  }
  return __ans;
}
int main()
{
  Input();
  MakePre();
  for (int i = 1; i <= n; ++i)
  {
    if (cow[i] == 'G' && GetSumG(i, e[i]) == totG)
      leaderG = i;
    if (cow[i] == 'H' && GetSumH(i, e[i]) == totH)
      leaderH = i;
  }

  // case 1
  if (leaderG != -1 && leaderH != -1)
    ++ans;
  
  // case 2
  if (leaderG != -1)
    ans += Find(leaderG);
  if (leaderH != -1)
    ans += Find(leaderH);
  cout << ans;
}

/*
![](../Pic/ResultA.png)
*/