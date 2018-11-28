#include <cstdio>

using namespace std;

const int maxn = 2002;

double hash[maxn] = { 0 };


struct Polynomials
{
	int exp;
	double coe;

	Polynomials(){
		coe = 0;
	}

}a[maxn];

int main(){

	int n;
	scanf("%d", &n);
	int aLen = n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %lf", &a[i].exp, &a[i].coe);
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int exp;
		double coe;
		scanf("%d %lf", &exp, &coe);

		for (int j = 0; j < aLen; j++)
		{
			hash[exp + a[j].exp] += (coe *  a[j].coe);
		}
	}

	int sum = 0;
	for (int i = 0; i < maxn; i++)
	{
		if (hash[i] != 0)
		{
			sum++;
		}
	}
	printf("%d", sum);
	for (int i = maxn - 1; i >= 0 && sum != 0; i--)
	{
		if (hash[i] != 0)
		{
			printf(" %d %0.1f", i, hash[i]);
			sum--;
		}
	}
	return 0;
}