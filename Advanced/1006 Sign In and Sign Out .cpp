#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){

	int m;
	scanf("%d%*c", &m);
	int minIn = 34 * 3600 + 10;
	int maxOut = -1;
	char inId[20], outId[20];
	for (int i = 0; i < m; i++)
	{
		char id[20];
		int h1, m1, s1, h2, m2, s2;
		scanf("%s %d:%d:%d %d:%d:%d%*c", id, &h1, &m1, &s1, &h2, &m2, &s2);
		int tempIn = h1 * 3600 + m1 * 60 + s1;
		int tempOut = h2 * 3600 + m2 * 60 + s2;
		if (i == 0){
			strcpy(inId, id);
			strcpy(outId, id);
			minIn = tempIn;
			maxOut = tempOut;
		}
		else
		{
			if (tempIn < minIn)
			{
				strcpy(inId, id);
				minIn = tempIn;
			}

			if (tempOut > maxOut)
			{
				strcpy(outId, id);
				maxOut = tempOut;
			}
		}
	}

	printf("%s %s", inId, outId);

	return 0;
}