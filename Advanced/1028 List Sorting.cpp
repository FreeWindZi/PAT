#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;

struct Student
{
	int id;
	char name[15];
	int grade;
}stu[maxn];

bool cmpId(Student a, Student b){
	return a.id < b.id;
}

bool cmpGrade(Student a, Student b){
	if (a.grade != b.grade)
	{
		return a.grade < b.grade;
	}
	else
	{
		return cmpId(a, b);
	}
}

bool cmpName(Student a, Student b){
	int result = strcmp(a.name, b.name);
	if (result)
	{
		return result < 0;
	}
	else
	{
		return cmpId(a, b);
	}
}

int main(){

	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
	}

	switch (c)
	{
	case 1:
		sort(stu, stu + n, cmpId);
		break;
	case 2:
		sort(stu, stu + n, cmpName);
		break;
	case 3:
		sort(stu, stu + n, cmpGrade);
		break;
	default:
		break;
	}


	for (int i = 0; i < n; i++)
	{
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}