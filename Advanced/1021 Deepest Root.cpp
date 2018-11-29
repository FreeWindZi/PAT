#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

const int maxn = 10005;



int father[maxn] = { 0 };
vector<int> G[maxn];
int inq[maxn] = { false };
int n;

set<int> ans;
int h[maxn] = { 0 };
int maxH = 0;

void BFS(int start){
	queue<int> q;
	q.push(start);
	inq[start] = true;
	h[start] = 1;
	while (!q.empty())
	{
		int now = q.front();
		maxH = max(maxH, h[now]);
		q.pop();
		for (int i = 0; i < G[now].size(); i++)
		{
			int next = G[now][i];
			if (!inq[next])
			{
				h[next] = h[now] + 1;
				q.push(next);
				inq[next] = true;
			}
		}
	}
}

void init(){
	for (int i = 1; i <= n; i++)
	{
		inq[i] = false;
		h[i] = 0;
		maxH = 0;
	}
}

int getBlocks(){
	int block = 0;
	init();
	for (int i = 1; i <= n; i++)
	{
		if (!inq[i])
		{
			BFS(i);
			block++;
		}
	}
	return block;
}

void getAns(){
	for (int i = 1; i <= n; i++)
	{
		if (h[i] == maxH)
		{
			ans.insert(i);
		}
	}
}

int main(){

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	int block = getBlocks();
	if (block == 1)
	{
		

		getAns();

		init();
		BFS(*ans.begin());
		getAns();
		for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
		{
			printf("%d\n", *it);
		}
	}
	else
	{
		printf("Error: %d components", block);
	}
	return 0;
}