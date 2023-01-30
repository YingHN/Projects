#include<bits/stdc++.h>
using namespace std;
int fa[1001];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)fa[i] = i;
    while(m--)
    {
        int x, y;
        cin>>x>>y;
        fa[find(x)] = fa[find(y)];
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(fa[i] != i) continue;
        int sz = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(find(j) == i)
            {
                ++sz;
            }
        }
        ans = max(ans, sz);
    }
    cout<<ans;
}
/**************************************************************
    Problem: 1522
    User: xz202201
    Language: C++
    Result: AC
    Time:8 ms
    Memory:2088 kb
****************************************************************/
