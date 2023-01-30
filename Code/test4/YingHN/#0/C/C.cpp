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


const int MAXN = 1e4 + 1;
/*
int head[MAXN], cnt = 0;
struct EDGE
{
	int next;
	int to;
	int del = false;
}edge[MAXN];
void addEdge(int u, int v)
{
	++cnt;
	edge[cnt].next = head[u];
	edge[cnt].to = v;
	edge[cnt].del = true;
	head[u] = cnt;
}
void delEdge(int u, int v)
{
	
}
int n, Q;
bool dfs(int node, int target)
{
	for(int i = head[node]; i; i = edge[head[node]].next)
	{
		if(i == target)return true;
		return dfs(i, target);
	}
	return false;
}*/
int n, Q;
bool Map[MAXN][MAXN];
void check(int node)
{
	for(int i = 1; i <= n; ++i)
	{
		if(!Map[node][i])continue;
		for(int j = 1;j <= n; ++j)
		{
			if(Map[i][j])
			{
				Map[node][j]=true;
			}
		}
	}
	return;
}
int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	cin>>n>>Q;
	while(Q--)
	{
		int typ, u, v;
		cin>>typ>>u>>v;
		if(typ == 1)
		{
			Map[u][v] = true;
			Map[v][u] = true;
			check(u);
			check(v);
			//addEdge(u, v);
		}
		if(typ == 2)
		{
		}
		if(typ == 3)
		{
			if(Map[u][v] || Map[v][u])
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
//			if(dfs(u, v) || dfs(v, u))
//			{
//				cout<<"Yes\n";
//			}
//			else cout<<"NO\n";
		}
	}
}

