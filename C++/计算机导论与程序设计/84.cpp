#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char cmd[200] = { 0 }, catalogue[200] = { 0 };
	cin.getline(catalogue, 200);
	while (cin.getline(cmd, 200), strcmp(cmd, "pwd"))
	{
		int i = strlen(catalogue) - 1;
		switch (cmd[3])
		{
		case '/':
			strcpy(catalogue, cmd + 3);
			break;
		case '.':
			while (catalogue[i] != '/')
			{
				catalogue[i--] = 0;
			}
			if (i) catalogue[i] = 0;
			break;
		default:
			if (i) catalogue[i + 1] = '/';
			strcat(catalogue, cmd + 3);
			break;
		}
	}
	cout << catalogue;
}
