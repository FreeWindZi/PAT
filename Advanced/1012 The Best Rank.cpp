#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn = 2005;
struct student
{
	string name;
	int  a, c, m, e;
}stu[maxn];

struct Level
{
	int a, c, m, e;
};

bool cmpA(student a, student b){
	return a.a > b.a;
}
bool cmpC(student a, student b){
	return a.c > b.c;
}
bool cmpM(student a, student b){
	return a.m > b.m;
}
bool cmpE(student a, student b){
	return a.e > b.e;
}

int n, m;

map<string, Level> ans;

void printAns(string name){
	map<string, Level>::iterator it = ans.find(name);
	if (it != ans.end())
	{
		int bestLevel = it->second.a;
		char testName = 'A';
		if (it->second.c < bestLevel)
		{
			bestLevel = it->second.c;
			testName = 'C';
		}
		if (it->second.m < bestLevel)
		{
			bestLevel = it->second.m;
			testName = 'M';
		}
		if (it->second.e < bestLevel)
		{
			bestLevel = it->second.e;
			testName = 'E';
		}

		cout << bestLevel << " " << testName << endl;
	}
	else
	{
		cout << "N/A" << endl;
	}
}

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].name >> stu[i].c >> stu[i].m >> stu[i].e;
		stu[i].a = stu[i].c + stu[i].m + stu[i].e;
	}

	sort(stu, stu + n, cmpA);
	int rank = 1;
	for (int i = 0; i < n; i++)
	{
		
		if (i == 0)
		{
			rank = 1;
		}
		else if (stu[i].a != stu[i - 1].a)
		{
			rank = i + 1;
		}
		Level level;
		level.a = rank;
		ans[stu[i].name] = level;
	}


	sort(stu, stu + n, cmpC);
	rank = 1;
	for (int i = 0; i < n; i++)
	{

		if (i == 0)
		{
			rank = 1;
		}
		else if (stu[i].c != stu[i - 1].c)
		{
			rank = i + 1;
		}
		ans[stu[i].name].c = rank;
	}

	sort(stu, stu + n, cmpM);
	rank = 1;
	for (int i = 0; i < n; i++)
	{

		if (i == 0)
		{
			rank = 1;
		}
		else if (stu[i].m != stu[i - 1].m)
		{
			rank = i + 1;
		}
		ans[stu[i].name].m = rank;
	}

	sort(stu, stu + n, cmpE);
	rank = 1;
	for (int i = 0; i < n; i++)
	{

		if (i == 0)
		{
			rank = 1;
		}
		else if (stu[i].e != stu[i - 1].e)
		{
			rank = i + 1;
		}
		ans[stu[i].name].e = rank;
	}

	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		printAns(name);
	}

	return 0;
}