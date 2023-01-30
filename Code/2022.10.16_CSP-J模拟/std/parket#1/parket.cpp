#include <bits/stdc++.h>
using namespace std;
int r, b;
int area, l, w;
int main()
{
	// 本题思路是枚举方程的解
	// 需要手算方程的解(以已知量表示解)
	// freopen("parket.in","r",stdin);
	// freopen("parket.out","w",stdout);
	scanf("%d%d", &r, &b);
	area = r + b;
	for (w = 2; w * w <= area; w++)
		if (area % w == 0)
		{
			l = area / w;
			if ((l + w) * 2 - 4 == r && (w - 2) * (l - 2) == b)
			{
				printf("%d %d", l, w);
				return 0;
			}
		}
}
