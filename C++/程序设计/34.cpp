#include <iostream>
#include <math.h>
using namespace std;

int function(int, int);

int main()
{
	int a, b;
	cin >> a >> b;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (a < 100) a = 100;
	cout << function(a, b);
}

int function(int a, int b)
{
	int result = 0;
	for (int i = a; i <= b; i++)//从a到b逐个分析每个数 
	{
		int store[4];//用来储存每一位上的数 
		int temp = i;
		int wei = 0;//第wei+1位 
		int sum = 0;
		while (temp)//取各位上的数并计算位数 
		{
			store[wei] = temp % 10;
			temp /= 10;
			wei++;//最后有wei位 
		}
		for (int k = 0; k < wei; k++)//计算总和，并比较 
		{
			sum += pow(store[k], wei);
		}
		if (sum == i) result++;
	}
	return result;
}
