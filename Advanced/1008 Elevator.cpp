#include <cstdio>

int main(){

	int n;
	scanf("%d", &n);
	int last = 0;
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		int now;
		scanf("%d", &now);
		if (now > last)
		{
			time += (now - last) * 6;
		}
		else if (now < last)
		{
			time += (last - now) * 4;
		}
		time += 5;
		last = now;
	}
	printf("%d", time);
	return 0;
}