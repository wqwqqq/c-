#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"

void menu()
{
	printf("***************************************************\n");
	printf("********    1.����              2.ɾ��     ********\n");
	printf("********    3.����              4.�޸�     ********\n");
	printf("********    5.�鿴              6.����     ********\n");
	printf("********    7.�洢              0.�˳�     ********\n");
	printf("***************************************************\n");
}

int main()
{
	int input = 0;
	struct Contact con;//dataָ�룬size��capacity
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
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
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			free(con.data);
			con.data = NULL;
			printf("�˳�����\n");break;
		default:
			printf("ѡ���������ѡ��\n");break;
		}

	} while (input);
	return 0;
}
