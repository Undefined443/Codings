#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int cmp(const void* a, const void* b);

typedef struct
{
	char ID[20];
	int total;
	int English;
}Stu;

int main()
{
	int total, available;
	cin >> total >> available;
	Stu stu[200];
	for (int i = 0; i < total; i++)
	{
		scanf("%s %d %d", &stu[i].ID, &stu[i].total, &stu[i].English);
	}
	qsort(stu, total, sizeof(stu[0]), cmp);
	for (int i = total - 1; i > total - available - 1; i--)
	{
		printf("%s %d %d\n", stu[i].ID, stu[i].total, stu[i].English);
	}
}

int cmp(const void* a, const void* b)
{
	return (*(Stu*)a).total > (*(Stu*)b).total || (*(Stu*)a).total == (*(Stu*)b).total && (*(Stu*)a).English > (*(Stu*)b).English || (*(Stu*)a).total == (*(Stu*)b).total && (*(Stu*)a).English == (*(Stu*)b).English && strcmp((*(Stu*)a).ID, (*(Stu*)b).ID) < 0 ? 1 : -1;
}
