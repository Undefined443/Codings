/*
* 程序名：堆栈模拟 
* 成员：李潇，吴兴祺 
* 功能：利用链表模拟堆栈 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用于模拟栈的链表，val 存放元素的值，next为下一元素的地址 
typetef struct Zhan {
	int val;
	struct Zhan* next;
}ZHAN;

//入栈函数 
ZHAN* push(ZHAN* head, int val) {
	ZHAN* newNode = (ZHAN*)malloc(sizeof(ZHAN));
	if (newNode == NULL) return NULL;
	newNode->val = val;
	newNode->next = head;
	return newNode;
}

//出栈函数 
ZHAN* pop(ZHAN* head) {
	ZHAN* nextNode = head->next;
	free(head);
	return nextNode;
}

//展示栈中所有元素 
void show(ZHAN* head) {
	if (head == NULL) {
		printf("栈为空\n");
	}
	else
	{
		printf("栈中元素：\n[");
		while (head != NULL) {
			printf("%d, ", head->val);
			head = head->next;
		}
		printf("\b\b]\n");
	}
}

int main()
{
	ZHAN* head = NULL; //存放链表头 
	char cmd[10] = { 0 }; //存放要处理的命令 
	do
	{
		printf("入栈输入\"push + 数值\"，出栈输入\"pop\"，退出输入\"q\"\n>");
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			int val;
			scanf("%d", &val);
			head = push(head, val);
			if (head != NULL)
			{
				printf("成功入栈：\n%d\n", val);
			}
			else
			{
				printf("入栈失败");
			}
			show(head);
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			if (head != NULL)
			{
				int val = head->val;
				head = pop(head);
				printf("出栈元素：%d\n", val);
				show(head);
			}
			else
			{
				printf("栈为空\n");
			}
		}
		else if (cmd[0] != 'q')
		{
			printf("命令错误\n");
		}
	} while (cmd[0] != 'q');
}