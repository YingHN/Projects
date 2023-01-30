#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MAXN = 1e5 + 1;
int a[MAXN];
struct NODE
{
	int sum, tag = 0;
}tr[MAXN << 2];
void build(int l, int r, int id)
{
	if(l == r)
	{
		tr[id].sum = a[l];
		return;
	}
	int m = ((r - l) >> 1) + l;
	build(l, m, id << 1), build(m + 1, r, (id << 1) + 1);
	tr[id].sum = tr[id << 1].sum + tr[(id << 1) + 1].sum;
}
void psd(int l, int r, int id)
{
	int m = ((r - l) >> 1) + l, ls = id << 1, rs = (id << 1) + 1;
	tr[ls].tag += tr[id].tag, tr[rs].tag += tr[id].tag;
	tr[ls].sum += (m - l + 1) * tr[id].tag;
	tr[rs].sum += (r - m) * tr[id].tag;
	tr[id].tag = 0;
}
int ask(int L, int R, int l, int r, int id)
{
	if(L <= l && R >= r)return tr[id].sum;
	int left = id << 1, right = (id << 1) + 1, m = ((r - l) >> 1) + l, sum = 0;
	psd(l, r, id);
	if(L <= m)sum += ask(L, R, l, m, left);
	if(R > m)sum += ask(L, R, m + 1, r, right);
	return sum;
}
void upd(int L, int R, int k, int l, int r, int id)
{
	if(L <= l && R >= r)
	{
		tr[id].tag += k;
		tr[id].sum += k * (r - l + 1);
		return;
	}
	int left = id << 1, right = (id << 1) + 1, m = (r - l) >> 1 + l, sum = 0;
	psd(l, r, id);
	if(L <= m)upd(L, R, k, l, m, left);
	if(R > m)upd(L, R, k, m + 1, r, right);
	tr[id].sum = tr[left].sum + tr[right].sum;
}
signed main()
{
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	build(1, n, 1);
	while(m--)
	{
		int typ, l, r;
		cin>>typ>>l>>r;
		if(typ == 1)
		{
			int k;
			cin>>k;
			upd(l, r, k, 1, n, 1);
		}
		if(typ == 2)
		{
			cout<<ask(l, r, 1, n, 1)<<endl;
		}
	}
}
