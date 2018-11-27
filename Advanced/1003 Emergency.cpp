#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int maxn = 505;

const int INF = INT_MAX;;

int n, m, c1, c2;

int G[maxn][maxn] = { 0 };
int weight[maxn];

int d[maxn];
int num[maxn];
int w[maxn];
bool vis[maxn] = { false };

void Dijkstra(int start){
	fill(d, d + maxn, INF);
	d[start] = 0;
	num[start] = 1;
	w[start] = weight[start];

	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < min)
			{
				u = j;
				min = d[j];
			}
		}

		if (u == -1)
		{
			return;
		}
		vis[u] = true;

		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != 0)
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if (d[u] + G[u][v] == d[v])
				{
					num[v] += num[u];
					if (w[u] + weight[v] > w[v])
					{
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}

}


int main(){

	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}

	for (int i = 0; i < m; i++)
	{
		int c1, c2, len;
		scanf("%d %d %d", &c1, &c2, &len);
		G[c1][c2] = G[c2][c1] = len;
	}
	Dijkstra(c1);
	printf("%d %d", num[c2], w[c2]);
	return 0;
}