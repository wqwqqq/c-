#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a = 10;
//	float f = 10.0;
//	short a = 2;
//
//	return 0;
//}

//void pd(int* p)
//{
//	char* a = (char*)p;
//	if (*a == 20)
//	{
//		printf("电脑为小端存储\n");
//	}
//	else
//	{
//		printf("电脑为大端\n");
//
//	}
//}
//
//
//int main()
//{
//	int a = 20;
//	int* p = &a;
//	pd(p);
//
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//
//	printf("a=%d b=%d c=%d ",a,b,c);
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	printf("%u\n",a);
//	return 0;
//}

//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n",i+j);
//	return 0;
//}

int main()
{
	char a[1000] = {0};
	int i = 0;
	for (i = 0;i < 1000;i++)
	{
		a[i] = -1 - i;
	}

	printf("%d\n",strlen(a));
	return 0;
}