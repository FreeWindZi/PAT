#include <cstdio>

const int maxk = 55;

const int num = 54;

int card[maxk];

int time = 0;
int order[maxk];

void printfCard(int i){
	i--;
	int type = i / 13;
	switch (i / 13)
	{
	case  0:
		printf("S");
		break;
	case  1:
		printf("H");
		break;
	case  2:
		printf("C");
		break;
	case  3:
		printf("D");
		break;
	default:
		printf("J");
		break;
	}
	printf("%d", i % 13 + 1);
}

int main(){

	for (int i = 1; i <= num; i++)
	{
		card[i] = i;
	}
	scanf("%d", &time);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &order[i]);
	}

	while (time)
	{
		int temp[maxk] = { 0 };
		for (int i = 1; i <= num; i++)
		{
			temp[order[i]] = card[i];
		}
		for (int i = 1; i <= num; i++)
		{
			card[i] = temp[i];
		}
		time--;
	}

	for (int i = 1; i <= num; i++)
	{
		printfCard(card[i]);
		if (i != num)
		{
			printf(" ");
		}
	}

	return 0;
}