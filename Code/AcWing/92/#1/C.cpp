#include<bits/stdc++.h>
using namespace std;

int d,n,fa[1001];
vector<int> sz(1001);
int find(int x)
{
  return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
  cin>>d;
  int op=0;
  for(int i=1;i<=d;++i)
  {
    int x,y;
    cin>>x>>y;
    int a=find(x),b=find(y);
    if(a!=b)fa[a]=b,sz[b]+=sz[a];
    else ++op;
    vector<int> v;v.clear();
    for(int j=1;j<=n;++j)
    {
      if(fa[j]==j)
      {
        v.push_back(sz[j]);
      }
    }
    sort(v.begin(),v.end(),greater<int>());
    int ans=-1;
    for(int j=0;j<=op&&j<v.size();++j)
    {
      ans+=v[j];
    }
    cout<<ans<<"\n";
  }

}

//AC