#include <cstdio>
#include <algorithm>
using namespace std;

using namespace std;

const int startTime = 8 * 60 * 60;
const int endTime = 17 * 60 * 60;

const int maxn = 10005;
const int maxk = 105;

struct Person
{
	int time;
	int proc;
}ps[maxn];

struct Window
{
	int startTime;

}w[maxk];

int n, k;

bool cmp(Person a, Person b){
	return a.time < b.time;
}

int main(){
	scanf("%d %d", &n, &k);
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		int h, m, s, p;
		scanf("%d:%d:%d %d", &h, &m, &s, &p);
		int time = h * 60 * 60 + m * 60 + s;
		if (time < endTime)
		{
			ps[len].time = time;
			if (p >= 60)
			{
				p = 60;
			}
			ps[len].proc = p * 60;
			len++;
		}
	}
	sort(ps, ps + len, cmp);

	for (int i = 0; i < k; i++)
	{
		w[i].startTime = startTime;
	}

	int waitTime = 0;
	for (int i = 0; i < len; i++)
	{
		if (i < k)
		{
			int winIndex = i % k;
			if (w[winIndex].startTime > ps[i].time)
			{
				waitTime += w[winIndex].startTime - ps[i].time;
				w[winIndex].startTime += ps[i].proc;
			}
			else
			{
				w[winIndex].startTime = ps[i].time + ps[i].proc;
			}
		}
		else
		{
			int winIndex = 0;
			for (int j = 1; j < k; j++)
			{
				if (w[j].startTime < w[winIndex].startTime)
				{
					winIndex = j;
				}
			}

			if (w[winIndex].startTime > ps[i].time)
			{
				waitTime += w[winIndex].startTime - ps[i].time;
				w[winIndex].startTime += ps[i].proc;
			}
			else
			{
				w[winIndex].startTime = ps[i].time + ps[i].proc;
			}

		}
	}

	printf("%0.1f", waitTime * 1.0 / 60 / len);

	return 0;
}