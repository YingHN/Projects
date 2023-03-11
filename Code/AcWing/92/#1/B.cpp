#include<bits/stdc++.h>
using namespace std;
string ans;
bool flag=1;
void f()
{
  string str;
  if(!(cin>>str))
  {
    flag=0;
    return;
  }
  ans+=str;
  if(str=="int")return;
  else
  {
    ans+="<";
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
  if(scanf("%*s")!=-1||flag==false)cout<<"Error occurred";
  else cout<<ans;
}

// AC