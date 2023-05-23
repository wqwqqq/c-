#define _CRT_SECURE_NO_WARNINGS 1
//
//1.字符指针
//2.数组指针
//3.指针数组
//4.数组传参和指针传参
//5.函数指针
//6.函数指针数组
//7.指向函数指针数组的指针
//8.回调函数

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
//	char* p = "abcdef";//常量字符串，不能被改变，把a的地址赋给p
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

	//指针数组是数组
	//int main()
	//{
	//	int arr[10] = { 0 };
	//	char ch[5] = { 0 };
	//	int* parr[4];//存放整形指针的数组
	//	char* pch[5];//存放字符指针的数组
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
//	int* a = NULL;//指向整形的指针
//	char* b = NULL;//指向字符的指针
//	int arr[10];
//	int(*p)[10] = &arr;//指向数组的指针
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