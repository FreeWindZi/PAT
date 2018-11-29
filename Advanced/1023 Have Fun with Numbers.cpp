#include <cstdio>
#include <cstring>
using namespace std;

struct Bign
{
	int len = 0;
	int d[100];
};

int hash[10] = { 0 };

Bign convert(char str[]){
	int len = strlen(str);
	Bign a;
	a.len = len;
	for (int i = 0; i < len; i++)
	{
		a.d[a.len - 1 - i] = str[i] - '0';
	}
	return a;
}

Bign multi(Bign a, int n){
	int carry = 0;
	Bign b;
	for (int i = 0; i < a.len; i++)
	{
		carry = (n * a.d[i]) + carry;
		b.d[b.len++] = carry % 10;
		carry /= 10;
	}
	while (carry)
	{
		b.d[b.len++] = carry % 10;
		carry /= 10;
	}
	return b;
}

int main(){

	char str[100];
	scanf("%s", str);;
	Bign a = convert(str);

	for (int i = 0; i < a.len; i++)
	{
		hash[a.d[i]]++;
	}
	Bign b = multi(a, 2);
	for (int i = 0; i < b.len; i++)
	{
		hash[b.d[i]]--;
	}
	bool same = true;
	for (int i = 0; i < 10; i++)
	{
		if (hash[i])
		{
			same = false;
			break;
		}
	}
	if (same)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	for (int i = b.len - 1; i >= 0; i--)
	{
		printf("%d", b.d[i]);
	}

	return 0;
}