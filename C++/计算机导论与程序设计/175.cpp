#include <iostream>
#include <vector>
using namespace std;

class WIN
{
public:
	int x1, x2, y1, y2;
	int index;
	void init(int i)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		index = i;
	}
	int select(int x, int y)
	{
		return x >= x1 && x <= x2 && y >= y1 && y <= y2;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<WIN> Win;
	WIN temp;
	for (int i = 0; i < N; i++)
	{
		temp.init(1 + i);
		Win.insert(Win.begin(), temp);
	}
	int x, y;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		bool flag = false;
		for (vector<WIN>::iterator it = Win.begin(); it != Win.end(); it++)
		{
			if (it->select(x, y))
			{
				flag = true;
				cout << it->index << endl;
				temp = *it;
				Win.erase(it);
				Win.insert(Win.begin(), temp);
				break;
			}
		}
		if (!flag) cout << "IGNORED" << endl;
	}
}
