#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8 + 7;
char Map[300][300];
bitset<300> used[300];
int w, h, Step[300][300], Move[4][2] =
{
{2,0},
{-2,0},
{0,2},
{0,-2},
};
struct POINT
{
	int x, y, step = 1;
	bool check(POINT fa)
	{
		return x >= 0 && x <= 2 * h + 1 && y >= 0 && y <= 2 * w + 1 && used[x][y] == false && Map[x][y] == ' ' && Map[(fa.x + x) / 2][(fa.y + y) / 2] == ' ';
	}
	POINT gen(int ty)
	{
		return POINT{ x + Move[ty][0],y + Move[ty][1],step + 1 };
	}
};
vector<POINT> s;
queue<POINT> q;
void DEBUG()
{
	for (int i = 1; i < (2 * h + 1); i += 2)
	{
		for (int j = 1; j < 2 * w + 1; j += 2)
		{
			cout << Step[i][j] << " ";
		}
		cout << "\n";
	}
}
int bfs(POINT st)
{
	int ans = -1;
	q.push(st);
	used[st.x][st.y] = true;
	Step[st.x][st.y] = 1;
	while (!q.empty())
	{
		POINT now = q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			POINT next = now.gen(i);
			if (!next.check(now))continue;
			q.push(next);
			used[next.x][next.y] = true;
			Step[next.x][next.y] = min(Step[next.x][next.y], next.step);
			ans = max(ans, next.step);
		}
	}
	return ans;
}
int main()
{

	cin >> w >> h;
	for (int i = 0; i < (2 * h + 1); ++i)
	{
		getchar();
		for (int j = 0; j < 2 * w + 1; ++j)
		{
			Map[i][j] = getchar();
			Step[i][j] = INF;
			if (Map[i][j] == ' ')
			{
				if (i == 0)s.push_back(POINT{ i + 1,j });
				if (i == 2 * h)s.push_back(POINT{ i - 1,j });
			}
		}
		if (Map[i][0] == ' ')s.push_back(POINT{ i,1 });
		if (Map[i][2 * w] == ' ')s.push_back(POINT{ i,2 * w - 1 });
	}


	for (auto it = s.begin(); it != s.end(); ++it)
	{
		bfs(*it);
	}
	int ans = 0;
	for (int i = 1; i < (2 * h + 1); i += 2)
	{
		for (int j = 1; j < 2 * w + 1; j += 2)
		{
			ans = max(ans, Step[i][j]);
		}
	}
	cout << ans;
}

