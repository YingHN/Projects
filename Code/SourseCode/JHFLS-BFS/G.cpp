#include<bits/stdc++.h>
using namespace std;
int n, m, cnt = 1, o = 0, v = 0;
int used[250][250];
char Map[250][250];
struct POINT
{
	int x,y;
	bool check()
	{
		return x>=0 && x<n && y>=0 && y<m;
	}
	bool CheckNotUsed()
	{
		return used[x][y] == 0 && (Map[x][y] == '.' || Map[x][y] == 'o' || Map[x][y] == 'v');
	}
};
POINT Move[4] = 
{
	POINT{1, 0},
	POINT{-1, 0},
	POINT{0, 1},
	POINT{0, -1}
};
void count(int x, int y)
{
	if(Map[x][y] == 'o')
	{
		++o;
	}
	if(Map[x][y] == 'v')
	{
		++v;
	}
}
void bfs(int sX, int sY)
{
	queue<POINT> q;
	q.push(POINT{sX, sY});
	count(sX, sY);
	used[sX][sY] = cnt;
	while(!q.empty())
	{
		POINT it = q.front();q.pop();
		for(int i = 0; i < 4; ++i)
		{
			POINT tar;
			tar.x = it.x+Move[i].x, tar.y=it.y+Move[i].y;
			if(!tar.check())
			{
				o = 0, v = 0;
				return;
			}
			if(!tar.CheckNotUsed())continue;
			count(tar.x, tar.y);
			q.push(tar);
			used[tar.x][tar.y] = cnt;
		}
	}
	return;
}
int main()
{
	
	cin>>n>>m;
	vector<int> sX, sY;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin>>Map[i][j];
			
		}
	}
	
	int cntO = 0, cntV = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if((Map[i][j] == '.' || Map[i][j] == 'o' || Map[i][j] == 'v') && used[i][j] == 0)
			{
				o = 0, v = 0;
				bfs(i, j);
				++cnt;
				if(o > v)
				{
					cntO+=o;
				}
				else
				{
					cntV+=v;
				}
			}
		}
	}
	cout<<cntO<<" "<<cntV<<endl;
}

/**************************************************************
    Problem: 1302
    User: xz202201
    Language: C++
    Result: AC
    Time:34 ms
    Memory:2404 kb
****************************************************************/
