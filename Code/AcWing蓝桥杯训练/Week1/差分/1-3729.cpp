#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+7;
int n,a,v[MAXN],diff[MAXN];
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    cin>>n;
    for(int i=1;i<=n;++i)
    {
      cin>>a;
      diff[i-a]+=1;
      diff[i+1]-=1;
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
      ans+=diff[i];
      cout<<(bool)ans;
    }
  }
}