#include<bits/stdc++.h>
using namespace std;
#define int long long int
int a[100000],d[100000];
signed main()
{
  int n,T;
  cin>>n>>T;
  
  cin>>d[0];
  cin>>a[d[0]];
  int food=a[d[0]],ans=0;
  for(int i=1;i<n;++i)
  {
    cin>>d[i];
    cin>>a[d[i]];
    food+=a[d[i]];
    if(d[i]-d[i-1]>food)
    {
      ans+=food,food=0;
      cout<<ans<<" "<<food<<"*\n";
    }
    else
    {
      food-=d[i]-d[i-1],ans+=d[i]-d[i-1];
      cout<<ans<<" "<<food<<"\n";
    }
  }
  cout<<ans;
}