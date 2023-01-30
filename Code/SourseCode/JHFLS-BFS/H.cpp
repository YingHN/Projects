#include<bits/stdc++.h>
using namespace std;
int R,C,L;
int step[30][30][30];
char Map[30][30][30];
bitset<30> used[30][30];
struct POINT
{
	int x,y,z;
	bool check()
	{
		return x>=0 && x<L && y>=0 && y<R && z>=0 && z<C && !used[x][y][z] && Map[x][y][z]!='#';
	}
}Move[6]
{
	POINT{1,0,0},
	POINT{-1,0,0},
	POINT{0,1,0},
	POINT{0,-1,0},
	POINT{0,0,1},
	POINT{0,0,-1},
};
bool bfs(int sX,int sY,int sZ)
{
	queue<POINT> q;
	q.push(POINT{sX,sY,sZ});
	used[sX][sY][sZ]=true;
	while(!q.empty())
	{
		POINT it=q.front();q.pop();
		for(int i=0;i<6;++i)
		{
			POINT tar;
				tar.x=it.x+Move[i].x,
				tar.y=it.y+Move[i].y,
				tar.z=it.z+Move[i].z;
			if(!tar.check())continue;
			step[tar.x][tar.y][tar.z]=step[it.x][it.y][it.z]+1;
			q.push(tar);
			used[tar.x][tar.y][tar.z]=true;
			if(Map[tar.x][tar.y][tar.z]=='E')
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int sX,sY,sZ;
	int tX,tY,tZ;
	cin>>L>>R>>C;
	for(int i=0;i<L;++i)
	{
		for(int j=0;j<R;++j)
		{
			cin>>Map[i][j];
			for(int k=0;k<C;++k)
			{
				if(Map[i][j][k]=='S')
				{
					sX=i,sY=j,sZ=k;
				} 
				if(Map[i][j][k]=='E')
				{
					tX=i,tY=j,tZ=k;
				} 
			}
		}
		 
	}
	if(bfs(sX,sY,sZ))
	{
		cout<<"Escaped in "<<step[tX][tY][tZ]<<" minute(s).";
	}
	else
	{
		cout<<"Trapped!";
	}
}

/**************************************************************
    Problem: 1301
    User: xz202201
    Language: C++
    Result: AC
    Time:1 ms
    Memory:2236 kb
****************************************************************/
