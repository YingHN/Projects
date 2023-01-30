#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cube[3], holl[2], n;
	cin>>n;
	while(n--)
	{
		scanf("%d%d%d%d%d", &cube[0], &cube[1], &cube[2], &holl[0], &holl[1]);
		sort(cube, cube + 3);
		sort(holl, holl + 2);
		if(cube[0] <= holl[0] && cube[1] <= holl[1])
			cout<<"Track complete";
		else cout<<"Track lost";
	}
}

