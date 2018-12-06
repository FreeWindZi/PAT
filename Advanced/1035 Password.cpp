#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1005;

struct User
{
	char name[15];
	char psw[15];
}u[maxn];

int n;

vector<int> ans;

void judge(int i){
	int len = strlen(u[i].psw);
	bool modify = false;
	for (int j = 0; j < len; j++)
	{
		if (u[i].psw[j] == '1')
		{
			modify = true;
			u[i].psw[j] = '@';
		}
		else if (u[i].psw[j] == '0')
		{
			modify = true;
			u[i].psw[j] = '%';
		}
		else if (u[i].psw[j] == 'l')
		{
			modify = true;
			u[i].psw[j] = 'L';
		}
		else if (u[i].psw[j] == 'O')
		{
			modify = true;
			u[i].psw[j] = 'o';
		}
	}

	if (modify)
	{
		ans.push_back(i);
	}
}

int main(){

	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s%*c", u[i].name, u[i].psw);
		judge(i);
	}

	int size = ans.size();
	if (size == 0)
	{
		if (n == 1)
		{
			printf("There is 1 account and no account is modified");
		}
		else
		{
			printf("There are %d accounts and no account is modified", n);
		}
	}
	else
	{
		printf("%d\n", size);
		for (int i = 0; i < size; i++)
		{
			printf("%s %s\n", u[ans[i]].name, u[ans[i]].psw);
		}
	}
	return 0;
}