#include<bits/stdc++.h>
using namespace std;
bitset<1000> Map[1000];
int n, m;
int cnt[1000][1000];
vector<int> ans;
struct POINT
{
	int x,y;
	bool check(bool it)
	{
		return x>=0 && x<n && y>=0 && y<n && !cnt[x][y] && Map[x][y]==(!it);
	}
}Move[4] = 
{
	POINT{1, 0},
	POINT{0, 1},
	POINT{-1, 0},
	POINT{0, -1}
};
int bfs(int sX, int sY)
{
	queue<POINT> q;
	q.push(POINT{sX, sY});
	cnt[sX][sY]=ans.size();
	int count = 1;
	while(!q.empty())
	{
		POINT it = q.front();q.pop();
		for(int i = 0; i < 4; ++i)
		{
			POINT next;
			next.x=it.x+Move[i].x, next.y=it.y+Move[i].y;
			
			if(!next.check(Map[it.x][it.y]))continue;
			
			++count;
			cnt[next.x][next.y]=ans.size();
			q.push(next);
		}
	}
	
	ans.push_back(count);
	return count;
}
int main()
{
	cin>>n>>m;
	ans.push_back(0);
	for(int i = 0; i<n;++i)
	{
		getchar();
		for(int j = 0; j<n;++j)
		{
			Map[i][j]=getchar() == '0' ? false : true;
		}
	}
	for(int i = 0; i<m;++i)
	{
		int x, y;
		
		scanf("%d %d", &x,&y);
		--x,--y;
		if(cnt[x][y])
		{
			printf("%d\n",ans.at(cnt[x][y]));
		}
		else
		{
			printf("%d\n",bfs(x,y));
		}
	}
}

/**************************************************************
    Problem: 1303
    User: xz202201
    Language: C++
    Result: AC
    Time:948 ms
    Memory:6608 kb
****************************************************************/
