#include <stdio.h>
int main()
{
	int n;
	int I = 0, II = 0, III = 0, IV = 0, V = 0, VI = 0;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d", &input);
		sum += input;
		if (input <= 50) I++;
		else if (input <= 100) II++;
		else if (input <= 150) III++;
		else if (input <= 200) IV++;
		else if (input <= 300) V++;
		else VI++;
	}
	double average = (double)sum / n;
	printf("%.2f\n%d %d %d %d %d %d", average, I, II, III, IV, V, VI);
}
