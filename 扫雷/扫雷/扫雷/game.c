#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int get_mine_count()
{

}

void InitBoard(char mein[ROWS][COLS], int rows, int clos,char set)
{
	int i = 0;
	int j = 0;
	for (i - 0;i < rows;i++)
	{
		for (j = 0;j < clos;j++)
		{
			mein[i][j] = set;
		}
	}
}

void DispalyBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i <= row;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = LEI_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入坐标:>");
	scanf("%d%d",&x,&y);
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DispalyBoard(mine, row, col);
				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}

}