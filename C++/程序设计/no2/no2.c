/*
* ����������ջģ�� 
* ��Ա�����죬������ 
* ���ܣ���������ģ���ջ 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ģ��ջ������val ���Ԫ�ص�ֵ��nextΪ��һԪ�صĵ�ַ 
typetef struct Zhan {
	int val;
	struct Zhan* next;
}ZHAN;

//��ջ���� 
ZHAN* push(ZHAN* head, int val) {
	ZHAN* newNode = (ZHAN*)malloc(sizeof(ZHAN));
	if (newNode == NULL) return NULL;
	newNode->val = val;
	newNode->next = head;
	return newNode;
}

//��ջ���� 
ZHAN* pop(ZHAN* head) {
	ZHAN* nextNode = head->next;
	free(head);
	return nextNode;
}

//չʾջ������Ԫ�� 
void show(ZHAN* head) {
	if (head == NULL) {
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ��Ԫ�أ�\n[");
		while (head != NULL) {
			printf("%d, ", head->val);
			head = head->next;
		}
		printf("\b\b]\n");
	}
}

int main()
{
	ZHAN* head = NULL; //�������ͷ 
	char cmd[10] = { 0 }; //���Ҫ��������� 
	do
	{
		printf("��ջ����\"push + ��ֵ\"����ջ����\"pop\"���˳�����\"q\"\n>");
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			int val;
			scanf("%d", &val);
			head = push(head, val);
			if (head != NULL)
			{
				printf("�ɹ���ջ��\n%d\n", val);
			}
			else
			{
				printf("��ջʧ��");
			}
			show(head);
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			if (head != NULL)
			{
				int val = head->val;
				head = pop(head);
				printf("��ջԪ�أ�%d\n", val);
				show(head);
			}
			else
			{
				printf("ջΪ��\n");
			}
		}
		else if (cmd[0] != 'q')
		{
			printf("�������\n");
		}
	} while (cmd[0] != 'q');
}