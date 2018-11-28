#include <cstdio>

int main(){

	double a[3] = { 0 };
	char result[5] = { 'W', 'T', 'L' };
	double ans = 1.0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
		int maxIndex = 0;
		if (a[1] > a[maxIndex])
		{
			maxIndex = 1;
		}
		if (a[2] > a[maxIndex])
		{
			maxIndex = 2;
		}
		ans *= a[maxIndex];
		printf("%c ", result[maxIndex]);
	}
	printf("%0.2f", (ans * 0.65 - 1) * 2);
	return 0;
}