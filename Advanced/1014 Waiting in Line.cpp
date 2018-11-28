#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


const int startTime = 8 * 60;
const int endTime = 17 * 60;

const int maxk = 1005;
const int maxn = 25;

struct Person
{
	int w;
	int endTime;

	Person(){
		endTime = -1;
	}
}ps[maxk];

struct Window
{
	queue<int> q;
}wd[maxn];

int n, m, k, q;

int main(){

	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &ps[i].w);
	}

	int cap = n * m;

	for (int i = 0; i < k; i++)
	{
		if (i < cap)
		{
			int index = i % n;
			int size = wd[index].q.size();
			if (size == 0)
			{
				ps[i].endTime = startTime + ps[i].w;
				wd[index].q.push(ps[i].endTime);
				
			}
			else
			{
				if (wd[index].q.back() < endTime)
				{
					ps[i].endTime = wd[index].q.back() + ps[i].w;
					wd[index].q.push(ps[i].endTime);
				}

			}
		}
		else
		{
			int index = 0;
			for (int j = 1; j < n; j++)
			{
				if (wd[j].q.front() < wd[index].q.front())
				{
					index = j;
				}
			}

			if (wd[index].q.front() < endTime && wd[index].q.back() < endTime)
			{
				ps[i].endTime = wd[index].q.back() + ps[i].w;
				wd[index].q.push(ps[i].endTime);
				wd[index].q.pop();
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		int query;
		scanf("%d", &query);
		query--;
		if (ps[query].endTime > 0)
		{
			int house = ps[query].endTime / 60;
			int minute = ps[query].endTime % 60;
			printf("%02d:%02d\n", house, minute);
		}
		else
		{
			printf("Sorry\n");
		}
	}

	return 0;
}