#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n, l;
		cin>>n>>l;--l;
		string s[2];
		cin>>s[1]>>s[0];
		for(int i = 3; i <= n; ++i)
			s[i % 2] = s[(i - 1) % 2] + s[i % 2];
		if(l > s[n % 2].size())cout<<"#\n";
		else cout<<s[n % 2][l]<<endl;
	}
	
}

