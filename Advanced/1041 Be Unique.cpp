#include <cstdio>
using namespace std;

const int maxm = 1e4 + 5;
const int maxn = 1e5 + 5;

int hashTable[maxm] = { 0 };

int a[maxn];

int main(){

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		hashTable[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (hashTable[a[i]] == 1)
		{
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}