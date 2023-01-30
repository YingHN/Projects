#include <bits/stdc++.h>
using namespace std;
#define int long long
inline char gc() // 快读
{
	static const int Len = 1000000;
	static char buf[Len], *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, Len, stdin), (s == t ? -1 : *s++) : *s++);
}
inline int read() // 快读
{
	int x = 0, f = 1;
	char ch = gc();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + ch - 48, ch = gc();
	return x * f;
}
inline void write(int x)// 快写
{
	if (!x)
		putchar('0');
	if (x < 0)
		x = -x, putchar('-');
	int cnt = 0, a[30];
	while (x)
		a[++cnt] = x % 10, x /= 10;
	while (cnt--)
		putchar(a[cnt + 1] + '0');
}
#define rd read()
#define pb push_back
#define ptc putchar
#define mk make_pair
unsigned long long f(unsigned long long x)
{
	x ^= x << 19;
	x ^= x >> 8;
	x ^= x << 9;
	x ^= x >> 6;
	x ^= x << 4;
	return x;
}
int Abs(int x) { return x < 0 ? (-x) : x; } // 绝对值
const int N = 1e5 + 5, mod = 998244353;
int n, m, typ, ans;
struct node // 区间节点
{
	int l, r; // ! 区间范围[l, r), 左闭右开
	// mutable: 强制变量可变, 即使在const函数中
	// 便于修改区间值
	mutable int k; // 区间值
	node(int L, int R = 0, int K = 0) : l(L), r(R), k(K) {}
	// 提前给R, K赋值, 使R, K在构造时可以不传入, 使用默认值
	// 构造函数, 在构造结构体时调用
	bool operator<(const node &x) const
	// 重载运算符
	{
		return l < x.l;
	}
};
set<node> s;
auto split(int pos)
// 将原本包含点#pos的区间(设为[l, r))分裂为两个区间[l, pos - 1]和[pos, r), 
// 并返回指向后者的迭代器
{
	auto it = s.lower_bound((node)(pos));
	// lower_bound(x): 返回首个大于等于x的元素的迭代器
	// 若没有找到, 返回end()("大于等于"在源码中使用运算符<, 因此只需重载运算符<)
	// 这里用于找到点#pos**所在的区间**
	// ~~因此, 类型最好用auto~~
	if (it != s.end() && it->l == pos)
	// "lower_bound()能找到区间#it"且"点#pos在区间#it的左端点"
		return it;
	--it;
	if (it->r < pos)
		return s.end();
	int l = it->l, r = it->r, k = it->k;
	s.erase(it);
	s.insert((node){l, pos - 1, k} /* 调用构造函数构造node */ );
	return s.insert((node){pos, r, k}).first;
	// insert()的返回值类型为pair<iterator, bool>, 
	// 其中iterator是一个指向所插入元素的迭代器, 
	// 而bool则代表元素是否插入成功
}
void upd(int l, int r, int k)
// 把[l, r)的所有区间权值更改为k, 
// 形成新区间
{
	auto R = split(r + 1), L = split(l);
	// ! **必须先分裂右区间再分裂左区间**
	// 在split()中, 点#pos在右端点时, 会修改区间; 在左端点时, 会直接返回. 
	// 而对于修改区间前的迭代器, 修改区间后便会失效, 
	// 所以必须先修改区间
	
	for (auto it = L; it != R; ++it) // 在更新时顺便求出感恩值总数
	// 遍历每一个[L, R)的区间
	{
		ans = (ans + (f(Abs(k - it->k)) % mod) * (it->r - it->l + 1) % mod) % mod;
		// f(Abs(k - it->k)): 此区间内每个黑人的感恩值
		// (it->r - it->l + 1): 此区间的黑人个数
	}

	s.erase(L, R); // 删除[L, R)中的所有区间
	s.insert((node){l, r, k}); // 插入新区间
}
signed main()
{
	n = rd, m = rd, typ = rd;
	s.insert((node){1, n, 0});
	while (m--) 
	{
		int l = rd, r = rd, k = rd;
		upd(l, r, k);
	}
	if (typ == 2)
		printf("%lld", ans);
	else
	{
		auto x = split(n); // 或许可以用s.end()
		printf("%lld", x->k);
	}
	return 0;
}
