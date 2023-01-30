#include <bits/stdc++.h>
#define LL long long
#define maxn 5005
using namespace std;
LL Ti, Boss, Ret, T, N, Ans;
struct ad
{
	LL w;// 攻击间隔
	int id;
	bool operator<(const ad &b) const { return (w < b.w) || (w == b.w && id < b.id); }
} a[maxn];
inline LL read()
{
	LL res = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		res = res * 10 + ch - 48, ch = getchar();
	return res * f;
}
bool check(LL now)// 能否杀死boss
{
	LL res = 0;// 所有鸡的伤害大小
	for (int i = 1; i <= N; i++)
		res += //
			now / a[i].w - // 到目前为止鸡#i的伤害大小
			Ti / a[i].w; // 重生前这只鸡#i的伤害大小, 此伤害**作废**(减去)
	return res >= Boss;
}
void work()
{
	LL all = 0; // 累加杀死boss前一时刻的伤害
	for (int i = 1; i <= N; i++)
		all += (Ret - 1) / a[i].w - Ti / a[i].w;
	
	for (int i = 1; i <= N; i++)
		if (!(Ret % a[i].w)) 
		// 若杀死boss时, 轮到鸡#i攻击, 则
		{
			all++; // 鸡#i攻击
			if (all == Boss) //正好杀死boss
			{
				Ans = a[i].id;
				return;
			}
		}
}
int main()
{
	// freopen("boss.in", "r", stdin);
	// freopen("boss.out", "w", stdout);
	T = read();
	while (T--)
	{
		N = read(), Ti = read(), Boss = read();
		for (int i = 1; i <= N; i++)
			a[i].w = read(), a[i].id = i;
		sort(a + 1, a + 1 + N);
		Ret = -1; // 在二分中记录是否得到过杀死boss的时间mid
		LL L = 1, R = 1e+18; 
		// 对于题目中有"...到...为止"条件
		// 如本题, "到1e18为止, 若仍不能杀死boss, 输出-1"
		// 一定是**二分**
		
		// 二分中, 要灵活运用边界条件(如本题的FUNC check)
		while (L <= R)
		{
			LL mid = R + L >> 1;
			if (check(mid)) // 若在mid时刻时(或前)能杀死boss, 缩短攻击时间
				R = mid - 1, Ret = mid;
			else // 若在mid时刻时不能杀死boss, 加长攻击时间
				L = mid + 1;
		}
		if (Ret == -1) // 未得到杀死boss的时间
		{
			printf("-1\n");
			continue;
		}
		// 得到Ret, 既杀死boss的时间
		work(), printf("%d\n", Ans - 1);
	}
	return 0;
}
