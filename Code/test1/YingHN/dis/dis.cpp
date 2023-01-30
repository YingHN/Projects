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
		~ NTR() {
			flush();
		}
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
		Reader() {}
	} cin;
	const char endl = '\n';
	struct Writer {
		template<typename T>
		Writer& operator << (T x) {
			if (x == 0) {
				putchar('0');
				return *this;
			}
			if (x < 0) {
				putchar('-');
				x = -x;
			}
			static int sta[45];
			int top = 0;
			while (x) {
				sta[++top] = x % 10;
				x /= 10;
			}
			while (top) {
				putchar(sta[top] + '0');
				--top;
			}
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
		Writer() {}
	} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end


const int INF = 1e3 + 1, MAXN = 1e3 + 1;
int nox, noy, x, y;
int f[MAXN][MAXN];
struct POINT {
	int x;
	int y;
	int step;

	struct POINT operator +(const struct POINT X) const {
		return {X.x+x, X.y+y, X.step+step};
	}
} DRC[8] = {
	POINT{0, 1, 1},
	//{0, -1, 1},
	POINT{0, 0, 0},
	POINT{1, 1, 1},
	POINT{1, -1, 1},
	POINT{1, 0, 1},
	POINT{-1, 1, 1},
	//{-1, -1, 1},
	POINT{0, 0, 0},
	//{-1, 0, 1}
	POINT{0, 0, 0}
};
POINT add(POINT a, POINT b) {
	return POINT {a.x+b.x, a.y+b.y, a.step+b.step};
}
bool check(struct POINT p) {
	if(p.x > x || p.y > y || p.x < 0 || p.y < 0)return false;
	else return true;
}
int bfs() {
	queue<struct POINT> que;
	que.push(POINT {0, 0, 0});
	while(!que.empty()) {
		for(int i = 0; i < 8; ++i) {
			struct POINT next = add(que.front(), DRC[i]);
			if(f[next.x][next.y] > next.step && check(next)) {
				que.push(next);
				f[next.x][next.y] = next.step;
			}
		}
		que.pop();
	}
	return f[x][y];
}
//void DFS(POINT p) {
//	if(p.x == x && p.y == y)
//	{
//		f[x][y] = max(f[x][y], p.step);
//		return;
//	}
//	for(int i = 0; i < 8; ++i) {
//		struct POINT next = add(p, DRC[i]);
//		if(f[next.x][next.y] > next.step && check(next)) {
//			f[next.x][next.y] = next.step;
//			DFS(next);
//		}
//	}
//	return;
//}
//int dfs()
//{
//	DFS(POINT{0, 0, 0});
//	return f[x][y];
//}
int main() {
	freopen("dis.in", "r", stdin);
	freopen("dis.out", "w", stdout);

	cin>>nox>>noy>>x>>y;
	if(x < 0) nox = -nox, x = -x;
	if(y < 0) noy = -noy, y = -y;
	for(int i = 0; i < 8; ++i)
		if(DRC[i].x == nox && DRC[i].y == noy)
			DRC[i] = POINT {0, 0, 0};
	for(int i = 0; i <= x; ++i) { //memset f = INF
		for(int j = 0; j <= y; ++j) {
			f[i][j] = INF;
		}
	}
	cout<<bfs();
}

