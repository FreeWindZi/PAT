#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;

int nc, np;

typedef long long LL;

LL c[maxn], p[maxn];

bool cmp(LL a, LL b){
	return a > b;
}

int main(){

	scanf("%d", &nc);
	for (int i = 0; i < nc; i++)
	{
		scanf("%lld", &c[i]);
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++)
	{
		scanf("%lld", &p[i]);
	}

	sort(c, c + nc, cmp);
	sort(p, p + np, cmp);
	LL ans = 0;
	int i = 0, j =0; 
	while (c[i] > 0 && p[j] > 0 && i < nc && j < np)
	{
		ans += (c[i++] * p[j++]);
	}

	 i = nc - 1, j = np - 1;
	while (c[i] < 0 && p[j] < 0 && i >=  0 && j >= 0)
	{
		ans += (c[i--] * p[j--]);
	}
	printf("%lld", ans);
	return 0;
}