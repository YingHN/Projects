/*
## [Problem](http://usaco.org/index.php?page=viewproblem&cpid=1265)

## Hint

! 数学题

### 核心性质

不难发现, 规则不改动中间的字符. 

! 因此, 寻找`O`即可. 
*/
#include <bits/stdc++.h>
using namespace std;
int T, n;
string str;
int Index()
{
  int ans = 0xffffff;
  for (int i = 1; i < n - 1; ++i)
  {
    if (str[i] == 'O')
    {
      string substr = {str[i - 1], str[i], str[i + 1]};
      if (substr == "MOO")
        return n-3;
      if (substr == "OOO" || substr == "MOM")
        ans = min(ans, 1);
      if (substr == "OOM")
        ans = min(ans, 2);
    }
  }
  if (ans == 0xffffff)
    return -1;
  ans += n - 3;
  return ans;
}
int main()
{
  cin >> T;
  while (T--)
  {  
    cin >> str;
    n = str.size();
    cout<<Index()<<"\n";
  }
}
/*
![](../Pic/ResultC.png)
*/