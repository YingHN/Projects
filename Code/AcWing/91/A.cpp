#include<bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(--T)
  {
    int n;
    cin>>n;
    int i,nn=n,k=0;
    while(nn)
    {
      if(nn%10)++k;
      nn/=10;
    }
    cout<<k<<"\n";
    for(i=0;n;++i)
    {
      int k=n%10;
      n/=10;
      if(k==0)continue;
      cout<<k;
      for(int j=0;j<i;++j)
      {
        cout<<0;
      }
      cout<<" ";
    }
    cout<<"\n";
    
  }
}