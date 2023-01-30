#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353, MAX = 1e5 + 1;
unsigned long long f(unsigned long long x)
{
	x ^= x << 19;
	x ^= x >> 8;
	x ^= x << 9;
	x ^= x >> 6;
	x ^= x << 4;
	return x;
}

struct NODE
{
	int l, r;
	mutable int k;
	NODE(int L, int R = 0, int K = 0) : l(L), r(R), k(K) {}
	bool operator < (const NODE &x) const
	{
		return l < x.l;
	}
};
set<NODE> s;
auto split(int pos)
{
	auto it = s.lower_bound(NODE(pos));
	if(it != s.end() && it->l == pos)
		return it;
	--it;
	if(it->r < pos)
		return s.end();
	int l = it->l, r = it->r, k = it->k;
	s.erase(it);
	s.insert(NODE{l, pos - 1, k});
	return s.insert(NODE{pos, r, k}).first;
}
int ans;
void upd(int l, int r, int k)
{
	auto R = split(r + 1), L = split(l);
	for(auto it = L; it != R; ++it)
	{
		ans = (ans + (f(abs(it->k - k)) % MOD) * ((it->r - it->l + 1) % MOD) % MOD) % MOD;
	}
	s.erase(L, R);
	s.insert(NODE{l, r, k});
}
int main()
{
	
	int n, m, typ;
	cin>>n>>m>>typ;
	s.insert(NODE{1, n, 0});
	while(m--)
	{
		int l, r, k;
		cin>>l>>r>>k;
		upd(l, r, k);
	} 
	if(typ == 1)
	{ 
		cout<<split(n)->k;
	}
	else
	{
		cout<<ans;
	}
}
