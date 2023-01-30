#include<bits/stdc++.h>
using namespace std;
int X,Y,tar,used[101][101];
struct STAUT
{
    int x,y,step;
    bool check()
    {
        return used[x][y]==-1;
    }
    void gen(int ty)
    {
        switch(ty)
        {
            case 1: x=X;break;
            case 2: y=Y;break;
            case 3: x=0;break;
            case 4: y=0;break;
            case 5: 
                if(x>Y-y)x=x-Y+y,y=Y;
                else y=y+x,x=0;
				// WARNING: code like "x=0,y=y+x" is the same as #3, it cannot change y.
				// because of this problem, I've been boring for 1 week.
                break;
            case 6: 
                if(y>X-x)y=y-X+x,x=X;
                else x=x+y,y=0;
                // WARNING! 
                break;
        }
        ++step;
    }
    bool isAns()
    {
        return (x==tar||y==tar);
    }
};queue<STAUT> q;
int main()
{
    cin>>X>>Y>>tar;
    for(int i=0;i<=X;++i)
        for(int j=0;j<=Y;++j)
            used[i][j]=-1;
     
    q.push(STAUT{0,0,0});
    used[0][0]=0;
    while(!q.empty())
    {
        STAUT now=q.front();q.pop();
        for(int i=1;i<=6;++i)
        {
            STAUT next=now;next.gen(i);
            if(!next.check())continue;
            if(next.isAns())
            {
                cout<<next.step;
                return 0;
            }
            used[next.x][next.y]=next.step;
            q.push(next);
        }
    }
     
    cout<<"No Solution!\n";
}

/**************************************************************
    Problem: 1299
    User: xz202201
    Language: C++
    Result: AC
    Time:0 ms
    Memory:2136 kb
****************************************************************/
