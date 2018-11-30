#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Bign
{
	int len;
	int d[150];

	Bign(){
		len = 0;
		fill(d, d + 150, 0);
	}
};

Bign change(char str[]){
	int len = strlen(str);
	Bign a;
	a.len = len;
	for (int i = 0; i < len; i++)
	{
		a.d[len - 1 - i] = str[i] - '0';
	}
	return a;
}

bool isPaNum(Bign a){
	for (int i = 0; i < a.len; i++)
	{
		if (a.d[i] != a.d[a.len - 1 - i])
		{
			return false;
		}
	}
	return true;
}

Bign reversed(Bign a){
	Bign b;
	b.len = a.len;
	for (int i = 0; i < a.len; i++)
	{
		b.d[i] = a.d[a.len - 1 - i];
	}
	return b;
}

Bign add(Bign a, Bign b){
	int carry = 0;
	Bign c;
	for (int i = 0; i < a.len || i < b.len; i++)
	{
		carry = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	while (carry)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void printBign(Bign a){
	for (int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int main(){

	char str[20];
	int step;
	scanf("%s %d", str, &step);

	Bign a = change(str);
	int num = 0;
	while (num < step && !isPaNum(a))
	{
		Bign b = reversed(a);
		a = add(a, b);
		num++;
	}
	printBign(a);
	printf("%d", num);

	return 0;
}