#include <cstdio>

int n, b;

int main(){

	scanf("%d %d", &n, &b);

	int v[50];
	int len = 0;
	do
	{
		v[len++] = n % b;
		n /= b;
	} while (n);
	bool paNum = true;
	for (int i = 0; i < len; i++)
	{
		if (v[i] != v[len - 1 - i])
		{
			paNum = false;
			break;
		}
	}

	if (paNum)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	for (int i = len - 1; i >= 0 ; i--)
	{
		printf("%d", v[i]);
		if (i != 0)
		{
			printf(" ");
		}
	}

	return 0;
}