#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){

	string str;
	getline(cin, str);
	int n1, n2;
	int len = str.size(); 
	len += 2;
	n2 = len / 3;
	if (len % 3 != 0)
	{
		n2 += (len % 3);
	}
	n1 = (len - n2) / 2;
	len -= 2;
	for (int i = 0; i < n1; i++)
	{
		if (i != n1 - 1)
		{
			printf("%c", str[i]);
			for (int j = 2; j < n2; j++)
			{
				printf(" ");
			}
			printf("%c\n", str[len - 1 - i]);
		}
		else
		{
			for (int j = 0; j < n2; j++)
			{
				printf("%c", str[i + j]);
			}
		}
	
	}
	return 0;
}