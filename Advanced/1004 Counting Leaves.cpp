#include <cstdio>
#include <vector>

using namespace std;


const int maxn = 100;

vector<int> nodes[maxn];

int n, m;
int layers[maxn] = { 0 };

int maxHeight = -1;

void DFS(int root, int height){
	int size = nodes[root].size();
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			DFS(nodes[root][i], height + 1);
		}
	}
	else
	{
		if (height > maxHeight)
		{
			maxHeight = height;
		}
		layers[height]++;
	}
}

int main(){

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int parent, k, child;
		scanf("%d %d", &parent, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			nodes[parent].push_back(child);
		}
	}

	DFS(1, 0);
	for (int i = 0; i <= maxHeight; i++)
	{
		printf("%d", layers[i]);
		if (i != maxHeight)
		{
			printf(" ");
		}
	}

	return 0;
}