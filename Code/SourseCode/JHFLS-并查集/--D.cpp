#include<bits/stdc++.h>
using namespace std;
int fa[100001], size[100001];
map<string, int> key;
inline int find(int &x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline void unite(int &x, int &y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy)return;
	if(size[x] < size[y])
	{
		fa[fx] = fa[fy];
		size[fx] += size[fy];
	}
	else
	{
		fa[fy] = fa[fx];
		size[fy] += size[fx];
	}
	return;
}
int main()
{
	int n, m, q;
	cin>>n>>m>>q;
	for(int i = 1; i <= n; ++i)
	{
		char tmp[12];
		cin>>tmp;
		key.insert(pair<string, int>{tmp, i});
		fa[i] = i;
		size[i] = 1;
	}
	while(m--)
	{
		char tmp1[12], tmp2[12];
		cin>>tmp1>>tmp2;
		fa[find(key[tmp1])] = fa[find(key[tmp2])];
	}
	while(q--)
	{
		char tmp1[12], tmp2[12];
		cin>>tmp1>>tmp2;
		if(find(key[tmp1]) == find(key[tmp2]))cout<<"safe\n";
		else cout<<"cc cry\n";
	}
}

