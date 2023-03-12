#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+7;
int n,a[MAXN];
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    cin>>n;
    int V=0;
    for(int i=0;i<=n;++i)
    {
      cin>>a[i];
      V<<=1;
      int aa=(int)pow(2,a[i])-1;
      if(aa>=V)V=(int)pow(2,i)-1;
      V|=aa;
    }
    while (V)
    {
      cout<<(V&1);
      V>>=1;
    }
    cout<<"\n";
  }
}