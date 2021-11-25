#pragma once
#define MAX 10 //ÿ����������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct BOOK {
	int ID;
	char name[10];
	int inventory;
	int borrowedBy[MAX];
}Book;

typedef struct USER {
	int ID;
	char name[10];
	int borrowed;
}User;

typedef struct BOOKLIST {
	Book book;
	struct BOOKLIST* previous;
	struct BOOKLIST* next;
}BookList;

typedef struct USERLIST {
	User user;
	struct USERLIST* previous;
	struct USERLIST* next;
}UserList;

//��ʾ�û��˵�
void showUserMenu()
{
	printf(".               User               .\n");
	printf(". 1-> Borrow book                  .\n");
	printf(". 2-> Return book                  .\n");
	printf(". 3-> Search book                  .\n");
	printf(". 4-> Search the borrowed book     .\n");
	printf(". 5-> Change user                  .\n");
	printf(". 6-> Quit                         .\n");
	printf(". Please select a number           .\n>");
}

//��ʾ����Ա�˵�
void showAdminMenu()
{
	printf(".            Administor            .\n");
	printf(". 1-> Add book information         .\n");
	printf(". 2-> Modify book information      .\n");
	printf(". 3-> Delete book                  .\n");
	printf(". 4-> Add User information         .\n");
	printf(". 5-> Modify User information      .\n");
	printf(". 6-> Delete  User                 .\n");
	printf(". 7-> Change user                  .\n");
	printf(". 8-> Quit                         .\n");
	printf(". Please select a number           .\n>");
}

//��ѯ�鼮����ʹ��ID����������
BookList* searchBook(const char* str, BookList* list)
{
	BookList* result = NULL;
	if (isalpha(str[0])) //ͨ����������
	{
		const char* name = str;
		while (list != NULL)
		{
			if (strcmp(name, list->book.name) == 0)
			{
				result = list;
				break;
			}
			list = list->next;
		}
	}
	else //ͨ��ID����
	{
		int ID = atoi(str);
		while (list != NULL)
		{
			if (list->book.ID == ID)
			{
				result = list;
				break;
			}
			list = list->next;
		}
	}
	return result;
}

//�����û�����ʹ��ID���û�������
UserList* searchUser(const char* str, UserList* list)
{
	UserList* result = NULL;
	if (isalpha(str[0])) //ͨ���û�������
	{
		const char* name = str;
		while (list != NULL)
		{
			if (strcmp(name, list->user.name) == 0)
			{
				result = list;
				break;
			}
			list = list->next;
		}
	}
	else //ͨ��ID����
	{
		int ID = atoi(str);
		while (list != NULL)
		{
			if (list->user.ID == ID)
			{
				result = list;
				break;
			}
			list = list->next;
		}
	}
	return result;
}

//����Ա����
//������Ŀ
BookList* addBook(int ID, const char* name, int inventory, int borrowedBy[], BookList* head)
{
	BookList* bookNode = (BookList*)calloc(1, sizeof(BookList));
	if (bookNode == NULL)
	{
		return NULL;
	}
	bookNode->next = head;
	bookNode->previous = NULL;

	bookNode->book.ID = ID;
	bookNode->book.inventory = inventory;
	strcpy(bookNode->book.name, name);
	if (borrowedBy != NULL)
	{
		for (int i = 0; i < MAX; i++)
		{
			bookNode->book.borrowedBy[i] = borrowedBy[i];
		}
	}
	if (head != NULL)
	{
		head->previous = bookNode;
	}
	return bookNode;
}

//�����û�
UserList* addUser(int ID, const char* name, int borrowed, UserList* head)
{
	UserList* userNode = (UserList*)calloc(1, sizeof(UserList));
	if (userNode == NULL)
	{
		return NULL;
	}
	userNode->next = head;
	userNode->previous = NULL;

	userNode->user.ID = ID;
	userNode->user.borrowed = borrowed;
	strcpy(userNode->user.name, name);
	if (head != NULL)
	{
		head->previous = userNode;
	}
	return userNode;
}

//ɾ����Ŀ
void deleteBook(BookList* target)
{
	BookList* previous = target->previous;
	BookList* next = target->next;
	if (previous != NULL)
	{
		previous->next = next;
	}
	if (next != NULL)
	{
		next->previous = previous;
	}
	free(target);
}

//ɾ���û�
void deleteUser(UserList* target)
{
	UserList* previous = target->previous;
	UserList* next = target->next;
	if (previous != NULL)
	{
		previous->next = next;
	}
	if (next != NULL)
	{
		next->previous = previous;
	}
	free(target);
}

//�޸��鼮��Ϣ����Ӧ����������鱾ID����ΪID���鱾��Ψһ��ʶ����ֻ�ܸ���������
void editBook(const char* name, int inventory, Book* target)
{
	strcpy(target->name, name);
}

//�޸��û���Ϣ
void editUser(const char* name, User* target)
{
	strcpy(target->name, name);
}

