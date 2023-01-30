#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int MAXN = 1e5 + 7;
int n;
ll c[MAXN];
struct LEVEL
{
	int perC=0,num=1;
	operator< (const LEVEL &x) const
	{
		return x.perC*x.num > perC*num;
	}
};
priority_queue<LEVEL> q;
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin>>n;
	LEVEL temp;
	for(int i=0;i<n;++i)
		cin>>c[i];
	sort(c,c+n);
	for(int i=0;i<n;++i)
	{
		if(c[i]==c[i-1])
		{
			++temp.num;
		}
		if(c[i]!=c[i-1])
		{
			temp.perC=c[i-1];
			q.push(temp);
			temp.num=1,temp.perC=c[i];
		}
	}
	q.push(temp);
	LEVEL ans;ans.num=0,ans.perC=0;
	while(!q.empty())
	{
		LEVEL now=q.top();q.pop();
//		cout<<now.num<<" "<<now.perC<<"\n";
		if((now.num+ans.num)*now.perC>=ans.num*ans.perC)
		{
			ans.num+=now.num, ans.perC=now.perC;
//			cout<<"*";
		}
		else
		{
			cout<<ans.num*ans.perC<<" "<<ans.perC<<"\n"; 
			return 0;
		}
	}
	cout<<ans.num*ans.perC<<" "<<ans.perC<<"\n";
}

