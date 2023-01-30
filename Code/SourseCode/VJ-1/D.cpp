#include<bits/stdc++.h>
using namespace std;
void f(char it, char tar, char ept, int ids, int ide)
{
	if(ids == ide)
	{
		cout<<ids<<":"<<it<<"->"<<tar<<endl;
		return;
	}
	f(it, ept, tar, ids , ide - 1);
	f(it, tar, ept, ide, ide);
	f(ept, tar, it, ids, ide - 1);
}
int main()
{
	int n;
	char a, b, c;
	cin>>n>>a>>b>>c;
	f(a, c, b, 1, n);
}

