#include<bits/stdc++.h>
using namespace std;
int n, pri[1000010], cnt = 0;
bitset<1000010> vis;
void getPri()
{
	for(int i = 2; i <= n; ++i)
	{
		if(!vis[i])pri[cnt++] = i;
		for(int j = 0; j < cnt && pri[j] * i <= n; ++j)
		{
			vis[i * pri[j]] = true;
			if(i % pri[j] == 0)break;
		}
	}
}
int main()
{
	cin>>n;
	getPri();
	int ans = 0;
	for(int i = 1; i < cnt && pri[i] <= n; ++i)
	{
		if(pri[i] - pri[i - 1] <= 2)
		{
			//cout<<pri[i]<<" "<<pri[i - 1]<<endl;
			++ans; 
		}
	}
	cout<<ans;
}

