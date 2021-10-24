#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Student
{
public:
	int ID;
	string name;
	int s1, s2, s3;
	double ave;
	void init();
	void show();
};

void Student::init()
{
	cin >> ID >> name >> s1 >> s2 >> s3;
	ave = (s1 + s2 + s3) / 3.0;
}

void Student::show()
{
	cout << ID << ' ' << name << ' ';
	printf("%.1f\n", ave);
}

int cmp(const void* p1, const void* p2)
{
	Student* a = (Student*)p1;
	Student* b = (Student*)p2;
	if (a->ave > b->ave) return -1;
	if (a->ave == b->ave && a->ID < b->ID) return -1;
	return 1;
}

int main()
{
	int n;
	cin >> n;
	Student stu[n];
	for (int i = 0; i < n; i++)
	{
		stu[i].init();
	}
	qsort(stu, n, sizeof(stu[0]), cmp);
	for (int i = 0; i < n; i++)
	{
		stu[i].show();
	}
}
