#include<bits/stdc++.h>
using namespace std;
long long int sum[500010];
int main()
{
	long long int n;
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin>>a;
		sum[i] = a + sum[i - 1];
	}
	long long int Q;
	cin>>Q;
	while(Q--)
	{
		int i, l;
		cin>>i>>l;
		cout<<sum[i + l - 1] - sum[i - 1]<<endl;
	}
}

