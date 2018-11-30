#include <cstdio>
#include <algorithm>
using namespace std;

const int maxk = 105;
const int maxn = 10005;
const int startTime = 8 * 60 * 60;
const int endTime = 21 * 60 * 60;
struct Table
{
	bool vip;
	int startTime;
	bool open;

	Table(){
		startTime = 8 * 60 * 60;
		open = true;
	}

}tab[maxk];

struct Person
{
	int arriveTime;
	int serveTime;
	int waitTime;
	int p;
	bool vip;
	Person(){
		waitTime = 0;
	}
}ps[maxn];


bool cmpArrive(Person a, Person b){
	return a.arriveTime < b.arriveTime;
}

int n;
int k, m;



int main(){

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int hh, mm, ss;
		int vip;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &ps[i].p, &vip);
		ps[i].arriveTime = hh * 3600 + mm * 60 + ss;
		ps[i].vip = vip;
	
		if (ps[i].p > 2 * 60)
		{
			ps[i].p = 2 * 60;
		}
		ps[i].p *= 60;
	}
	scanf("%d %d", &k, &m);
	for (int i = 0; i < m; i++)
	{
		int vipTab;
		scanf("%d", &vipTab);
		tab[vipTab].vip = true;
		tab[vipTab].open = false;
	}

	sort(ps, ps + n, cmpArrive);
	for (int i = 0; i < n; i++)
	{
		if (ps[i].vip)
		{

		}
	}

	return 0;
}