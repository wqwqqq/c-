#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"


void menu()
{
	printf("****************************\n");
	printf("*****1.play     0.exit   ***\n");
	printf("****************************\n");
}

void game()
{
	
	//布置好雷的信息
	char mine[ROWS][COLS] = {0};
	//排查好雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化函数
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//DispalyBoard(mine,ROW,COL);
	printf("\n");
	DispalyBoard(show, ROW, COL);
	SetMine(mine,ROW,COL);
	//DispalyBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择:>\n");
			break;
		}
	} while (input);

}

int main()
{
	test();
	return 0;
}