/*
## [Problem](http://usaco.org/index.php?page=viewproblem&cpid=1264)

## Hint

DFS+二进制优化

~除了装B就没用的优化(甚至是负优化)~

可以"增加代码简洁度", "防止爆栈"(笑). 该优化适用于搜索树为二叉树的搜索. 

枚举状态 $S \in (0,2^m]$ 若二进制下第 $i$ 位为 $0$ 代表使用这台空调, 否则不用. 
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
int n,m,c[MAXL],lim[MAXL],cost=0xffffff,dfs;
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
    if(dfs&(1<<(i-1)))
    {
      AddArr(c,a[i].s, a[i].e,a[i].t);
      __cost+=a[i].c;
    }
  for(int i=1;i<=MAXL-7;++i)
    if(c[i]<lim[i])return -1;
  return __cost;
}
void DFS()
{
  int maxDFS=(1<<m);
  for(dfs=1;dfs<=maxDFS;++dfs)
  {
    int c=check();
    if(c==-1)continue;
    else
    {
      cost=min(cost,c);
    }
  }
}
int main()
{
  Input();
  DFS();
  cout<<cost;
}

/*
![](../Pic/ResultB.png)
*/