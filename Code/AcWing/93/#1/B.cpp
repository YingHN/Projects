/*
简单`DFS+剪枝`, (目前来说)剪枝逃不开以下几种情况: 
1. 无效性剪枝: 对 0 or 1 不操作. 
2. 最优性剪枝: 当深度已经超过之前的最优答案, 不必操作. 

但是这样还是不能过. 

3. **启发式剪枝**: 
   用"启发式评估函数"否定非最优解. 
   即, 当"当前代价+评估下最优后续操代价 不好于 现有最优解", 
   那么不必操作. 
   关键是评估函数, 必须满足充分性和必要性, 
   这里采用了"剩余数位", 因为最优情况下, 
   一次操作增加一个数位. 

启发式剪枝在这里可以替代最优性剪枝. 

为保证思维的体现, 使用了若干专业术语; 
部分思路来源于y总讲解;
有错请指出; 
本人初二, 能力有限, 请谅解. 
*/

#include<bits/stdc++.h>
using namespace std;

const long long int MAXN=19+1,INF=9223372036854775807LL;

long long int n,xx,ans=INF;
auto f(int deepth, long long int x)
{
  bool st[12]={0};// 桶自动去重
  int cnt=0; // 统计数位
  for(long long int y=x;y;++cnt,st[y%10]=true,y/=10);
  // 这里y要用long long. 我TM排了好久...无语. 
  // 熟悉的小调再次响起, 
  // "十年~OI~一场空~~, 不开~longlong~见祖宗~~. "
  
  if(cnt>=n)
  {
    ans=ans>deepth?deepth:ans;
    //cout<<ans<<","<<x<<"\n"; //DEBUG
    return;
  }
  if(deepth+n-cnt>=ans)return;// 启发式剪枝
  
  for(int i=9;i>=2;--i)
    if(st[i])
      f(deepth+1,x*i);
  // 大数优先, 使局部最优
  // 但是此题有后效性, 局部最优不一定全局最优
  // 比方样例3. 
}

int main()
{
  cin>>n>>xx;
  f(0,xx);
  if(ans==INF)cout<<-1;
  else
  {
    cout<<ans;
  }

}