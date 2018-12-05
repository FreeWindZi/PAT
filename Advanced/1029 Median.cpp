#include <cstdio>
#include <climits>

const int maxn = 2 * 1e5 + 5;


int a[maxn];

int main(){

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[n] = INT_MAX;
	int m = 0;
	scanf("%d", &m);
	int half = (n + m + 1)/ 2;
	int index = 0;

	int aIndex = 0;
	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		while (temp > a[aIndex])
		{
			ans = a[aIndex++];
			index++;
			if (index == half){
				printf("%d", ans);
				return 0;
			}
		}
		ans = temp;
		index++;
		if (index == half){
			printf("%d", ans);
			return 0;
		}
		
		
	}

	while (index != half){
		index++;
		ans = a[aIndex++];
	}

	printf("%d", ans);
	return 0;

	return 0;
}