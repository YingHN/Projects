#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6e3 + 1, INF = 1e9 + 1;
int n, head[MAXN], cnt;
struct EDGE
{
    int next;
    int to;
}edge[MAXN];
void addEdge(int u, int v)
{
    ++cnt;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    head[u] = cnt;
}
int dp[MAXN][2], root;
bool notRoot[MAXN], vis[MAXN];
void dfs(int node)
{
	vis[node] = true;
    for(int i = head[node]; i; i = edge[i].next)
    {
    	int x = edge[i].to;
    	if(vis[x])continue;
        dfs(x);
		dp[node][1] += dp[x][0];
        dp[node][0] += max(dp[x][1], dp[x][0]);
    }
    return; 
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
	// 一定要从1开始 
    {
        cin>>dp[i][1];
    }
    for(int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin>>u>>v;
        notRoot[u] = true;
        addEdge(v, u);//不要弄反 
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!notRoot[i])
		{
			root = i;
			break;
		}
    }
    dfs(root);
    cout<<max(dp[root][0], dp[root][1]);
}
