#include<bits/stdc++.h>
using namespace std;


/* --------------- fast io --------------- */ // begin
namespace Fread {
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
inline char getchar() {
	if (S == T) {
		T = (S = buf) + fread(buf, 1, SIZE, stdin);
		if (S == T) return '\n';
	}
	return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
	fwrite(buf, 1, S - buf, stdout);
	S = buf;
}
inline void putchar(char c) {
	*S++ = c;
	if (S == T) flush();
}
struct NTR {
	~ NTR() { flush(); }
} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
#endif
namespace Fastio {
struct Reader {
	template<typename T>
	Reader& operator >> (T& x) {
		char c = getchar();
		T f = 1;
		while (c < '0' || c > '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		x = 0;
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		x *= f;
		return *this;
	}
	Reader& operator >> (char& c) {
		c = getchar();
		while (c == ' ' || c == '\n') c = getchar();
		return *this;
	}
	Reader& operator >> (char* str) {
		int len = 0;
		char c = getchar();
		while (c == ' ' || c == '\n') c = getchar();
		while (c != ' ' && c != '\n' && c != '\r') { // \r\n in windows
			str[len++] = c;
			c = getchar();
		}
		str[len] = '\0';
		return *this;
	}
	Reader(){}
} cin;
const char endl = '\n';
struct Writer {
	template<typename T>
	Writer& operator << (T x) {
		if (x == 0) { putchar('0'); return *this; }
		if (x < 0) { putchar('-'); x = -x; }
		static int sta[45];
		int top = 0;
		while (x) { sta[++top] = x % 10; x /= 10; }
		while (top) { putchar(sta[top] + '0'); --top; }
		return *this;
	}
	Writer& operator << (char c) {
		putchar(c);
		return *this;
	}
	Writer& operator << (char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer& operator << (const char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer(){}
} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end

const int MAXN = 1e4 + 1, INF = 2e7;
int a[MAXN], Min[MAXN][MAXN], Max[MAXN][MAXN], sum[MAXN];
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		a[i + n] = a[i];
	}
	
	for(int i = 1; i <= 2*n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];	
	}
	
	for(int len = 1; len < n; ++len)
	{
		for(int l = 1; l <= 2 * n; ++l)
		{
			int r = l + len;
			Min[l][r] = INF;
			for(int i = l; i < r/* && i <= 2 * n*/; ++i)
			{
				Min[l][r] = min(Min[l][r], Min[l][i] + Min[i + 1][r] + sum[r] - sum[l - 1]);
				Max[l][r] = max(Max[l][r], Max[l][i] + Max[i + 1][r] + sum[r] - sum[l - 1]);
			}
		}
	}
	
	int minAns = INF, maxAns = -1;
	for(int i = 1; i <= n; ++i)
	{
		minAns = min(minAns, Min[i][i + n - 1]), maxAns = max(maxAns, Max[i][i + n - 1]);
	}
		
	cout<<minAns<<"\n"<<maxAns;
}

