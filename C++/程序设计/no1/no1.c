/*
* �������������������� 
* ���ܣ�ʵ�ֳ������Ӽ������ɲ��������� 
* ��Ա�����죬������ 
*/

#define LENGTH 1000 //������λ�� 
#define POSITIVE 0 //���ű�� 
#define NEGATIVE 1 //���ű�� 
#include <stdio.h>
#include <ctype.h>

//����ָ�뽻������ 
void swap(int** a, int** b)
{
	int* t = *a;
	*a = *b;
	*b = t;
}

//���泤�������� 
int saveLongInteger(int* integerArray, char* charArray)
{
	int j = 2; //��������������������ǰ��λ���ڴ�����ź�λ������˴�2��ʼ 
	for (int i = LENGTH; i > 0; i--)
	{
		if (charArray[i] != 0)
		{
			if (isdigit(charArray[i])) //���������ȷ�� 
			{
				integerArray[j] = charArray[i] - '0';
				j++;
			}
			else
			{
				return -1;
			}
		}
	}
	switch (charArray[0]) //������λ 
	{
	case '+':
		integerArray[0] = POSITIVE;
		break;
	case '-':
		integerArray[0] = NEGATIVE;
		break;
	default: //����ʡ�����ŵ���� 
		if (isdigit(charArray[0]))
		{
			integerArray[j] = charArray[0] - '0';
			j++;
			integerArray[0] = POSITIVE;
		}
		else
		{
			return -1;
		}
		break;
	}
	integerArray[1] = j - 2;
	return 0;
}

//�������ӷ����� 
void addLongInteger(int* result, int* num_1, int* num_2)
{
	int t = 0; //�����λ 
	for (int i = 2; i < LENGTH; i++)
	{
		result[i] = num_1[i] + num_2[i] + t;
		t = result[i] / 10;
		result[i] %= 10;
	}
	result[0] = num_1[0]; //Ĭ������ͬ�ţ���˽�����һ�����ķ�����Ϊ����ķ��� 
}

//�������������� 
void subtractLongInteger(int* result, int* num_1, int* num_2)
{
	result[0] = num_1[0];
	//�� num_1, num_2 ������ֵ�ɴ�С���� 
	if (num_1[1] < num_2[1]) //num_1 ��λ��С�� num_2 ����� 
	{
		swap(&num_1, &num_2);
		result[0] = NEGATIVE;
	}
	else if (num_1[1] == num_2[1]) //λ����ͬ����λ�Ƚϴ�С
	{
		for (int i = LENGTH; i > 1; i--)
		{
			if (num_1[i] > num_2[i])
			{
				break;
			}
			else if (num_1[i] < num_2[i])
			{
				swap(&num_1, &num_2);
				result[0] = NEGATIVE;
				break;
			}
		}
		
	}
	
	
	if (num_1[1] == num_2[1] && num_1[num_1[1] + 1] < num_2[num_2[1] + 1]) //num_1 �� num_2 λ����ͬ,�� num_1 ����λ�� num_2 С����� 
	{
		swap(&num_1, &num_2);
		result[0] = NEGATIVE;
	}
	int t = 0; //�����λ 
	for (int i = 2; i < LENGTH; i++)
	{
		result[i] = num_1[i] - num_2[i] - t;
		if (result[i] < 0)
		{
			result[i] += 10;
			t = 1;
		}
		else
		{
			t = 0;
		}
	}
}

int main()
{
	int longInteger_1[LENGTH + 1] = { 0 }; //���������飬+1 ��ֹ����Խ�� 
	int longInteger_2[LENGTH + 1] = { 0 };
	char charLongInteger[LENGTH + 1] = { 0 }; //�������ַ��� 
	printf("��������1��\n>");
	scanf("%s", charLongInteger);
	if (saveLongInteger(longInteger_1, charLongInteger) == -1) //���������ַ���ת��Ϊ���飬ͬʱ��������������� 
	{
		printf("�������\n");
		return -1;
	}
	for (int i = 0; i < LENGTH; i++) //���ó������ַ������Ա��������� 
	{
		charLongInteger[i] = 0;
	}
	printf("��������2��\n>");
	scanf("%s", charLongInteger);
	if (saveLongInteger(longInteger_2, charLongInteger) == -1)
	{
		printf("�������\n");
		return -1;
	}
	int mode;
	printf("������\n1. ���  2. ���\n>");
	scanf("%d", &mode);
	int result[LENGTH + 1] = { 0 };
	switch (mode)
	{
	case 1: //�ӷ� 
		if (longInteger_1[0] == longInteger_2[0]) //�ж����������Ƿ���ͬ 
		{
			addLongInteger(result, longInteger_1, longInteger_2);
		}
		else //���Ų�ͬʱ���ӷ�ת��Ϊ���� 
		{
			if (longInteger_2[0] == NEGATIVE) //numz-2 Ϊ��ʱ�൱�� num_1 - |num_2| 
			{
				longInteger_2[0] = POSITIVE;
				subtractLongInteger(result, longInteger_1, longInteger_2);
			}
			else //num_1 Ϊ��ʱ�൱�� num_2 - |num_1|
			{
				longInteger_1[0] = POSITIVE;
				subtractLongInteger(result, longInteger_2, longInteger_1);
			}
		}
		printf("���ǵĺ��ǣ�");
		break;
	case 2: //���� 
		if (longInteger_1[0] == longInteger_2[0]) //ͬ����� 
		{
			subtractLongInteger(result, longInteger_1, longInteger_2);
		}
		else
		{
			if (longInteger_2[0] == NEGATIVE) //num_2 Ϊ�����൱�� num_1 + |num_2| 
			{
				longInteger_2[0] = POSITIVE;
				addLongInteger(result, longInteger_1, longInteger_2);
			}
			else //num_1 Ϊ�����൱�� -(|num_1| + num_2) 
			{
				longInteger_2[0] = NEGATIVE;
				addLongInteger(result, longInteger_2, longInteger_1);
			}
		}
		printf("���ǵĲ��ǣ�");
		break;
	default:
		printf("�������\n");
		return -1;
	}
	if (result[0] == NEGATIVE) //����Ǹ��������'-'�� 
	{
		printf("-");
	}
	int flag = 0; //�����жϽ������λ�Ƿ�Ϊ�� 
	for (int i = LENGTH; i > 1; i--)
	{
		if (result[i] == 0 && flag == 0) //��λΪ����������֣�������һ��ѭ�� 
		{
			continue;
		}
		printf("%d", result[i]);
		flag = 1;
	}
	if (flag == 0)
	{
		printf("0"); //��δ����κ��������Ϊ�� 
	}
	printf("\n");
	return 0;
}