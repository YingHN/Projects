#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1, MAXN = 2e5 + 1;
int cnt, head[MAXN], n, m, s;
struct EDGE //边
{
	int next;
	int to;
	int wt; 
}edge[MAXN];
void addEdge(int u, int v, int wt)
{
	++cnt;
	edge[cnt].next = head[u];
	edge[cnt].to = v;
	edge[cnt].wt = wt;
	head[u] = cnt;
}
struct NODE
{
	int dis;
	int id;
	bool operator <(const NODE &x) const
	{
		return x.dis < dis;
	}
};
bool vis[MAXN];
int dis[MAXN];
void dijkstra()
{
	priority_queue<NODE> que;// 堆(小顶)优化
	// ! que储存**用于松弛其他节点**的节点
	que.push(NODE{0, s}); // 起点
	dis[s] = 0;

	while(!que.empty())
	{
		NODE u = que.top(); // 只有用"距离起点距离最小的节点"才能松弛其他节点
		que.pop();
		if(vis[u.id])continue; // 已经使用节点#u松弛其他节点
		vis[u.id] = true;

		for(int i = head[u.id]; i; i = edge[i].next)
		// 链式前向星遍历边的方式
		{
			if(dis[edge[i].to] > dis[u.id] + edge[i].wt)
			{
				//使用 节点#i 松弛 节点#edge[i].to 
				dis[edge[i].to] = dis[u.id] + edge[i].wt;
				// 由于使用"距离起点距离最小的节点"松弛, 
				// 节点#edge[i].to也成为了最优的节点, 
				// 可以松弛其他节点
				if(!vis[edge[i].to]) // 未使用节点#edge[i].wt松弛其他节点
				{
					que.push(NODE{dis[edge[i].to], edge[i].to});
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m>>s;
	for(int i = 1; i <= n; ++i)dis[i] = INF; 
	// **必须从1开始**
	for(int i = 0; i < m; ++i) 
	{
		int u, v, wt;
		cin>>u>>v>>wt;
		addEdge(u, v, wt);
	}
	dijkstra();
	for(int i = 1; i <= n; ++i)
	{
		cout<<dis[i]<<" ";
	}
}

