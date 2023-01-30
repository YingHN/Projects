#include<bits/stdc++.h>
using namespace std;
int fa[6000];
int find(int x)
{
    if(fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
int main()
{
    int n, m, q;
    cin>>n>>m>>q;
    for(int i = 1; i <= n; ++i)fa[i] = i;
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        cin>>x>>y;
        fa[find(x)] = find(y);
    }
    for(int i = 1; i <= q; ++i)
    {
        int x, y;
        cin>>x>>y;
        cout<< ((find(x) == find(y)) ? "Yes" : "No") <<endl;
    }
}
/**************************************************************
    Problem: 1521
    User: xz202201
    Language: C++
    Result: AC
    Time:191 ms
    Memory:2108 kb
****************************************************************/
