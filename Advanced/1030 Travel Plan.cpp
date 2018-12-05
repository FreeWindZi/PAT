#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 505;
const int INF = 1e9 + 5;

int G[maxn][maxn] = { 0 };
int Cost[maxn][maxn] = { 0 };
bool vis[maxn] = { false };
int d[maxn];
int pre[maxn];
int w[maxn];


int n, m, s, ed;

void Dijkstra(int start){
	fill(d, d + maxn, INF);
	d[start] = 0;
	w[start] = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
		{
			return;
		}
		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (!vis[v] && G[u][v] != 0)
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + Cost[u][v];
					pre[v] = u;
				}
				else if (d[u] + G[u][v] == d[v] && w[u] + Cost[u][v] < w[v])
				{
					w[v] = w[u] + Cost[u][v];
					pre[v] = u;
				}
			}
		}
	}

}

void DFS(int end){
	if (end == s)
	{
		printf("%d ", end);
		return;
	}
	else
	{
		DFS(pre[end]);
		printf("%d ", end);
	}
}

int main(){

	scanf("%d %d %d %d", &n, &m, &s, &ed);

	for (int i = 0; i < m; i++)
	{
		int c1, c2, dis, cos;
		scanf("%d %d %d %d", &c1, &c2, &dis, &cos);
		G[c1][c2] = G[c2][c1] = dis;
		Cost[c1][c2] = Cost[c2][c1] = cos;
	}
	Dijkstra(s);
	DFS(ed);
	printf("%d %d", d[ed], w[ed]);
	return 0;
}