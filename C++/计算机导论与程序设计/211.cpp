#include <cstdio>

class Student
{
public:
	double score[4];
	double average = 0.0;
	int failed = 0;
	bool good = true;
	void init()
	{
		for (int i = 0; i < 4; i++)
		{
			scanf("%lf", &score[i]);
			average += score[i];
			if (score[i] < 85.0)
			{
				good = false;
				if (score[i] < 60.0) failed++;
			}
		}
		average /= 4.0;
		if (average >= 90.0) good = true;
	}
};

int fal(Student* stu);
int well(Student* stu);
double aver(Student* stu);

int main()
{
	Student stu[5];
	for (int i = 0; i < 5; i++)
	{
		stu[i].init();
	}
	printf("%.1f %d %d", aver(stu), fal(stu), well(stu));
}

int fal(Student* stu)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (stu[i].failed >= 2) sum++;
	}
	return sum;
}

int well(Student* stu)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (stu[i].good) sum++;
	}
	return sum;
}

double aver(Student* stu)
{
	double average = 0.0;
	for (int i = 0; i < 5; i++)
	{
		average += stu[i].score[0];
	}
	average /= 5.0;
	return average;
}
