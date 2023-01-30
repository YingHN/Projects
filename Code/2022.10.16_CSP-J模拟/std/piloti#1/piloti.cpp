#include <bits/stdc++.h>
#define maxn 200005
#define LL long long
using namespace std;
int N;
LL Ans;
inline int read()
{
	int ret = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}
priority_queue<int> q; // 优先队列(小顶堆)保存升职加薪的数量 => 保证升职时花费最小
int main()
{
	//freopen("piloti.in", "r", stdin);
	//freopen("piloti.out", "w", stdout);
	N = read();
	for (int i = 1; i <= N; i++)
	{
		int x = read(), y = read();
		Ans += x, q.push(y - x);
		if (i & 1)				// i是奇数 => 偶数取助手, 奇数取机长.
			Ans += q.top(); // 升职
	}
	printf("%lld\n", Ans);
	return 0;
}
