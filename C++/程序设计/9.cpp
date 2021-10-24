#include <stdio.h>
int main()
{
	int Fe, Au;
	scanf("%d%d", &Fe, &Au);
	const double PI = 3.1415926;
	double mFe = 7.86 * 4 * PI * Fe * Fe * Fe * 0.001 / 24;
	double mAu= 19.3 * 4 * PI * Au * Au * Au * 0.001 / 24;
	printf("%.3f %.3f", mFe, mAu);
	return 0;
}
