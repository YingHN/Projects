#include<bits/stdc++.h>
using namespace std;

bool used[9][9];

struct POINT
{
	int x, y, step;
	bool check()
	{
		return x<=8 && x>=1 && y<=8 && y>=1 && !used[x][y];
	}
};
POINT Move[8] = 
{
POINT{1,2},
POINT{1,-2},
POINT{-1,2},
POINT{-1,-2},
POINT{2, 1},
POINT{2, -1},
POINT{-2, 1},
POINT{-2, -1},
};
int main()
{
//	for(int i = 1; i <= 8; ++i)
//	{
//		for(int j = 1; j <= 8; ++j)
//		{
//			Map[i][j]=0x7fffffff;
//		}
//	}
	int sX = getchar()-'a'+1, 
		sY = getchar()-'0';
	getchar();
	int tX = getchar()-'a'+1, 
		tY = getchar()-'0';
	if(sX==tX && sY==tY)cout<<0;
	queue<POINT> q;
	q.push(POINT{sX, sY, 0});
	used[sX][sY] = true;
	while(!q.empty())
	{
		POINT tmp = q.front();
		for(int i = 0;i < 8; ++i)
		{
			POINT tar;
			tar.x = tmp.x+Move[i].x, tar.y = tmp.y+Move[i].y, tar.step = tmp.step + 1;
			if(!tar.check())continue;
			if(tar.x == tX && tar.y==tY)
			{
				cout<<tar.step;
				return 0;
			}
			q.push(tar);
			used[tar.x][tar.y]=true;
		}
		q.pop();
	}
//	for(int i = 1; i <= 8; ++i)
//	{
//		for(int j = 1; j <= 8; ++j)
//		{
//			cout<<used[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	//cout<<Map[tX][tY];
}