//�û�����
//����
int borrowBook(Book* book, User* user)
{
	if (book->inventory == 0) //���鼮�ѽ���
	{
		return -1;
	}
	book->inventory -= 1;
	user->borrowed = book->ID;
	for (int i = 0; i < MAX; i++)
	{
		if (book->borrowedBy[i] == 0)
		{
			book->borrowedBy[i] = user->ID;
			return 0;
		}
	}
}

//����
const char* returnBook(BookList* bookList, User* user)
{
	BookList* target = searchBook(user->borrowed, bookList);
	target->book.inventory += 1;
	user->borrowed = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (target->book.borrowedBy[i] == user->ID)
		{
			target->book.borrowedBy[i] = 0;
			break;
		}
	}
	return target->book.name;
}

//�洢ͼ�������Ϣ�ļ�
void saveArchive(BookList* bookList, UserList* userList)
{
	FILE* archive = fopen("archive.txt", "w");
	BookList* bhead = bookList;
	int count = 0;
	while (bhead != NULL)
	{
		count++;
		bhead = bhead->next;
	}
	fprintf(archive, "----------Book----------\n[%d books]\n", count);
	while (bookList != NULL)
	{
		fprintf(archive, "------------------\nID: %d\nName: %s\nInventory: %d\n", bookList->book.ID, bookList->book.name, bookList->book.inventory);
		fprintf(archive, "Borrowed by:\n");
		for (int i = 0; i < MAX; i++)
		{
			if (bookList->book.borrowedBy[i] != 0)
			{
				fprintf(archive, "%d\n", bookList->book.borrowedBy[i]);
			}
		}
		fprintf(archive, "%d\n", 0); //�������
		fprintf(archive, "------------------\n");
		bookList = bookList->next;
	}
	UserList* uhead = userList;
	count = 0;
	while (uhead != NULL)
	{
		count++;
		uhead = uhead->next;
	}
	fprintf(archive, "----------User----------\n[%d users]\n", count);
	while (userList != NULL)
	{
		fprintf(archive, "------------------\nID: %d\nName: %s\nBorrowed: %d\n", userList->user.ID, userList->user.name, userList->user.borrowed);
		fprintf(archive, "------------------\n");
		userList = userList->next;
	}
	fclose(archive);
}

//��ȡͼ�������Ϣ�ļ�
void loadArchive(BookList** bookList, UserList** userList)
{
	printf("Loading archive from file...\n");
	FILE* archive = fopen("archive.txt", "r");
	if (archive == NULL)
	{
		printf("File not found.\n");
		return;
	}
	int		count;
	int		ID;
	int		inventory;
	int		borrowed;
	int		borrowedBy[MAX] = { 0 };
	char	name[10] = { 0 };
	char	buffer[30] = { 0 };

	if (fscanf(archive, "%s", buffer) == EOF)
	{
		printf("Empty file.\n");
		return;
	}
	printf("Books...\n");
	if (strcmp(buffer, "----------Book----------") != 0)
	{
		printf("Format error!\n");
		return;
	}
	fscanf(archive, "%*c%*c%d%*s", &count);
	for (int i = 0; i < count; i++)
	{
		fscanf(archive, "%s", buffer);
		if (strcmp(buffer, "------------------") != 0)
		{
			printf("Format error!\n");
			return;
		}
		fscanf(archive, "%*s%d%*s%s%*s%d", &ID, name, &inventory);
		fscanf(archive, "%*s%*s"); //����"Borrowed by:"
		for (int i = 0; i < MAX; i++)
		{
			fscanf(archive, "%d", &borrowedBy[i]);
			if (borrowedBy[i] == 0)
			{
				break;
			}
		}
		fscanf(archive, "%s", buffer);
		if (strcmp(buffer, "------------------") != 0)
		{
			printf("Format error!\n");
			return;
		}
		*bookList = addBook(ID, name, inventory, borrowedBy, *bookList);
		//��ʾ��ȡ������Ϣ
		printf("ID: %d\nName: %s\nInventory: %d\n", ID, name, inventory);
		printf("Borrowed by:\n");
		int flag = 0;
		for (int i = 0; i < MAX; i++)
		{
			if (borrowedBy[i] != 0)
			{
				printf("%d\n", borrowedBy[i]);
				borrowedBy[i] = 0;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("null\n");
		}
	}
	printf("Users...\n");
	fscanf(archive, "%s", buffer);
	if (strcmp(buffer, "----------User----------") != 0)
	{
		printf("Format error!\n");
		return;
	}
	fscanf(archive, "%*c%*c%d%*s", &count);
	for (int i = 0; i < count; i++)
	{
		fscanf(archive, "%s", buffer);
		if (strcmp(buffer, "------------------") != 0)
		{
			printf("Format error!\n");
			return;
		}
		fscanf(archive, "%*s%d%*s%s%*s%d", &ID, name, &borrowed);
		fscanf(archive, "%s", buffer);
		if (strcmp(buffer, "------------------") != 0)
		{
			printf("Format error!\n");
			return;
		}
		*userList = addUser(ID, name, borrowed, *userList);
		//��ʾ��ȡ������Ϣ
		printf("ID: %d\nName: %s\nBorrowed: %d\n", ID, name, borrowed);
	}
	printf("All of the information has been loaded.\n");
	fclose(archive);
}