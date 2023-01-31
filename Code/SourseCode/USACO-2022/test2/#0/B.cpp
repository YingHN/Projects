/*
## [Problem](http://usaco.org/index.php?page=viewproblem&cpid=1264)

## Hint

暴搜
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20+7,MAXL=100+7;
int maxL;
struct Cow
{
  int s,e,t;
}cow[MAXN];
struct AirCondition
{
  int s,e,t,c;
}a[MAXN];
int n,m,c[MAXL],lim[MAXL],cost=0xffffff;
bool dfs[MAXN];
void AddArr(int arr[],int l, int r,int var)
{
  for(int i=l;i<=r;++i)
    arr[i]+=var;
}
void Input()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i)
  {
    cin>>cow[i].s>>cow[i].e>>cow[i].t;
    maxL=max(maxL,cow[i].e);
    AddArr(lim,cow[i].s,cow[i].e,cow[i].t);
  }
  
  for(int i=1;i<=m;++i)
  {
    cin>>a[i].s>>a[i].e>>a[i].t>>a[i].c;
    maxL=max(maxL, a[i].e);
  }
}
int check()
{
  int __cost=0;
  memset(c,0,sizeof c);
  for(int i=1;i<=m;++i)
    if(dfs[i])
    {
      AddArr(c,a[i].s, a[i].e,a[i].t);
      __cost+=a[i].c;
    }
  for(int i=1;i<=MAXL-7;++i)
    if(c[i]<lim[i])return -1;
  return __cost;
}
void DFS(int id)
{
  if(id>m+1)return;
  int ch=check();
  if(ch!=-1)
  {
    cost=min(cost,ch);
    return;
  }
  
  dfs[id]=true;DFS(id+1);
  dfs[id]=false;DFS(id+1);
}
int main()
{
  Input();
  DFS(1);
  cout<<cost;
}

/*
![](../Pic/ResultB.png)
*/