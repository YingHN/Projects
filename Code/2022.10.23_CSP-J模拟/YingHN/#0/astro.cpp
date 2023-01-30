#include<bits/stdc++.h>
using namespace std;
const char DAY[8][15]=
	{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
struct time
{
	int day;
	int hh;
	int mm;
};
void check(struct time &t)
{
	t.mm = abs(t.mm);
	t.hh = abs(t.hh);
	t.day = abs(t.day);
	if(t.mm>=60)t.hh+=t.mm/60, t.mm%=60;
	if(t.hh>=24)t.day+=t.hh/24, t.hh%=24;
	if(t.day>=7)t.day%=7;
}
void print(struct time t)
{
	cout<<DAY[t.day]<<endl;
	if(t.hh < 10)cout<<"0";
	cout<<t.hh<<":";
	if(t.mm < 10)cout<<"0";
	cout<<t.mm<<endl;
}
int t_n(struct time t)
{
	return t.hh*60+t.mm;
}
int main()
{
	//freopen("astro.in","r",stdin);
	//freopen("astro.out","w",stdout);
	struct time s1,s2,d1,d2;
	s1.day=6,s2.day=6,d1.day=0,d2.day=0;
	scanf("%d:%d", &s1.hh,&s1.mm);
	scanf("%d:%d", &s2.hh,&s2.mm);
	scanf("%d:%d", &d1.hh,&d1.mm);
	scanf("%d:%d", &d2.hh,&d2.mm);
	int t = 0;
	int S1=t_n(s1),S2=t_n(s2),D1=t_n(d1),D2=t_n(d2);
	int maxt = D1*D2/__gcd(D1, D2); 
	while(S1 <= maxt || S2 <= maxt)
	{
		if(S1==S2)
		{
			struct time temp;
			temp.day = 5;
			temp.mm = S1;
			check(temp);
			print(temp);
			return 0;
		}
		if(S1<S2)S1+=D1;
		if(S2<S1)S2+=D2;
	}
	cout<<"Never";
	return 0;	
}
/*
02:20
13:00
05:50
01:00
*/

