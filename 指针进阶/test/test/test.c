#define _CRT_SECURE_NO_WARNINGS 1
//
//1.�ַ�ָ��
//2.����ָ��
//3.ָ������
//4.���鴫�κ�ָ�봫��
//5.����ָ��
//6.����ָ������
//7.ָ����ָ�������ָ��
//8.�ص�����

#include <stdio.h>

//void test(int arr[])
//{
//	printf("%d\n",sizeof(arr)/sizeof(arr[0])); 
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	return 0;
//}

//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%s\n",pc);
//	printf("%s\n",arr);
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";//�����ַ��������ܱ��ı䣬��a�ĵ�ַ����p
//	printf("%p\n",p);
//	printf("%p", "abcdef");
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";
//	char* p2 = "abcdef";
	//if (arr1 == arr2)
	//{
	//	printf("hehe\n");
	//}
	//else
	//{
	//	printf("haha\n");
	//}
//	if (p1 == p2)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha");
//	}
//	return 0;
//}

	//ָ������������
	//int main()
	//{
	//	int arr[10] = { 0 };
	//	char ch[5] = { 0 };
	//	int* parr[4];//�������ָ�������
	//	char* pch[5];//����ַ�ָ�������
	//	return 0;
	//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 5;j++)
//		{
//			printf("%d ",parr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int* a = NULL;//ָ�����ε�ָ��
//	char* b = NULL;//ָ���ַ���ָ��
//	int arr[10];
//	int(*p)[10] = &arr;//ָ�������ָ��
//	return 0;
//}

//int main()
//{
//	char* arr[5];
//	char*(*ch)[5]=&arr;
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ",(*p)[i]);
//	}
//	return 0;
//}

void print(int(*p)[5], int a, int b)
{

	int i = 0;
	int j = 0;
	for (i = 0;i < a;i++)
	{
		for (j = 0;j < b;j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print(arr,3,5);
	return 0;
}