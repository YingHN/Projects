#include<bits/stdc++.h>
using namespace std;
string ans;
void f()
{
  string str;
  if(!(cin>>str))
  {
    ans="0";
    return;
  }
  if(str=="int")return;
  else
  {
    ans+="pair<";
    f();
    ans+=",";
    f();
    ans+=">";
  }
  return;
}

int main()
{
  scanf("%*d");
  f();
  if(scanf("%*s")!=-1&&ans[0]==0)cout<<"Error occurred";
  else cout<<ans;
}