#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void* ���Խ�����������ָ�������

////int cmp(const void* e1,const void *e2)
////{
////	if (*(int*)e1 > *(int*)e2)
////	{
////		return 1;
////	}
////	return 0;
////}
////
////void bubble_sort(int* p, int sz)
////{
////	int flag = 1;
////	int i = 0;
////	for (i = 0;i < sz-1;i++)
////	{
////		int j = 0;
////		flag = 1;
////		for (j = 0;j <sz-i-1;j++)
////		{
////			int tmp=0;
////			if (p[j] > p[j + 1])
////			{
////				tmp=p[j] ;
////				p[j] = p[j + 1];
////				p[j + 1] = tmp;
////				flag = 0;
////			}
////
////		}
////		if (flag == 1)
////		{
////			break;
////		}
////	}
////
////
////}
////
////struct stu
////{
////	char name[20];
////	int age;
////};
////
////int cmp1(const void* e1, const void* e2)
////{
////
////	return (((struct stu*)e1)->age) - (((struct stu*)e2)->age);
////}
////
////int cmp2(const void* e1, const void* e2)
////{
////	return strcmp(((struct stu*)e1)->name , ((struct stu*)e2)->name);
////}
////
////
////
////int main()
////{
////	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	struct stu s[3] = { {"��ȫ��",20} ,{"����",18},{"��ȫ��",19} };
////	//bubble_sort(arr,sz);
////	qsort(arr, sz, sizeof(arr[0]), cmp);
////	qsort(&s, 3, sizeof(s[0]), cmp2);
////	printf("%s %d\n",s[0].name,s[0].age);
////	printf("%s %d\n", s[1].name, s[1].age);
////	printf("%s %d\n", s[2].name, s[2].age);
////	int i = 0;
////	for (i = 0;i < sz;i++)
////	{
////		printf("%d ",arr[i]);
////	}
////
////
////	return 0;
////}

//qsort,��������
//��һ���������������������Ԫ�ص�ַ
//�ڶ�������������������Ԫ�صĸ���
//�����������������������ÿһ��Ԫ�صĴ�С-��λʮ�ֽ�
//���ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�ص����õıȽϷ�ʽ�ĺ���

/********************ʵ��qsort����**************************************/

//void Swp(char* a, char* b, int width)
//{
//	int i = 0;
//	for (i = 0;i < width;i++)
//	{
//		char tmp = 0;
//		tmp=*a;
//		*a = *b;
//		*b = tmp;
//		a++;
//		b++;
//	}
//}
//
//int cmp(const void* a, const void* b)
//{
//	return *((int*)a) - *((int*)b);
//}
//
//void bublle_sort(void* base, int sz, int width, int(*cmp)(void* a, void* b))
//{
//	int i = 0;
//	int c = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		int j = 0;
//		for (j = 0;j < sz - i - 1;j++)
//		{
//			//(char*)base = (char*)base + width * j;
//			if (cmp((char*)base+j*width, ((char*)base + (j+1)*width)) > 0)
//			{
//				/*����*/
//				for (c = 0;c < width;c++)
//				{
//					char tmp = 0;
//					tmp = *((char*)base + j * width +c);
//					*((char*)base + j * width +c) = *((char*)base + (j + 1) * width +c);
//					*((char*)base + (j + 1) * width +c) = tmp;
//				}
//				/*����*/
//
//				/*������װһ����������*/
//				//Swp((char*)base + j * width, (char*)base + (j + 1) * width,width);
//			
//
//			}
//		}
//	}
//}
//
//void main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bublle_sort(arr,sz,4,cmp);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}

/**********************************************************************/

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n",sizeof(a));//16
//	printf("%d\n",sizeof(a+0));//4
//	printf("%d\n",sizeof(*a));//4
//	printf("%d\n",sizeof(a+1));//4
//	printf("%d\n",sizeof(a[1]));//4
//	printf("%d\n",sizeof(&a));//4
//	printf("%d\n",sizeof(*&a));//16
//	printf("%d\n",sizeof(&a+1));//4
//	printf("%d\n",sizeof(&a[0]));//4
//	printf("%d\n",sizeof(&a[0]+1));//4
//	return 0;
//}

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n",sizeof(arr));//6
	printf("%d\n",sizeof(arr+0));//4
	printf("%d\n",sizeof(*arr));//1
	printf("%d\n",sizeof(arr[1]));//1
	printf("%d\n",sizeof(&arr));//4
	printf("%d\n",sizeof(&arr+1));//4
	printf("%d\n",sizeof(&arr[0]+1));//4
	return 0;
}