#include<bits/stdc++.h>
using namespace std;





bool compare(string s, string t)
{
	int n = s.size();
	int m = t.size();
	int j = 0;
	for(int i = 0; i < n && j < m; ++i)
	{
		if(s[i] == t[j])
		{
			//cout<<"  Æ¥ÅäÓÚ"<<i<<", "<<j<<endl;
			++j;
		}
	}
	if(j == (m))
	{
		//cout<<"  SCCUSS!";
		return true;
	}
	else return false; 
	
}


int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	string s;
	cin>>s;
	int n, ans = 0;
	cin>>n;
	string t[n];
	for(int i = 0; i < n; ++i)
	{
		cin>>t[i];
		if(compare(s, t[i]))
		{
			++ans;
			//cout<<"__"<<t[i]<<endl;
		}
	}
	cout<<ans;
}

