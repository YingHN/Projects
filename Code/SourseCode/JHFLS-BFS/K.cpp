#include<bits/stdc++.h>
using namespace std;
int n,m,t,sR,sC,tR,tC;
char Map[101][101];
bitset<101> inQue[101];
int cnt[101][101];
struct POINT
{
    int r,c,step;
	// WARNING: you must choose a way: book cnt in or out struct
    bool check()
    {
        return r>=1&&r<=n&&c>=1&&c<=m&&step<=t&&Map[r][c]!='*';
    }
    bool isAns()
    {
        return r==tR&&c==tC&&step==t;
    }
}Move[4]
{
POINT{1,0},
POINT{-1,0},
POINT{0,1},
POINT{0,-1}
};
queue<POINT> q;
int main()
{
    cin>>n>>m>>t;
    for(int i=1;i<=n;++i)
        cin>>Map[i]+1;//WARNING: you must "+1", because the order is start from 0. 
    cin>>sR>>sC>>tR>>tC;
 
    q.push(POINT{sR,sC,0});
    inQue[sR][sC]=true;
    cnt[sR][sC]=1;
	int ans=0;
    while(!q.empty())
    {
        POINT now=q.front();q.pop();inQue[now.r][now.c]=false; 
         
        for(int i=0;i<4;++i)
        {
            POINT next;
                next.r=now.r+Move[i].r,
                next.c=now.c+Move[i].c,
                next.step=now.step+1;
             
            if(!next.check())continue;
            if(next.isAns())ans+=cnt[now.r][now.c];
              
            if(!inQue[next.r][next.c])
            {
                inQue[next.r][next.c]=true;
                cnt[next.r][next.c]=cnt[now.r][now.c];
                q.push(next);
            }
            else
            {
                cnt[next.r][next.c]+=cnt[now.r][now.c]; 
            }
        }
    }
    cout<<ans;
}

/**************************************************************
    Problem: 1298
    User: xz202201
    Language: C++
    Result: AC 
    Time:0 ms
    Memory:2148 kb
****************************************************************/
