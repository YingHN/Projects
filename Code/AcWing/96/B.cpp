#include<bits/stdc++.h>
using namespace std;
const int MAXN =10+7;
int dp[MAXN]={0},n,m,v[MAXN],w[MAXN],t[MAXN];
int main()
{
  cin>>n>>m>>v[0]>>w[0];
  t[0]=n/v[0];
  for(int i=1;i<=m;++i)
  {
    int l,h;
    cin>>l>>h>>v[i]>>w[i];
    t[i]=(int)l/h;
  }
  
  for(int i=0;i<=m;++i)
  {
    for(int vv=n;vv>=v[i];--vv)
    {
      for(int k=0;k<=t[i];++k)
      {
        if(vv-k*v[i]>=0)
          dp[vv]=max(dp[vv],dp[vv-k*v[i]]+k*w[i]);
      }
    }
  }
  cout<<dp[n];
}