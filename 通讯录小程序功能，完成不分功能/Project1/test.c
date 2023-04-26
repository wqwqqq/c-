#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"

void menu()					//��ʾ�˵�����
{
	printf("**************************************\n");		//��ʾ�˵�����
	printf("*********1.add          2.del   ******\n");		
	printf("*********3.search       4.modify *****\n");
	printf("*********5.show          6.sort  *****\n");
	printf("*********0.exit      *****************\n");
	printf("**************************************\n");

}

int main()
{
	struct Contact con;			//���ýṹ�����con
	int input = 0;				//ѡ�����빦��
	InitContact(&con);			//��ʼ���ṹ�����ݣ����ṹ���ַ����ȥ

	do
	{
		menu();					//��ʾ�˵�
		printf("��ѡ��:>");		//ѡ����ع���
		scanf("%d",&input);
		switch (input)			//ѡ���Ӧ����
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;

		}
	} while (input);
	return 0;
}
