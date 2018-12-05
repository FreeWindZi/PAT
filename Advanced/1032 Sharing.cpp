#include <cstdio>

const int maxn = 1e5 + 5;

struct Node
{
	int address;
	char data;
	int next;
	bool first;
	Node(){
		first = false;
	}

}node[maxn];

int main(){

	int s1, s2, n;
	scanf("%d %d %d", &s1, &s2, &n);
	for (int i = 0; i < n; i++)
	{
		int address, next;
		char data;
		scanf("%d %c %d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}


	while (s1 != -1)
	{
		node[s1].first = true;
		s1 = node[s1].next;
	}

	while (s2 != -1)
	{
		if (node[s2].first)
		{
			printf("%05d", s2);
			return 0;
		}
		s2 = node[s2].next;
	}
	printf("-1");
	return 0;
}