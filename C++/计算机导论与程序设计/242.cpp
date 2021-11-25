#include <cstdio>

class Student
{
public:
	int xuehao;
	char name[11];
	int score1, score2, score3;
	double average;
	void init()
	{
		scanf("%d %s %d%d%d", &xuehao, name, &score1, &score2, &score3);
		average = (score1 + score2 + score3) / 3.0;
	}
	void show()
	{
		printf("%d %s %.1f\n", xuehao, name, average);
	}
};

void swap(Student* stu1, Student* stu2);

int main()
{
	int n;
	scanf("%d", &n);
	Student stu[100];
	for (int i = 0; i < n; i++)
	{
		stu[i].init();
	}
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (stu[j].average < stu[j + 1].average)
			{
				swap(&stu[j], &stu[j + 1]);
				flag = true;
			}
			else if (stu[j].average == stu[j + 1].average && stu[j].xuehao > stu[j + 1].xuehao)
			{
				swap(&stu[j], &stu[j + 1]);
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (int i = 0; i < n; i++)
	{
		stu[i].show();
	}
}

void swap(Student* stu1, Student* stu2)
{
	Student temp = *stu1;
	*stu1 = *stu2;
	*stu2 = temp;
}
