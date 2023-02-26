#include<bits/stdc++.h>
using namespace std;
int fuck[(int)(1e5+1)];
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;++i)
  {
    int a,b;
    cin>>a>>b;
    for(int j=a;j<=b;++j)
    {
      ++fuck[j];
    }
  }
  for(int i=1;i<=n;++i)
  {
    if(fuck[i]==1)continue;
    cout<<i<<fuck[i]<<"\n";
    return 0;
  }
  cout<<"OK";
}