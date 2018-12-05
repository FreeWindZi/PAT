#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 505;

struct Gas
{
	double price;
	double dis;
}g[maxn];

double cap, dis, avg;
int n;

const int INF = 

bool cmp(Gas a, Gas b){
	return a.dis < b.dis;
}

int main(){

	scanf("%lf %lf %lf %d", &cap, &dis, &avg, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &g[i].price, &g[i].dis);
	}
	g[n].price = 0;
	g[n].dis = dis;
	sort(g, g + n + 1, cmp);

	int nowG = -1, nowCap = 0, nowDis = 0;
	double maxRun = avg * cap;

	if (g[0].dis != 0)
	{
		printf("The maximum travel distance = 0.2f\n", nowDis);
		return 0;
	}
	nowCap = 0;
	double nowPrice = g[0].price;
	while (nowCap <= n)
	{
		int nextG = -1;
		double minPrice = g[nowG + 1].price;
		
		for (int i = nowG + 1; i <= n && g[i].dis - g[nowG].dis <= maxRun; i++)
		{
			if (g[i].price < minPrice)
			{
				minPrice = g[i].price;
			}

			if (minPrice < nowPrice)
			{
				next
			}
		}
	}

	return 0;
}