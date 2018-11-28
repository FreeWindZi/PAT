#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

LL n1, n2;


const int max_len = 256;
int hashTable[max_len] = {0};

LL calcute(string str, LL radix){

	LL v = 0;
	for (int i = 0; i < str.size(); i++)
	{
		v = v * radix + hashTable[str[i]];
		if (v < 0)
		{
			break;
		}
	}
	return v;

}

int findMinRadix(string str){
	int radix = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (hashTable[str[i]] > radix)
		{
			radix = hashTable[str[i]];
		}
	}
	return radix + 1;
}

LL binarySearch(LL left, LL right, LL d, string str){
	LL mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		LL temp = calcute(str, mid);
		if (temp == d)
		{
			right = mid;
		}
		else if (temp > d || temp < 0)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}


int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	string str1, str2;
	int tag;
	LL radix;

	for (int i = '0'; i <= '9'; i++)
	{
		hashTable[i] = i - '0';
	}

	for (int i = 'a'; i <= 'z'; i++)
	{
		hashTable[i] = 10 + i - 'a';
	}

	cin >> str1 >> str2 >> tag >> radix;
	if (tag == 2)
	{
		swap(str1, str2);
	}
	n1 = calcute(str1, radix);

	LL left = findMinRadix(str2);
	LL right = max(left, n1);

	LL radix2 = binarySearch(left, right, n1, str2);
	n2 = calcute(str2, radix2);

	if (n1 == n2)
	{
		printf("%d", radix2);
	}
	else
	{
		printf("Impossible");
	}



	return 0;
}