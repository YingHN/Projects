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
int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	int a[n + 1][m + 1] //原数组
			,
			b[n + 1][m + 1] //行的大小
			,
			c[n + 1][m + 1]; //列的大小
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
			c[j][i] = a[i][j];
		}
	}
	/*
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << "``````````````\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << c[j][i] << " ";
		}
		cout << endl;
	}
	cout << "``````````````\n";
	*/
	for (int i = 1; i <= n; ++i)
		sort(b[i] + 1, b[i] + m + 1, [](int a, int b)
				 { return a > b; });
	for (int i = 1; i <= m; ++i)
		sort(c[i] + 1, c[i] + n + 1, [](int a, int b)
				 { return a > b; });
	/*
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << "``````````````\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << c[j][i] << " ";
		}
		cout << endl;
	}
	cout << "``````````````\n";
	*/
	while (q--)
	{
		// cout<<"DEBUG1 ";
		int x, y, k, cnt = 0;
		bool f;
		cin >> x >> y >> k;
		int i = 1, j = 1;
		for (int cnt = 1; cnt != k + 1; ++cnt)
		{
			// cout<<"#"<<cnt<<"=";
			if (b[x][i] > c[y][j])
			{
				// cout<<b[x][i];
				++i, f = false;
			}
			else if (b[x][i] < c[y][j])
			{
				// cout<<c[y][j];
				++j, f = true;
			}
			else if (b[x][i] == c[y][j])
			{
				// cout<<c[y][j]<<"&"<<b[x][i];
				++i, ++j, f = true;
			}
			// cout<<" | ";
		}
		if (!f)
			cout << b[x][i - 1]; //<<"b:"<<x<<" "<<i;
		else
			cout << c[y][j - 1]; //<<"c:"<<j<<" "<<y;
		cout << endl;
	}
}
