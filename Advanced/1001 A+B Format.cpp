#include <cstdio>

int main(){

	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a + b;
	if (c < 0)
	{
		printf("-");
		c = -c;
	}

	int v[10];
	int len = 0;
	do
	{
		v[len++] = c % 10;
		c = c / 10;
	} while (c);

	for (int i = len - 1; i >= 0; i--)
	{
		printf("%d", v[i]);
		if (i % 3 ==0 & i != 0)
		{
			printf(",");
		}
	}

	return 0;
}