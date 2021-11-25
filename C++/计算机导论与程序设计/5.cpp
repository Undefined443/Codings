#include <iostream>
using namespace std;

int main()
{
	int y_, x_;
	cin >> y_ >> x_;
	int data[x_][y_];
	for (int y = 0; y < y_; y++)//input the data
	{
		for (int x = 0; x < x_; x++)
		{
			cin >> data[x][y];
		}
	}
	//remark each group of sequence's end position and it's length
	//remark each row
	int endpos_y[y_][x_ >= 3 ? x_ / 3 : 1] = { 0 };
	int length_y[y_][x_ >= 3 ? x_ / 3 : 1] = { 0 };
	int group_y[y_] = { 0 };
	//remark each column
	int endpos_x[x_][y_ >= 3 ? y_ / 3 : 1] = { 0 };
	int length_x[x_][y_ >= 3 ? y_ / 3 : 1] = { 0 };
	int group_x[x_] = { 0 };
	int sequence = 0;
	for (int y = 0; y < y_; y++)//scan by row
	{
		for (int x = 0; x < x_ - 1; x++)
		{
			if (data[x][y] == data[x + 1][y])
			{
				sequence++;
			}
			else
			{
				if (sequence >= 2)
				{
					endpos_y[y][group_y[y]] = x;
					length_y[y][group_y[y]] = sequence;
					group_y[y]++;
				}
				sequence = 0;
			}
		}
		//now at the end of the row
		if (sequence >= 2)
		{
			endpos_y[y][group_y[y]] = x_ - 1;
			length_y[y][group_y[y]] = sequence;
			group_y[y]++;
		}
		sequence = 0;
	}
	for (int x = 0; x < x_; x++)//scan by column
	{
		for (int y = 0; y < y_ - 1; y++)
		{
			if (data[x][y] == data[x][y + 1])
			{
				sequence++;
			}
			else
			{
				if (sequence >= 2)
				{
					endpos_x[x][group_x[x]] = y;
					length_x[x][group_x[x]] = sequence;
					group_x[x]++;
				}
				sequence = 0;
			}
		}
		//at the end case
		if (sequence >= 2)
		{
			endpos_x[x][group_x[x]] = y_ - 1;
			length_x[x][group_x[x]] = sequence;
			group_x[x]++;
		}
		sequence = 0;
	}
	for (int y = 0; y < y_; y++)//delete by row
	{
		for (int group = 0; group < group_y[y]; group++)
		{
			for (int x = endpos_y[y][group] - length_y[y][group]; x <= endpos_y[y][group]; x++)
			{
				data[x][y] = 0;
			}
		}
	}
	for (int x = 0; x < x_; x++)//delete by column
	{
		for (int group = 0; group < group_x[x]; group++)
		{
			for (int y = endpos_x[x][group] - length_x[x][group]; y <= endpos_x[x][group]; y++)
			{
				data[x][y] = 0;
			}
		}
	}
	for (int y = 0; y < y_; y++)//output
	{
		for (int x = 0; x < x_; x++)
		{
			cout << data[x][y] << ' ';
		}
		cout << endl;
	}
}
