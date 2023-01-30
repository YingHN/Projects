#include<bits/stdc++.h>
using namespace std;
int fa[2000];
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(x);
}
int main()
{
	int n, m;
	cin>>n>>m;
	while(m--)
	{
		int x, y, k;
		bool f = false, ff = false;
		cin>>x>>y>>k;
		fa[find(x)] = fa[find(y)];
		for(int i = 1; i <= n; ++i)
		{
			if(f == true)
			{
				ff = true;
				break;
			}
			if(fa[i] == i)f = true;
		}
		if(ff)
		{
			cout<<k;
			return 0;
		}
	}
}

