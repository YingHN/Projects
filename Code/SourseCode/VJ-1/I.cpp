#include<bits/stdc++.h>
using namespace std;
#define int long long int
int a[100001];
signed main()
{
	int n, pos = 0, neg = 0, tmp = 0;
	cin>>n;
	
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i] - a[i - 1] > 0 && i != 1)
		{
			pos += a[i] - a[i - 1];
		}
		if(a[i] - a[i - 1] < 0 && i != 1)
		{
			neg += a[i] - a[i - 1];
		}
	}
	neg = -neg;
	//cout<<pos<<" "<<neg<<endl;
	cout<<max(neg, pos)<<"\n"<<abs(pos - neg) + 1;
}

