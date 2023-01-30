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

const int MAXN = 1e3;
int head[MAXN], tail[MAXN], dp[MAXN][MAXN], times[MAXN];
int op(int a, int b)
{
	return head[a] * tail[a] * tail[b];
}
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>head[i];
		tail[i - 1] = head[i];
		tail[i + n - 1] = tail[i - 1];
		head[i + n] = head[i];
		//times[i] = op(times[(i - 1) % n], head[i % n]); 
	}
	tail[2 * n] = head[1];
	times[0] = 1;
	for(int i = 1; i <= 2 * n; ++i)
	{
		times[i] = times[i - 1] * tail[i] * head[i];
		//cout<<times[i]<<" ";
	}
	
	//cout<<endl<<times[3] / times[1]<<endl;
/*
4
2 3 5 10
*/	
	
	for(int len = 1; len < n; ++len)
	{
		for(int l = 1; l <= 2 * n; ++l)
		{
			int r = l + len;
			for(int i = l; i < r && i <= 2 * n; ++i)
			{
				dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r] + head[l] * tail[i] * tail[r]);
			}
		}
	}
	
	
//	for(int l = 1; l <= 2 * n; ++l)
//	{
//		for(int r = 1; r <= 2 * n; ++r)
//		{
//			cout<<dp[l][r]<<" ";
//		}
//		cout<<endl;
//	}
	
	
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans = max(dp[i][i + n - 1], ans);
		//cout<<dp[i][i + n]<<" ";
	} 
	cout<<endl<<ans;
}

