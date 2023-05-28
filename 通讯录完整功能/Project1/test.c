#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"

void menu()
{
	printf("***************************************************\n");
	printf("********    1.增加              2.删除     ********\n");
	printf("********    3.查找              4.修改     ********\n");
	printf("********    5.查看              6.排序     ********\n");
	printf("********    0.退出                         ********\n");
	printf("***************************************************\n");
}

int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SercachContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
				break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出程序\n");break;
		default:
			printf("选择错误，重新选择\n");break;
		}

	} while (input);
	return 0;
}
