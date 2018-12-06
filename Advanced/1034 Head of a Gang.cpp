#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2005;

map<string, int> mpNameToId;
vector<string> names;

int w[maxn] = { 0 };

int len = 0;

bool cmp(int a, int b){
	return names[a] < names[b];
}

int findId(string name){
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
int gang[maxn] = { 0 };
int findFather(int a){
	int x = a;
	while (a != father[a])
	{
		a = father[a];
	}

	return a;

}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB){
		if (w[faA] > w[faB])
		{
			father[faB] = faA;
		}
		else
		{
			father[faA] = faB;
		}
	}
}



int main(){
	for (int i = 0; i < maxn; i++)
	{
		father[i] = i;
	}
	scanf("%d %d%*c", &n, &k);
	k *= 2;
	for (int i = 0; i < n; i++)
	{
		string name1, name2;
		int time;
		cin >> name1 >> name2 >> time;
		getchar();
	
		int id1 = findId(name1);
		int id2 = findId(name2);
		w[id1] += time;
		w[id2] += time;

		Union(id1, id2);
	}
	
	for (int i = 0; i < len; i++)
	{
		root[father[i]]++;
		gang[father[i]] += w[i];
	}
	vector<int> ans;
	for (int i = 0; i < len; i++)
	{
		if (root[i] > 2 && gang[i] > k)
		{
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end(), cmp);

	int size = ans.size();
	printf("%d\n", size);
	for (int i = 0; i < size; i++)
	{
		printf("%s %d\n", names[i].c_str(), root[i]);
	}

	return 0;
}