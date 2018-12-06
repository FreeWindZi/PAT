#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

map<string, vector<int>> stu;


int main(){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++)
	{
		int c, num;
		scanf("%d %d", &c, &num);
		for (int j = 0; j < num; j++)
		{
			getchar();
			string name;
			cin >> name;
			stu[name].push_back(c);
		}
	}

	for (int i = 0; i < n; i++)
	{
		getchar();
		string name;
		cin >> name;
		map<string, vector<int>>::iterator it = stu.find(name);
		if (it == stu.end())
		{
			printf("%s 0\n", name.c_str());
		}
		else
		{
			int size = it->second.size();
			sort(it->second.begin(), it->second.end());
			printf("%s %d", name.c_str(), size);
			for (int i = 0; i < size; i++)
			{
				printf(" %d", it->second[i]);
			}
			printf("\n");
		}

	}

	return 0;
}