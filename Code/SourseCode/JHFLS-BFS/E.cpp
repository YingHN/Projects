#include<bits/stdc++.h>
using namespace std;
int n, m, x;
bool used[7][7];
char Map[7][7];
struct POINT
{
	int x,y,step;
	bool check()
	{
		return x>=0 && x<n && y>=0 && y<m && !used[x][y] && Map[x][y] != 'X';
	}
};
POINT Move[4] = 
{
	POINT{1, 0, 1},
	POINT{-1, 0, 1},
	POINT{0, 1, 1},
	POINT{0, -1, 1}
};
bool bfs(int sX, int sY)
{
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
			if(Map[tar.x][tar.y] == 'D')
			{
				return (tar.step<=x);
			}
			q.push(tar);
			used[tar.x][tar.y] = true;
		}
	}
	return false;
}
int main()
{
	
	cin>>n>>m>>x;
	vector<int> sX, sY;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin>>Map[i][j];
			if(Map[i][j] == 'S')
			{
				sX.push_back(i), sY.push_back(j);
			}
		}
	}
	for(int i = 0; i < sX.size(); ++i)
	{
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				used[i][j] = false;
		
		if(bfs(sX[i], sY[i]))
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}

