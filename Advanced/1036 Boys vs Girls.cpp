#include <cstdio>
#include <vector>
using namespace std;



struct Student
{
	char name[20];
	char id[20];
	int grade;
	char gender;
};


int n;

int main(){

	scanf("%d%*c", &n);

	Student fMax, mMin;
	fMax.grade = -1;
	mMin.grade = 101;
	for (int i = 0; i < n; i++)
	{
		Student temp;
		scanf("%s %c %s %d%*c", temp.name, &temp.gender, temp.id, &temp.grade);
		if (temp.gender == 'F')
		{
			if (temp.grade > fMax.grade)
			{
				fMax = temp;
			}
		}
		else
		{
			if (temp.grade < mMin.grade)
			{
				mMin = temp;
			}
		}

	}
	if (fMax.grade < 0)
	{
		printf("Absent\n");
	}
	else
	{
		printf("%s %s\n", fMax.name, fMax.id);
	}

	if (mMin.grade > 100)
	{
		printf("Absent\n");
	}
	else
	{
		printf("%s %s\n", mMin.name, mMin.id);
	}

	if (fMax.grade < 0 || mMin.grade > 100)
	{
		printf("NA");
	}
	else
	{
		printf("%d", fMax.grade - mMin.grade);
	}
	return 0;
}