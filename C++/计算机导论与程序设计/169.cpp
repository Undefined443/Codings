#include <iostream>
using namespace std;

class File
{
public:
	/*File();*/
	void init();
	int m_year, m_month, m_day;
	int m_size;
};

bool filecmp(File a, File b);

int main()
{
	File F[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		F[i].init();
	}
	bool flag;
	File Temp;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (!filecmp(F[j], F[j + 1]))
			{
				Temp = F[j];
				F[j] = F[j + 1];
				F[j + 1] = Temp;
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d/%d/%d %d\n", F[i].m_year, F[i].m_month, F[i].m_day, F[i].m_size);
	}
}

//File::File() :m_year(0), m_month(0), m_day(0), m_size(0)
//{
//	;
//}

void File::init()
{
	scanf("%d/%d/%d %d", &m_year, &m_month, &m_day, &m_size);
}

bool filecmp(File a, File b)
{
	if (a.m_year > b.m_year) return true;
	if (a.m_year == b.m_year && a.m_month > b.m_month) return true;
	if (a.m_year == b.m_year && a.m_month == b.m_month && a.m_day > b.m_day) return true;
	if (a.m_year == b.m_year && a.m_month == b.m_month && a.m_day == b.m_day && a.m_size > b.m_size)return true;
	return false;
}
