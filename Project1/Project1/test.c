#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"

void menu()
{
	printf("***************************************************\n");
	printf("********    1.����              2.ɾ��     ********\n");
	printf("********    3.����              4.�޸�     ********\n");
	printf("********    5.�鿴              6.����     ********\n");
	printf("********    0.�˳�                         ********\n");
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
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:break;
		case 3:break;
		case 4:break;
		case 5:
			ShowContact(&con);
				break;
		case 6:break;
		case 0:printf("�˳�����\n");break;
		default:printf("ѡ���������ѡ��\n");break;
		}

	} while (input);
	return 0;
}
