#include <cstdio>


const int maxk = 1001;

double hash[maxk];

int main(){
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int ex;
		double coe;
		scanf("%d %lf", &ex, &coe);
		hash[ex] = coe;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int ex;
		double coe;
		scanf("%d %lf", &ex, &coe);
		hash[ex] += coe;
	}

	int sum = 0;
	for (int i = 0; i < maxk; i++)
	{
		if (hash[i])
		{
			sum++;
		}
	}

	printf("%d", sum);
	for (int i = maxk - 1; i >=0 && sum; i--)
	{
		if (hash[i])
		{
			printf(" %d %0.1f", i, hash[i]);
			sum--;
		}
	}

	return 0;
}