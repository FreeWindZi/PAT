#include <cstdio>

using namespace std;

char value[] = "0123456789ABC";;

void convert(int c){
	printf("%c%c", value[c / 13], value[c % 13]);
}

int main(){

	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf("#");
	convert(r);
	convert(g);
	convert(b);
	return 0;
}