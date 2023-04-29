#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"

void meun()
{
	printf("**************************\n");
	printf("****1. play   2. exit ****\n");
	printf("**************************\n");
}

void game()
{
	//首先需要创建一个数组，放棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化数组
	Initboard(board, ROW, COL);
	//显示棋盘函数
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		
		PlayerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
	}
}

void test()
{
	int input = 0;
	do {
		meun();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}

	} while (input);

}




int main()
{
	test();
	return 0;
 }