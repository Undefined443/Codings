#include <stdio.h>

double icos(double x);//自定义cos 
long long factorial(int n);//阶乘 
double ipow(double x, int y);//自定义pow 

int main()
{
	int n;
	scanf("%d", &n);
	double x[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &x[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%f", icos(x[i]));
	}
}

double icos(double x)
{
	double result = 1.0;
	long double plus = ipow(x, 2) / 2.0;
	result += -plus;
	for (int i = 2; plus >= 0.0004; i++)
	{
		plus = ipow(x, 2 * i) / factorial(2 * i);
		result += ipow(-1.0, i) * plus;
	}
	return result;
}

long long factorial(int n)
{
	long long factorial = 1;
	for (int i = n; i > 1; i--)
	{
		factorial *= i;
	}
	return factorial;
}

double ipow(double x, int y)
{
	double a = x;
	for (int i = 1; i < y; i++)
	{
		a *= x;
	}
	return a;
}
