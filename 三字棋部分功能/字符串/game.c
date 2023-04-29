#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}

	}

}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int l = 0;
//	for (i = 0;i < row;i++)
//	{
//
//		for (l = 0;l < col;l++)
//		{
//			printf(" %c | ",board[l][i])
//
//		}
//		printf(" %c | %c | %c\n", board[i][0], board[i][2], board[i][2]);
//
//		if (i < row-1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//
//}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int l = 0;
//	int b = col;
//	for (i = 0;i < ROW;i++)
//	{
//
//		for (l = 0;l < col;l++)
//		{
//			printf("---");
//			if(l<b-1)
//			printf("%c|", board[l][i]);
//			
//
//		}
//		printf("\n");
//
//	}
//
//}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)

			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}

}

void PlayerMove(char board[ROW][COL], int a, int b)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>");
	scanf("%d%d",&x,&y);
	if (x >= 1 && x <= a&&y>=1&&y<=b)
	{
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
		
		}
		else
		{
			printf("请重新输入坐标\n");
		}
	}
	else
	{
		printf("输入的坐标错误，请重新输入\n");
	}

}