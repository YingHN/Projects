#include <bits/stdc++.h>
using namespace std;

/* --------------- fast io --------------- */ // begin
namespace Fread
{
	const int SIZE = 1 << 21;
	char buf[SIZE], *S, *T;
	inline char getchar()
	{
		if (S == T)
		{
			T = (S = buf) + fread(buf, 1, SIZE, stdin);
			if (S == T)
				return '\n';
		}
		return *S++;
	}
} // namespace Fread
namespace Fwrite
{
	const int SIZE = 1 << 21;
	char buf[SIZE], *S = buf, *T = buf + SIZE;
	inline void flush()
	{
		fwrite(buf, 1, S - buf, stdout);
		S = buf;
	}
	inline void putchar(char c)
	{
		*S++ = c;
		if (S == T)
			flush();
	}
	struct NTR
	{
		~NTR() { flush(); }
	} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
#define getchar Fread ::getchar
#define putchar Fwrite ::putchar
#endif
namespace Fastio
{
	struct Reader
	{
		template <typename T>
		Reader &operator>>(T &x)
		{
			char c = getchar();
			T f = 1;
			while (c < '0' || c > '9')
			{
				if (c == '-')
					f = -1;
				c = getchar();
			}
			x = 0;
			while (c >= '0' && c <= '9')
			{
				x = x * 10 + (c - '0');
				c = getchar();
			}
			x *= f;
			return *this;
		}
		Reader &operator>>(char &c)
		{
			c = getchar();
			while (c == ' ' || c == '\n')
				c = getchar();
			return *this;
		}
		Reader &operator>>(char *str)
		{
			int len = 0;
			char c = getchar();
			while (c == ' ' || c == '\n')
				c = getchar();
			while (c != ' ' && c != '\n' && c != '\r')
			{ // \r\n in windows
				str[len++] = c;
				c = getchar();
			}
			str[len] = '\0';
			return *this;
		}
		Reader() {}
	} cin;
	const char endl = '\n';
	struct Writer
	{
		template <typename T>
		Writer &operator<<(T x)
		{
			if (x == 0)
			{
				putchar('0');
				return *this;
			}
			if (x < 0)
			{
				putchar('-');
				x = -x;
			}
			static int sta[45];
			int top = 0;
			while (x)
			{
				sta[++top] = x % 10;
				x /= 10;
			}
			while (top)
			{
				putchar(sta[top] + '0');
				--top;
			}
			return *this;
		}
		Writer &operator<<(char c)
		{
			putchar(c);
			return *this;
		}
		Writer &operator<<(char *str)
		{
			int cur = 0;
			while (str[cur])
				putchar(str[cur++]);
			return *this;
		}
		Writer &operator<<(const char *str)
		{
			int cur = 0;
			while (str[cur])
				putchar(str[cur++]);
			return *this;
		}
		Writer() {}
	} cout;
} // namespace Fastio
#define cin Fastio ::cin
#define cout Fastio ::cout
#define endl Fastio ::endl
/* --------------- fast io --------------- */ // end

const int MAX = 1e3 + 1, INF = 1e9;
int v[MAX][MAX], w[MAX][MAX], cnt[MAX], dp[MAX];
int main()
{
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int n, m, tmp = 0;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int V, W, K;
		cin >> V >> W >> K;
		tmp = max(K, tmp);
		//v[K][cnt[K]++] = i;
		v[K][cnt[K]] = V;
		w[K][cnt[K]++] = W;
	}
	for (int k = 1; k <= tmp; ++k)
	{ // the #k team
		for (int vv = n; vv >= 0; --vv)
		{ // as use V of vv
			for (int i = 0; i < cnt[k]; ++i)
			{ // the #i obj
				if(vv < v[k][i])continue;
				dp[vv] = max(dp[vv - v[k][i]] + w[k][i], dp[vv]);
			}
		}
	}
	cout << dp[n];
}
