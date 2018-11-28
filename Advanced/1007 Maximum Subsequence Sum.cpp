#include <cstdio>
#include <iostream>
using namespace std;

const int maxk = 10001;

int k;

int A[maxk];
int dp[maxk];
int s[maxk];

int main(){

	scanf("%d", &k);
	bool negative = true;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &A[i]);
		if (A[i] >= 0)
		{
			negative = false;
		}
	}

	if (negative)
	{
		printf("%d %d %d", 0, A[1], A[k]);
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			if (dp[i - 1] + A[i] > A[i])
			{
				dp[i] = dp[i - 1] + A[i];
				s[i] = s[i - 1];
			}
			else
			{
				s[i] = A[i];
				dp[i] = A[i];
			}
		}

		int maxSum = dp[1], index = 1;
		for (int i = 1; i <= k; i++)
		{
			if (dp[i] > maxSum)
			{
				maxSum = dp[i];
				index = i;
			}
		}
		printf("%d %d %d", maxSum, s[index], A[index]);
	}

	return 0;
}