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


const int MAXN = 7e2 + 1;
int f[MAXN][MAXN][MAXN];
int sum;
bool check(int a, int b, int c)
{
	if(a >= b + c || b >= a + c || c >= a + b)return false;
	else return true;
}
//int ans = 0;
int dfs(int a, int b, int L)
{
	//cout<<"TRY: "<<a<<" "<<b<<" L="<<L<<"\n";
	int c = sum - a - b;
	if(f[a][b][L] != -1)
	{
		//cout<<"  USE: "<<a<<" "<<b<<" L="<<L<<"\n";//f[a][b][L]
		return 0;
	}
	if(L == 0)
	{
		if(check(a, b, c))
		{
			//cout<<"  ANS: "<<a<<" "<<b<<" L="<<L<<"\n";
			f[a][b][L] = 1;
			return 1;
		}
		else 
		{
			f[a][b][L] = 0;
			return 0;
		}
	}
	int ans = 0;
	for(int i = 1; i <= L; ++i)
	{
		ans += dfs(a + i, b, L - i) + dfs(a, b + i, L - i) + dfs(a, b, L - i);
	}
	f[a][b][L] = ans;
	return ans;
}
int main()
{
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	int a, b, c, L;
	cin>>a>>b>>c>>L;
	sum = a + b + c + L;
	int Max = max(max(a, b), c);
	int Min = min(min(a, b), c);
	for(int i = a; i <= a + L; ++i)
	{
		for(int j = b; j <= b + L; ++j)
		{
			for(int x = 0; x <= L; ++x)
			{
				//cout<<"Y";
				f[i][j][x] = -1;
			}
		}
	}
	
	cout<<check(a, b, c) + dfs(a, b, L);
}
/*
1 1 1 2
//4
*/

