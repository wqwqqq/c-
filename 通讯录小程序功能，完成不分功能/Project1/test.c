#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"

void menu()					//显示菜单功能
{
	printf("**************************************\n");		//显示菜单内容
	printf("*********1.add          2.del   ******\n");		
	printf("*********3.search       4.modify *****\n");
	printf("*********5.show          6.sort  *****\n");
	printf("*********0.exit      *****************\n");
	printf("**************************************\n");

}

int main()
{
	struct Contact con;			//设置结构体变量con
	int input = 0;				//选择输入功能
	InitContact(&con);			//初始化结构体内容，将结构体地址传过去

	do
	{
		menu();					//显示菜单
		printf("请选择:>");		//选择相关功能
		scanf("%d",&input);
		switch (input)			//选择对应功能
		{
		case ADD:
			AddContact(&con);
				break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;

		}
	} while (input);
	return 0;
}
