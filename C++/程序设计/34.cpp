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
	for (int i = a; i <= b; i++)//��a��b�������ÿ���� 
	{
		int store[4];//��������ÿһλ�ϵ��� 
		int temp = i;
		int wei = 0;//��wei+1λ 
		int sum = 0;
		while (temp)//ȡ��λ�ϵ���������λ�� 
		{
			store[wei] = temp % 10;
			temp /= 10;
			wei++;//�����weiλ 
		}
		for (int k = 0; k < wei; k++)//�����ܺͣ����Ƚ� 
		{
			sum += pow(store[k], wei);
		}
		if (sum == i) result++;
	}
	return result;
}
