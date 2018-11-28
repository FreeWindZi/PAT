#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int a){
	if (a < 2)
	{
		return false;
	}
	int sqr =(int) sqrt(a);
	for (int i = 2; i <= sqr; i++)
	{
		if (a % i == 0)
		{
			return false;	 
		}
	}
	return true;
}

int reverse(int a, int radix){
	int v[32];
	int len = 0;
	do
	{
		v[len++] = a % radix;
		a /= radix;
	} while (a);

	int ans = 0;
	for (int i = 0; i < len; i++)
	{
		ans = ans * radix + v[i];
	}

	return ans;

}

int main(){

	int a;
	scanf("%d", &a);
	int radix;
	while (a > 0)
	{
		scanf("%d", &radix);

		if (isPrime(a) && isPrime(reverse(a, radix)))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

		scanf("%d", &a);
	}

	return 0;
}