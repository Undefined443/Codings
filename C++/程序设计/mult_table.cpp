#include <stdio.h>

int main()
{
	for(int i = 1; i <= 9; i++)
	{
		for(int k = 1; k <= i; k++)
		{
			printf("%-3d", k*i);
		}
		printf("\n");
	}
}
