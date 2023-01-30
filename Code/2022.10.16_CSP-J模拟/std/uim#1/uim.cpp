#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 805, maxm = 17, tt = 1000000007;
int n, m, k, a[maxn][maxn], f[maxn][maxn][maxm][2];
long long int ans;
// f[x][y][p][x]: when reach (x, y)(both start at 1), their difference is p,
// x = 0 means this step is by uim, x = 1 means by A
// following, I use the code over
inline int read()//Fast-IO
{
	int ret = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
int main()
{
	freopen("uim.in", "r", stdin);
	freopen("uim.out", "w", stdout);
	n = read(), m = read(), k = read() + 1;
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= m; ++y)
			a[x][y] = read(), f[x][y][a[x][y]][1] = 1;
			// when p = a[x][y] and it's A's turn, after A eating, it gets an answer
	// start to DP
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= m; ++y)
		// enumerate the (x, y)
			for (int t = 0; t < k; ++t)
			// enumerate the number of sth we have eaten
			{
				// this state'll be the sum of the number of the ways up and left

				// now for the first situation: A's turn
				if (y != 1)// the state can come from the up
					f[x][y][t][1] = 
						(f[x][y][t][1] + f[x][y - 1][(t - a[x][y] + k) % k][0]) % tt;
					// we must add it and the number of ways we math before
					// the number of the ways up must minus sth we have eaten
					//
					// why we plus a "k" ?
					// when the negative things happened, 
					// add a "k" can find the state which has the same effect
					// therefore, when it is positive, we find that k disappear!
					// when it is negative, obviously(t - a[x][y] + k) > 0, k turn the state, 
					// but k disappear, too!
					// you can take an example
				if (x != 1)// the state can come from the left
					f[x][y][t][1] = 
						(f[x][y][t][1] + f[x - 1][y][(t - a[x][y] + k) % k][0]) % tt;
				
				// now for the other situation: Uim's turn
				if (y != 1)
					f[x][y][t][0] = 
						(f[x][y][t][0] + f[x][y - 1][(t + a[x][y]) % k][1]) % tt;
					// why we use "+" but not "-"?
					// p = u - a, when p = 0, we get an answer.
					// so...
					// besides, there no way for (t + a[x][y]) to change into a nagetive number.
				if (x != 1)
					f[x][y][t][0] = 
						(f[x][y][t][0] + f[x - 1][y][(t + a[x][y]) % k][1]) % tt;
			}
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= m; ++y)
			ans = (ans + f[x][y][0][0]) % tt;
	printf("%d\n", ans);
	return 0;
}
