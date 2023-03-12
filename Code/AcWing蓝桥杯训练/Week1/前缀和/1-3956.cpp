#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+7;
int n,sum[MAXN],total,tot;
int main()
{
  cin>>n;
  for(int i=1;i<=n;++i)
  {
    int a;
    cin>>a;
    sum[i]=sum[i-1]+a;
  }total=sum[n];
  if(total%3!=0||n<3)
  {
    cout<<0;
    return 0;
  }
  tot=total/3;
  long long int ans=0,t=0;
  // ans: [1,n]分段点#2的所有可能位置数
  // t: [1,i)内分段点#1的所有可能位置数
  for(int i=2;i<n;++i) 
  // i<n, 保证最后段非空
  {
    if(sum[i-1]==tot)++t;
    if(sum[i]==2*tot)ans+=t;
  }
  cout<<ans;
}