#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+7;
int n,sum[MAXN],total,tot;
int f(int st,int deepth)
{
  if(deepth>3)return 1;
  int ans=0;
  for(int i=st;i<=n;++i)
  {
    if(sum[i]-sum[st]==tot)
    {
      ans+=f(i,deepth+1);
    }
  }
  return ans;
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;++i)
  {
    int a;
    cin>>a;
    sum[i]=sum[i-1]+a;
  }total=sum[n];
  if(total%3!=0)cout<<0;
  tot=total/3;
  f(1,1);
}