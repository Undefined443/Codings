#include <iostream>
using namespace std;

class Student
{
public:
	char name[11];
	int score[5];
	int extra;
	int sum = 0;
	void init()
	{
		cin >> name;
		for (int i = 0; i < 5; i++)
		{
			cin >> score[i];
			sum += score[i];
		}
		cin >> extra;
		sum += extra;
	}
	void show()
	{
		cout << name << ' ' << sum << ' ' << extra << endl;
	}
};

void swap(Student* stu1, Student* stu2);

int main()
{
	int n;
	cin >> n;
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
			if (stu[j].sum < stu[j + 1].sum)
			{
				swap(&stu[j], &stu[j + 1]);
				flag = true;
			}
			else if (stu[j].sum == stu[j + 1].sum && stu[j].extra < stu[j + 1].extra)
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
