#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10004;

int n;

map<string, vector<int>> mpTitle, mpAuther, mpKey, mpPublisher, mpYear;

void printAns(vector<int> ans){
	sort(ans.begin(), ans.end());
	int size = ans.size();
	for (int i = 0; i < size; i++)
	{
		if (i == 0 )
		{
			printf("%07d\n", ans[i]);
		}
		else if (ans[i] != ans[i -1])
		{
			printf("%07d\n", ans[i]);
		}
		
	}
}

void printAns(int qFlag, string q){
	
	switch (qFlag)
	{
	case 1:
		if (mpTitle.count(q) == 0)
		{
			printf("Not Found\n");
		}
		else
		{
			vector<int> ans = mpTitle[q];
			printAns(ans);
		}
		break;
	case 2:
		if (mpAuther.count(q) == 0)
		{
			printf("Not Found\n");
		}
		else
		{
			vector<int> ans = mpAuther[q];
			printAns(ans);
		}
		break;
	case 3:
		if (mpKey.count(q) == 0)
		{
			printf("Not Found\n");
		}
		else
		{
			vector<int> ans = mpKey[q];
			printAns(ans);
		}
		break;
	case 4:
		if (mpPublisher.count(q) == 0)
		{
			printf("Not Found\n");
		}
		else
		{
			vector<int> ans = mpPublisher[q];
			printAns(ans);
		}
		break;
	case 5:
		if (mpYear.count(q) == 0)
		{
			printf("Not Found\n");
		}
		else
		{
			vector<int> ans = mpYear[q];
			printAns(ans);
		}
		break;
	}

}

int main(){

	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++)
	{
		int id;
		scanf("%d%*c", &id);
		string title;
		getline(cin, title);
		mpTitle[title].push_back(id);

		string auther;
		getline(cin, auther);
		mpAuther[auther].push_back(id);

		string key;
		char flag;
		do
		{
			cin >> key;
			mpKey[key].push_back(id);
			flag = getchar();
		} while (flag != '\n');
		string publishers;
		getline(cin, publishers);
		mpPublisher[publishers].push_back(id);

		string year;
		getline(cin, year);

		mpYear[year].push_back(id);
	}


	int m;
	scanf("%d%*c", &m);
	int qFlag = 0;
	for (int i = 0; i < m; i++)
	{
		string query;
		getline(cin, query);
		cout << query << endl;
		qFlag = query[0] - '0';

		query.erase(query.begin(), query.begin() + 3);
		printAns(qFlag, query);

	}

	return 0;
}