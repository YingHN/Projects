#include<bits/stdc++.h>
using namespace std;
int n, m, x;
bool used[100][100];
char Map[100][100];
struct POINT
{
	int x,y,step;
	bool check()
	{
		return x>=0 && x<n && y>=0 && y<m && !used[x][y] && Map[x][y] != 'X';// && step <= x;
	}
};
POINT Move[4] = 
{
	POINT{1, 0, 1},
	POINT{-1, 0, 1},
	POINT{0, 1, 1},
	POINT{0, -1, 1}
};
int main()
{
	
	cin>>n>>m>>x;
	int sX, sY, tX, tY;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin>>Map[i][j];
			if(Map[i][j] == 'S')
			{
				sX=i, sY=j;
			}
			if(Map[i][j] == 'D')
			{
				tX=i, tY=j;
			}
		}
	}
	queue<POINT> q;
	q.push(POINT{sX, sY, 0});
	used[sX][sY] = true;
	while(!q.empty())
	{
		POINT it = q.front();q.pop();
		for(int i = 0; i < 4; ++i)
		{
			POINT tar;
			tar.x = it.x+Move[i].x, tar.y=it.y+Move[i].y, tar.step = it.step+Move[i].step;
			if(!tar.check())continue;
			if(tar.x == tX && tar.y == tY)
			{
				cout<<((tar.step<=x) ? "YES" : "NO");
				return 0;
			}
			q.push(tar);
			used[tar.x][tar.y] = true;
		}
	}
	cout<<"NO";
}

