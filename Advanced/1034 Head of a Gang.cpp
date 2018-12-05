#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 2005;

map<string, int> mpNameToId;
vector<string> names;

int len = 0;

int findIds(string name){
	map<string, int>::iterator it = mpNameToId.find(name);
	if (it != mpNameToId.end())
	{
		return it->second;
	}
	else {
		mpNameToId[name] = len;
		names.push_back(name);
		return len++;
	}
}

int n, k;
int father[maxn] = { 0 };
int root[maxn] = { 0 };



int main(){
	for (int i = 0; i < maxn; i++)
	{
		father[i] = i;
	}
	scanf("%d %d%*c", &n, &k);

	for (int i = 0; i < n; i++)
	{
		string name1, name2;
		int time;
		cin >> name1 >> name2 >> time;
		getchar();
	}
	

	return 0;
}