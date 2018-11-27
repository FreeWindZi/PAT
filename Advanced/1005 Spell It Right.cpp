#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


string english[] = { "zero", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine" };

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string str;
	getline(cin, str);
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		sum += (str[i] - '0');
	}

	int v[100];
	int len = 0;

	do
	{
		v[len++] = sum % 10;
		sum /= 10;
	} while (sum);

	for (int i = len - 1; i >= 0 ; i--)
	{
		cout << english[v[i]];
		if (i != 0){
			cout << " ";
		}
	}

	return 0;
}