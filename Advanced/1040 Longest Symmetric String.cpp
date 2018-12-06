#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1005;

bool dp[maxn][maxn] = { false };

int main(){

	string str;
	getline(cin, str);

	int len = str.size();
	int ans = 1;
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = true;
		if (i > 0 && str[i - 1] == str[i])
		{
			dp[i - 1][i] = true;
			ans = 2;
		}
	}

	for (int k = 3; k <= len; k++)
	{
		for (int i = 0; i + k - 1 < len; i++)
		{
			int j = i + k - 1;
			if (str[i] == str[j] && dp[i + 1][j - 1] )
			{
				ans = k;
				dp[i][j] = true;
			}
		}
	}
	printf("%d", ans);

	return 0;
}