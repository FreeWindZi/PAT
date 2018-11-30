#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxp = 100 * 300 + 10;

const int maxk = 305;

struct Person
{
	LL id;
	int score;
	int locNum;
	int locRank;
}ps[maxp], temp[maxk];

bool cmp(Person a, Person b){
	if (a.score != b.score)
	{
		return a.score > b.score;
	}
	else
	{
		return a.id < b.id;
	}
}

int main(){

	int n;
	scanf("%d", &n);
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		int start = index;
		for (int j = 0; j < k; j++)
		{
			scanf("%lld %d", &ps[index].id, &ps[index].score);
			ps[index].locNum = i;
			index++;
		}
		sort(ps + start, ps + index, cmp);
		int locRank = 1;
		for (int j = 0; j < k; j++)
		{
			if (j != 0 && ps[j - 1 + start].score != ps[j + start].score)
			{
				locRank = j + 1;
			}
			ps[j + start].locRank = locRank;
		}
	}
	sort(ps, ps + index, cmp);
	printf("%d\n", index);
	int rank = 1;
	for (int i = 0; i < index; i++)
	{
		if (i != 0 && ps[i -1].score != ps[i].score)
		{
			rank = i + 1;
		}
		printf("%013lld %d %d %d\n", ps[i].id, rank, ps[i].locNum, ps[i].locRank);
	}

	return 0;
}