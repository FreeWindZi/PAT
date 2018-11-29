#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 10004;

int n;

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	char flag;
	cin >> n >> flag;

	for (int i = 0; i < n; i++)
	{
		string name;
		getline(cin, name);
		string title;
		getline(cin, title);
		string auther;
		getline(cin, auther);
		string key;
		do
		{
			cin >> key >> flag;
		} while (flag != '\n');
		string publishers;
		getline(cin, publishers);
		int year;
		cin >> year;
	}

	return 0;
}