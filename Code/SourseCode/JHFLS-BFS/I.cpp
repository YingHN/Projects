#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int area[50][50];
char Map[50][50];

struct POINT
{
	int x,y;
	bool check(POINT fa)
	{
		return x>=0&&x<n&&y>=0&&y<m&&!area[x][y]&&Map[x][y]>=Map[fa.x][fa.y];
	}
}Move[4]=
{
	POINT{0,1},
	POINT{0,-1},
	POINT{1,0},
	POINT{-1,0}
};
vector<POINT> minn[26]; 
void bfs(int sX, int sY)
{
	queue<POINT> q;
	q.push(POINT{sX,sY});
	area[sX][sY]=++k;
	
	while(!q.empty())
	{
		POINT it=q.front();q.pop();
		
		for(int i=0;i<4;++i)
		{
			POINT tar;tar.x=it.x+Move[i].x,tar.y=it.y+Move[i].y;
			
			if(!tar.check(it))continue;
			
			area[tar.x][tar.y]=k;
			q.push(tar);
		}
	}
	
	return;
}
void debug(int x,int y)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cout<<area[i][j];
		}
		cout<<endl;
	}
	cout<<"========================"<<x<<","<<y<<"==============================\n";
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0;i<n;++i)
		{
			cin>>Map[i];
			for(int j=0;j<m;++j)
				minn[Map[i][j]-'a'].push_back(POINT{i,j});
		}
			
		
		for(int i=0;i<26;++i)
		{
			for(int j=0;j<minn[i].size();++j)
			{
				int x=minn[i][j].x,y=minn[i][j].y;
				if(area[x][y]==0)bfs(x,y);
			}
			minn[i].clear();
		}
			
				
		
		cout<<k<<endl;
		
		k=0;
		for(int i=0;i<50;++i)for(int j=0;j<50;++j)area[i][j]=0,Map[i][j]=0;
	}
}

/**************************************************************
    Problem: 1300
    User: xz202201
    Language: C++
    Result: AC
    Time:10 ms
    Memory:2248 kb
****************************************************************/
