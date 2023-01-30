#include<bits/stdc++.h>
using namespace std;
int n,m;
char Map[10][10];
int check(int x,int y)
{
	int ans = 0;

	if(x+1<n&&y+1<n&&Map[x][y]=='1'&&Map[x+1][y]=='1'&&Map[x][y+1]=='1'&&Map[x+1][y+1]=='0')ans=ans*10+1;
	if(x+1<n&&y-1>=0&&Map[x][y]=='1'&&Map[x+1][y]=='1'&&Map[x][y-1]=='1'&&Map[x+1][y-1]=='0')ans=ans*10+2;
	if(x-1>=0&&y+1<n&&Map[x][y]=='1'&&Map[x-1][y]=='1'&&Map[x][y+1]=='1'&&Map[x-1][y+1]=='0')ans=ans*10+3;
	if(x-1>=0&&y-1>=0&&Map[x][y]=='1'&&Map[x-1][y]=='1'&&Map[x][y-1]=='1'&&Map[x-1][y-1]=='0')ans=ans*10+4;
	
	return ans;
}
int main()
{
	
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>Map[i];
	
	int ans = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			int ck=check(i,j);
			if(ck==0)continue;
			if(ck<10)ans=ans*10+ck;
			else if(ck<100)ans=ans*100+ck;
		}
	
	switch (ans)
	{
		case 1234:
			cout<<0;break;
		case 0:
			cout<<1;break;
		case 2413:
			cout<<2;break;
		case 2143:
			cout<<2;break;
		case 2424:
			cout<<3;break;
		case 342:
			cout<<4;break;
		case 1324:
			cout<<5;break;
		case 131234:
			cout<<6;break;
		case 113234:
		    cout<<6;break;
		case 2:
			cout<<7;break;
		case 12132434:
			cout<<8;break;
		case 12341234:
			cout<<8;break;
		case 123424:
			cout<<9;break;
		case 123244:
		    cout<<9;break;
	}
}

/**************************************************************
    Problem: 1962
    User: xz202201
    Language: C++
    Result: AC
    Time:0 ms
    Memory:2088 kb
****************************************************************/
