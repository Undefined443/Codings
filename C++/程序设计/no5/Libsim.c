/*
* 程序名：模拟图书管理系统
* 成员：李潇，吴兴祺
*/
#include "Libsim.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv)
{
	//图书、用户链表头
	BookList* bookList = NULL;
	UserList* userList = NULL;

	BookList* targetBook;
	UserList* targetUser;

	int  mode;
	int  ID;
	char name[10];
	char buffer[10];
	int  inventory;

	//获取命令
	if (argc < 2)
	{
		printf("Using the command line parameters to open!");
		return -1;
	}
	char userType[3] = { 0 };
	char userName[10] = { 0 };
	strcpy(userType, argv[1]);
	if (argc >= 3)
	{
		strcpy(userName, argv[2]);
	}

	//读取图书信息文件
	loadArchive(&bookList, &userList);

	while (1)
	{
		if (strcmp(userType, "-a") == 0) //管理员模式
		{
			printf("User: administor\n");
			showAdminMenu();
			scanf("%d", &mode);
			switch (mode)
			{
			case 1: //增加书目
				//输入并检查
				printf("--------Add book information-------\n");
				printf("Book ID:\n>");
				scanf("%d", &ID);
				if (ID <= 0)
				{
					printf("Input error!\n");
					break;
				}
				_itoa(ID, buffer, 10);
				if (searchBook(buffer, bookList) != NULL)
				{
					printf("The book is already existing\n");
					break;
				}
				printf("Book name:\n>");
				scanf("%s", name);
				if (searchBook(name, bookList) != NULL)
				{
					printf("The book is already existing\n");
					break;
				}
				printf("Book inventory:\n>");
				scanf("%d", &inventory);
				if (inventory < 0)
				{
					printf("Input error!\n");
					break;
				}
				//执行操作
				bookList = addBook(ID, name, inventory, NULL, bookList);
				if (bookList == NULL)
				{
					printf("Error: Memory allocation failure!\nBook not added.\n");
					break;
				}
				printf("Book \"%s\" has been added\n", name);
				break;
			case 2: //修改书籍信息
				//输入并检查
				printf("------Modify book information------\n");
				printf("Book ID\\name:\n>");
				scanf("%s", buffer);
				targetBook = searchBook(buffer, bookList);
				if (targetBook == NULL)
				{
					printf("No such book\n");
					break;
				}
				printf("New name:\n>");
				scanf("%s", name);
				if (searchBook(name, bookList) != NULL)
				{
					printf("The book is already existing\n");
					break;
				}
				printf("New book inventory:\n>");
				scanf("%d", &inventory);
				if (inventory < 0)
				{
					printf("Input error!\n");
					break;
				}
				//执行操作
				editBook(name, inventory, &(targetBook->book));
				printf("Book information modified successfully\n");
				break;
			case 3: //删除书目
				//输入并检查
				printf("------------Delete book------------\n");
				printf("Book ID\\name\n>");
				scanf("%s", buffer);
				targetBook = searchBook(buffer, bookList);
				if (targetBook == NULL)
				{
					printf("No such book\n");
					break;
				}
				//执行操作
				strcpy(name, targetBook->book.name);
				deleteBook(targetBook);
				printf("Book \"%s\" has been deleted\n", name);
				break;
			case 4: //新增用户
				//输入并检查
				printf("--------Add User information-------\n");
				printf("User ID:\n>");
				scanf("%d", &ID);
				if (ID <= 0)
				{
					printf("Input error!\n");
					break;
				}
				_itoa(ID, buffer, 10);
				if (searchUser(buffer, userList) != NULL)
				{
					printf("The user is already existing\n");
					break;
				}
				printf("User name:\n>");
				scanf("%s", name);
				if (searchUser(name, userList) != NULL)
				{
					printf("The user is already existing\n");
					break;
				}
				//执行操作
				userList = addUser(ID, name, 0, userList);
				if (userList == NULL)
				{
					printf("Error! Memory allocation failure!\n");
					return -1;
				}
				printf("User \"%s\" has been added\n", name);
				break;
			case 5: //修改用户信息
				//输入并检查
				printf("------Modify User information------\n");
				printf("User ID\\name:\n");
				scanf("%s", buffer);
				targetUser = searchUser(buffer, userList);
				if (targetUser == NULL)
				{
					printf("No such user\n");
					break;
				}
				printf("New name:\n>");
				scanf("%s", name);
				if (searchUser(name, userList) != NULL)
				{
					printf("The user is already existing\n");
					break;
				}
				//执行操作
				editUser(name, &(targetUser->user));
				printf("User information modified successfully\n");
				break;
			case 6: //删除用户信息
				//输入并检查
				printf("------------Delete user------------\n");
				printf("User ID\\name\n>");
				scanf("%s", buffer);
				targetUser = searchUser(buffer, userList);
				if (targetUser == NULL)
				{
					printf("No such user\n");
					break;
				}
				//执行操作
				strcpy(name, targetUser->user.name);
				deleteUser(targetUser);
				printf("User \"%s\" has been deleted\n", name);
				break;
			case 7: //更改当前用户
				printf("------------Change user------------\n");
				printf("Log in: <-userType userName>\n>");
				scanf("%s", userType);
				if (strcmp(userType, "-u") == 0)
				{
					scanf("%s", userName);
				}
				break;
			case 8: //退出程序
				return 0;
			default:
				printf("Wrong number!\n");
				break;
			}
		}

		else if (strcmp(userType, "-u") == 0) //用户模式
		{
			if (argc < 2)
			{
				printf("User name:\n>");
				scanf("%s", userName);
				break;
			}
			targetUser = searchUser(userName, userList); //确认用户信息
			if (targetUser == NULL)
			{
				printf("No such user\n");
				printf("------------Change user------------\n");
				printf("Log in: <-userType userName>\n>");
				if (strcmp(userType, "-u") == 0)
				{
					scanf("%s", userName);
				}
				continue;
			}
			printf("User: %s\n", userName);
			showUserMenu();
			scanf("%d", &mode);
			switch (mode)
			{
			case 1: //借书
				printf("------------Borrow book------------\n");
				if (targetUser->user.borrowed != 0) //如果用户还有未还书籍，则此时不能借书
				{
					printf("You have already borrowed a book, return it before borrowing a new one.\n");
					break;
				}
				//输入并检查
				printf("Book ID\\name:\n>");
				scanf("%s", buffer);
				targetBook = searchBook(buffer, bookList);
				if (targetBook == NULL)
				{
					printf("No such book\n");
					break;
				}
				//执行操作
				strcpy(name, targetBook->book.name);
				if (borrowBook(&(targetBook->book), &(targetUser->user)) == -1)
				{
					printf("Book \"%s\" is borrowed out.\nTry again later.\n", name);
					break;
				}
				printf("You have borrowed \"%s\"\n", name);
				break;
			case 2: //还书
				printf("------------Return book------------\n");
				if (targetUser->user.borrowed == 0) //若用户没有未还书籍，则此时不用还书
				{
					printf("You have not borrowed any book.\n");
					break;
				}
				strcpy(name, returnBook(bookList, &(targetUser->user)));
				printf("You have returned \"%s\"\n", name);
				break;
			case 3: //查找书籍信息
				printf("------------Search book------------\n");
				printf("Book ID\\name:\n>");
				scanf("%s", buffer);
				targetBook = searchBook(buffer, bookList);
				if (targetBook == NULL)
				{
					printf("No such book\n");
					break;
				}
				printf("-------------Book info-------------\n");
				printf("ID:\t\t%d\n", targetBook->book.ID);
				printf("Name:\t\t%s\n", targetBook->book.name);
				printf("Inventory:\t%d\n", targetBook->book.inventory);
				printf("Borrowed by:\n");
				int flag = 0;
				for (int i = 0; i < MAX; i++)
				{
					if (targetBook->book.borrowedBy[i] != 0)
					{
						itoa(targetBook->book.borrowedBy[i], buffer, 10);
						targetUser = searchUser(buffer, userList);
						printf("%s\n", targetUser->user.name);
						flag = 1;
					}
				}
				if (flag == 0)
				{
					printf("null\n");
				}
				printf("----------------end----------------\n");
				break;
			case 4: //查询已借书籍
				printf("------Search the borrowed book-----\n");
				if (targetUser->user.borrowed == 0)
				{
					printf("You have not borrow any book\n");
					break;
				}
				_itoa(targetUser->user.borrowed, buffer, 10);
				targetBook = searchBook(buffer, bookList);
				printf("You have borrowed \"%s\".\n", targetBook->book.name);
				break;
			case 5: //更改当前用户
				printf("------------Change user------------\n");
				printf("Log in: <-userType userName>\n>");
				scanf("%s", userType);
				if (strcmp(userType, "-u") == 0)
				{
					scanf("%s", userName);
				}
				break;
			case 6: //退出程序
				return 0;
			default:
				printf("You entered wrong number\n");
				break;
			}
		}
		else
		{
			printf("Wrong parameter!\n");
			return -1;
		}
		saveArchive(bookList, userList);
		printf("\n");
	}
}