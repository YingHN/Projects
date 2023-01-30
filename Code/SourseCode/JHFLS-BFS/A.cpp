#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int q[3276710],head=1,tail=0;
int main()
{
	cin>>m>>n;
	for(int i = 1; i <= m;++i)q[++tail] = i;
	
	while(head <= tail)
	{
		++cnt;
		if(cnt == n)
		{
			cnt = 0;
			cout<<q[head]<<"\n";
		}
		else q[++tail] = q[head];
		++head;
	}
}

