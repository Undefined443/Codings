/*
* 程序名：长整数计算器 
* 功能：实现长整数加减法，可操作正负数 
* 成员：李潇，吴兴祺 
*/

#define LENGTH 1000 //长整数位数 
#define POSITIVE 0 //正号标记 
#define NEGATIVE 1 //负号标记 
#include <stdio.h>
#include <ctype.h>

//数组指针交换函数 
void swap(int** a, int** b)
{
	int* t = *a;
	*a = *b;
	*b = t;
}

//储存长整数函数 
int saveLongInteger(int* integerArray, char* charArray)
{
	int j = 2; //长整数数组索引，数组前两位用于储存符号和位数，因此从2开始 
	for (int i = LENGTH; i > 0; i--)
	{
		if (charArray[i] != 0)
		{
			if (isdigit(charArray[i])) //检查输入正确性 
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
	switch (charArray[0]) //填充符号位 
	{
	case '+':
		integerArray[0] = POSITIVE;
		break;
	case '-':
		integerArray[0] = NEGATIVE;
		break;
	default: //输入省略正号的情况 
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

//长整数加法函数 
void addLongInteger(int* result, int* num_1, int* num_2)
{
	int t = 0; //储存进位 
	for (int i = 2; i < LENGTH; i++)
	{
		result[i] = num_1[i] + num_2[i] + t;
		t = result[i] / 10;
		result[i] %= 10;
	}
	result[0] = num_1[0]; //默认两数同号，因此将其中一个数的符号作为结果的符号 
}

//长整数减法函数 
void subtractLongInteger(int* result, int* num_1, int* num_2)
{
	result[0] = num_1[0];
	//将 num_1, num_2 按绝对值由大到小排序 
	if (num_1[1] < num_2[1]) //num_1 的位数小于 num_2 的情况 
	{
		swap(&num_1, &num_2);
		result[0] = NEGATIVE;
	}
	else if (num_1[1] == num_2[1]) //位数相同，逐位比较大小
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
	
	
	if (num_1[1] == num_2[1] && num_1[num_1[1] + 1] < num_2[num_2[1] + 1]) //num_1 与 num_2 位数相同,但 num_1 的首位比 num_2 小的情况 
	{
		swap(&num_1, &num_2);
		result[0] = NEGATIVE;
	}
	int t = 0; //储存借位 
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
	int longInteger_1[LENGTH + 1] = { 0 }; //长整数数组，+1 防止数组越界 
	int longInteger_2[LENGTH + 1] = { 0 };
	char charLongInteger[LENGTH + 1] = { 0 }; //长整数字符串 
	printf("输入数字1：\n>");
	scanf("%s", charLongInteger);
	if (saveLongInteger(longInteger_1, charLongInteger) == -1) //将长整数字符串转换为数组，同时处理输入错误的情况 
	{
		printf("输入错误\n");
		return -1;
	}
	for (int i = 0; i < LENGTH; i++) //重置长整数字符串，以便重新输入 
	{
		charLongInteger[i] = 0;
	}
	printf("输入数字2：\n>");
	scanf("%s", charLongInteger);
	if (saveLongInteger(longInteger_2, charLongInteger) == -1)
	{
		printf("输入错误\n");
		return -1;
	}
	int mode;
	printf("操作：\n1. 相加  2. 相减\n>");
	scanf("%d", &mode);
	int result[LENGTH + 1] = { 0 };
	switch (mode)
	{
	case 1: //加法 
		if (longInteger_1[0] == longInteger_2[0]) //判断两数符号是否相同 
		{
			addLongInteger(result, longInteger_1, longInteger_2);
		}
		else //符号不同时将加法转换为减法 
		{
			if (longInteger_2[0] == NEGATIVE) //numz-2 为负时相当于 num_1 - |num_2| 
			{
				longInteger_2[0] = POSITIVE;
				subtractLongInteger(result, longInteger_1, longInteger_2);
			}
			else //num_1 为负时相当于 num_2 - |num_1|
			{
				longInteger_1[0] = POSITIVE;
				subtractLongInteger(result, longInteger_2, longInteger_1);
			}
		}
		printf("它们的和是：");
		break;
	case 2: //减法 
		if (longInteger_1[0] == longInteger_2[0]) //同号情况 
		{
			subtractLongInteger(result, longInteger_1, longInteger_2);
		}
		else
		{
			if (longInteger_2[0] == NEGATIVE) //num_2 为负，相当于 num_1 + |num_2| 
			{
				longInteger_2[0] = POSITIVE;
				addLongInteger(result, longInteger_1, longInteger_2);
			}
			else //num_1 为负，相当于 -(|num_1| + num_2) 
			{
				longInteger_2[0] = NEGATIVE;
				addLongInteger(result, longInteger_2, longInteger_1);
			}
		}
		printf("它们的差是：");
		break;
	default:
		printf("输入错误\n");
		return -1;
	}
	if (result[0] == NEGATIVE) //如果是负数先输出'-'号 
	{
		printf("-");
	}
	int flag = 0; //用于判断结果的首位是否为零 
	for (int i = LENGTH; i > 1; i--)
	{
		if (result[i] == 0 && flag == 0) //首位为零则不输出数字，跳到下一次循环 
		{
			continue;
		}
		printf("%d", result[i]);
		flag = 1;
	}
	if (flag == 0)
	{
		printf("0"); //若未输出任何数字则答案为零 
	}
	printf("\n");
	return 0;
}