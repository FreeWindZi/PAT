#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1005;

bool G[maxn][maxn] = { false };

int n, m, k;
bool inq[maxn] = { false };

void BFS(int s, int flagCity){
	queue<int> q;
	q.push(s);
	inq[s] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (inq[i] == false && i != flagCity && G[now][i] == true)
			{
				q.push(i);
				inq[i] = true;
			}
		}
	}
}

int GraphTravel(int flagCity){

	fill(inq, inq + maxn, false);
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		if (inq[i] == false && i != flagCity){
			BFS(i, flagCity);
			num++;
		}
	}
	return num - 1;

}

int main(){

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		G[c1][c2] = G[c2][c1] = true;
	}

	for (int i = 0; i < k; i++)
	{
		int start;
		scanf("%d", &start);
		printf("%d\n", GraphTravel(start));
	}

	return 0;
}