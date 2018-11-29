#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 505;
const int INF = 1e9;

int cap, n, sp, m;

int half;

int w[maxn] = { 0 };

int G[maxn][maxn] = { 0 };
int vis[maxn] = { false };

int d[maxn] = { 0 };

vector<int> pre[maxn];

int start = 0;

void Dijkstra(int s){
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i <= n; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j <= n; j++)
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
		for (int v = 0; v <=n ; v++)
		{
			if (!vis[v] && G[u][v] !=0 )
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v])
				{
					pre[v].push_back(u);
				}
			}
		}


	}

}


vector<int> temp, path;

int minSend = INF, minTake = INF;

void DFS(int end){
	if (end == start)
	{
		temp.push_back(end);
		int send = 0;
		int take = 0;
		int size = temp.size();

		for (int i = size - 2; i >= 0;  i--)
		{
			if (w[temp[i]] > 0)
			{
				take += w[temp[i]];
			}
			else if (w[temp[i]] < 0)
			{
				int absW = abs(w[temp[i]]);
				if (take >= absW)
				{
					take -= absW;
				}
				else
				{
					absW -= take;
					take = 0;
					send += absW;
				}
			}
		}

		if (send < minSend)
		{
			minSend = send;
			minTake = take;
			path = temp;
		}	if (send == minSend && take < minTake){
			minTake = take;
			path = temp;
		}

		temp.pop_back();
	}
	else
	{
		temp.push_back(end);
		int size = pre[end].size();
		for (int i = 0; i < size; i++)
		{
			DFS(pre[end][i]);
		}
		temp.pop_back();
	}
}

void printAns(){
	printf("%d ", minSend);
	int size = path.size();
	for (int i = size - 1; i >= 0; i--){
		printf("%d", path[i]);
		if (i != 0){
			printf("->");
		}
	}
	printf(" %d", minTake);

}

int main(){

	scanf("%d %d %d %d", &cap, &n, &sp, &m);
	half = cap / 2;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		w[i] = temp - half;
	}
	for (int i = 0; i < m; i++)
	{
		int c1, c2, len;
		scanf("%d %d %d", &c1, &c2, &len);
		G[c1][c2] = G[c2][c1] = len;
	}
	Dijkstra(start);
	DFS(sp);
	printAns();
	return 0;
}






