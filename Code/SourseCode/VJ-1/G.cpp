#include<bits/stdc++.h>
using namespace std;
int a[1000][1000], sum[1000][1000];
int main()
{
	int n, m;
	cin>>n>>m;
	for(int i = 1; i<= n; ++i)
	{
		for(int j = 1;j<m;++j)
		{
			cin>>a[i][j];
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}
	
}

