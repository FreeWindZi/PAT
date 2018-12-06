#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


const int maxn = 1e4 + 5;

int n;
string str[maxn];

bool cmp(string a, string b){
	return a + b < b + a;
}

int main(){

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	bool isPrint = false;
	for (int i = 0; i < n; i++)
	{
		if (isPrint)
		{
			printf("%s", str[i].c_str());
		}
		else
		{
			int size = str[i].size();
			for (int j = 0; j < size; j++)
			{
				if (isPrint)
				{
					printf("%c", str[i][j]);
				}
				else
				{
					if (str[i][j] != '0')
					{
						printf("%c", str[i][j]);
						isPrint = true;
					}
				}
			}
		}
	}

	if (!isPrint)
	{
		printf("0");
	}

	return 0;
}