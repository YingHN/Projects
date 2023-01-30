#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int q[1010],head=1,tail=0;
bool 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) q[++tail]=i;
	
	while(head<=tail){
		int t=q[head++];
		cnt++;
		if(cnt==m)cnt=0,cout<<t<<" ";
		else q[++tail]=t;
	}
}

