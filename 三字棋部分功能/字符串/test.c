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
	//������Ҫ����һ�����飬��������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ʾ���̺���
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
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}

	} while (input);

}




int main()
{
	test();
	return 0;
 }