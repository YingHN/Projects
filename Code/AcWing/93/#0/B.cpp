#include<bits/stdc++.h>
using namespace std;

const long long int MAXN=19+1,INF=0xffff;

long long int n,x,cnt=-1,tCnt=-1,ans=INF;
int num[MAXN],tNum[MAXN];

void upI()
{
  x=0;
  for(int i=0;i<cnt;x*=10,x+=num[i],++i);
}
void upC()
{
  cnt=-1;
  for(int xx=x;xx;num[++cnt]=xx%10,xx/=10);
  sort(num,num+cnt,greater<int>());
}
void DEBUG()
{
  cout<<"X:  "<<x<<"\n";
  cout<<"Num:";
  for(int i=0;i<=cnt;++i)cout<<num[i]<<"|";
  cout<<"\n";
}
auto f(int deepth)
{
  DEBUG();
  if(cnt>=n-1)
  {
    ans=ans<deepth?ans:deepth;
    //cout<<"*"<<ans<<"*";
    return;
  }
  for(int i=0;i<=cnt;++i)
  {
    if(num[i]==1 || num[i]==0)continue;
    int xx=x;
    x*=num[i],upC();
    f(deepth+1);
    x=xx,upC();
  }
  return;
}

int main()
{
  cin>>n>>x;
  upC();
  DEBUG();
  f(0);
  if(ans==INF)cout<<-1;
  else
  {
    cout<<ans;
  }

}