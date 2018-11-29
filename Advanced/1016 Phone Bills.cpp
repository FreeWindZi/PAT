#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int day_hours = 24;
const int maxn = 1005;

int rates[day_hours];
int n;

struct Record
{
	char name[25];
	int time;

	int dd, hh, mm;

	bool on;
}re[maxn];


bool cmpRecord(Record a, Record b){
	int sameName = strcmp(a.name, b.name);
	if (sameName == 0)
	{
		if (a.time != b.time)
		{
			return a.time < b.time;
		}
		else
		{
			return a.on > b.on;
		}
	}
	else
	{
		return sameName < 0;
	}
}

int month;
int allDayMoney = 0;

int getTime(int dd, int hh, int mm){
	return dd  * 24 * 60 +  hh * 60 + mm;
}

int getMoney(Record a){

	int money = (a.dd - 1) * allDayMoney;
	for (int i = 0; i < a.hh; i++)
	{
		money += rates[i] * 60;
	}

	return money + rates[a.hh] * a.mm;
}

int getCost(Record a, Record b){
	return getMoney(b) - getMoney(a);
}

int main()
{

	for (int i = 0; i < day_hours; i++)
	{
		scanf("%d", &rates[i]);
		allDayMoney += rates[i] * 60;
	}

	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++)
	{
		char flag[20];
		int m, dd, hh, mm;
		scanf("%s %d:%d:%d:%d %s%*c", re[i].name, &m, &dd, &hh, &mm, flag);
		month = m;
		re[i].time = getTime(dd, hh, mm);
		re[i].dd = dd; 
		re[i].hh = hh;
		re[i].mm = mm;
		if (strcmp(flag, "on-line") == 0)
		{
			re[i].on = true;
		}
		else
		{
			re[i].on = false;
		}
	}

	sort(re, re + n, cmpRecord);

	bool needPrintCost = false;
	bool printName = false;
	int total = 0;
	for (int i = 1; i < n; i++)
	{
		if (strcmp(re[i - 1].name, re[i].name) == 0)
		{
			if (re[i - 1].on == true && re[i].on == false)
			{
				int minute = re[i].time - re[i - 1].time;
				int cost = getCost(re[i - 1], re[i]);
				if (!printName)
				{
					printf("%s %02d\n", re[i].name, month);
					printName = true;
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%0.2f\n", re[i - 1].dd, re[i - 1].hh, re[i - 1].mm, re[i].dd, re[i].hh, re[i].mm,
					minute, cost * 0.01);
				total += cost;
				needPrintCost = true;
			}

		}
		else
		{
			if (needPrintCost)
			{
				printf("Total amount: $%0.2f\n", total * 0.01);
			}
			printName = false;
			needPrintCost = false;
			total = 0;
		}
	}
	if (needPrintCost)
	{
		printf("Total amount: $%0.2f\n", total * 0.01);
	}
	return 0;
}