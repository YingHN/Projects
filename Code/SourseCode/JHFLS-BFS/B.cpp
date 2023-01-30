#include<bits/stdc++.h>
using namespace std;
#define int long long int
int que[50000000], head = 1, tail = 0;
signed main()
{
	int a,n;
	cin>>a>>n;
	que[++tail] = a;
	while(head < 10*n && head <= tail)
	{
		que[++tail]=que[head]*2+1;
		que[++tail]=que[head]*3+1;
		++head;
	}
	sort(que, que+tail);
	unique(que+1, que+tail+2);
	cout<<que[n];
}

