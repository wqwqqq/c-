#define _CRT_SECURE_NO_WARNINGS 1

//动态内存函数的介绍
//malloc  和   free函数

/*void * mallco(size_t size)*/ //返回类型是空指针，指向开辟空间位置的指针，参数是开辟空间的大小单位是字节，开辟空间失败返回的是空指针

//void free(void * ptr)			//无返回，参数是指向空间的指针，释放动态开辟的内存，ptr需要指向的是动态开辟的空间，栈上和静态区的空间都不能用free，释放后指针需要置为空指针

#include <stdio.h>

//int main()
//{
//	int num = 0;
//	printf("请输入num的值:>");
//	scanf("%d",&num);
//	//int arr[num] = { 0 };
//	int* ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//
//	/*if (ptr != NULL)*/
//	/*{*/
//		int i = 0;
//		for (i = 0;i < num;i++)
//		{
//			*(ptr + i)=i;
//			printf("%d ",*(ptr+1));
//		}
//
//		free(ptr);
//		ptr = NULL;
//
//	//}
//
//	return 0;
//}

//  calloc 用来分配动态内存
// void* calloc(size_t num,size_t size)  //返回值是开辟空间的地址指针，参数是开辟的个数，大小是size个字节，将开辟空间的值初始化为0；

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int* p = (int*)calloc(10,sizeof(int));
//	if (p != NULL)
//	{
//		int i = 0;
//		for (i = 0;i < 10;i++)
//		{
//			p[i] = i;
//			printf("%d ",p[i]);
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc 动态内存追加
//void * realloc (void* ptr,size_t size);//返回类型是指向开辟空间位置的指针，开辟失败返回空指针，参数是指向动态空间的地址，调整之后的新大小

//开辟空间有两种情况，第一种原空间后面有足够大的空间开辟新空间，
//第二种情况原空间后面没有足够大的空间开辟新空间，重新在其他位置开辟一块调整后的空间，将原空间的内容拷贝到新空间中，并释放掉原空间。


//#include <stdio.h>
//
//int main()
//{
//	int* ptr = (int *)malloc(100);
//	int* p = (int*)realloc(ptr,1000);
//	if (p != NULL)
//	{
//		ptr = p;
//		free(ptr);
//		ptr = NULL;
//	}
//
//
//	return 0;
//}
//

//不能对空指针解应用操作，所以开辟空间的时候注意判断是否开辟空间成功

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("开辟空间失败");
//		return 0;
//	}
//	for (i = 0;i < 12;i++)//动态开辟的空间越界访问会出现问题，避免这样使用
//	{
//		p[i] = i;
//		printf("%d ",p[i]);
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//释放不是动态开辟的内存，程序会直接卡死
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//释放不是指向动态存储的起始位置错误
//	return 0;
//}

//不能重复释放动态存储，忘记释放会赵成内存泄漏

//int main()
//{
//	while (1)
//	{
//		int* p = (int*)malloc(40);
//	}
//	return 0;
//}

//void a(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void test(void)
//{
//	char* str = NULL;
//	a(&str);
//	strcpy(str, "hello world");
//	printf(str);
//
//}
//int main()
//{
//	test();
//	return 0;
//}

//char* GetMemor(void)
//{
//	char p[] = "hello world";
//	return p;
//
//}
//
//void test(void)
//{
//	char* str = NULL;
//	str = GetMemor();//返回的是数组的地址，但是返回后数组会被销毁，存在非法访问
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}

//void GetMeory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void test(void)
//{
//
//	char* str = NULL;
//	GetMeory(&str,100);
//	strcpy(str,"hello 王全武");
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
//
//void test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str,"hello wangquanwu");
//	free(str);//申请的空间已经被释放掉了，不能再接着使用
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//
//	}
//
//}

//柔性数组，结构体中必粗柔性数组前面要有一个成员，柔性数组的结构使用malloc（）函数进行动态分配，并且分配的内存大小应该大于结构体的大

typedef struct s				//定义结构体类型s
{
	int i;
	int a[0];					//柔性数组，用malloc申请空间可以改变大小

}s;								//结构体变量s，这个位置定义的结构体变量是全局变量

int main()
{
	s* p = NULL;
	printf("%d",sizeof(s));//大小为4

	p = (s*)malloc(sizeof(s)+100*sizeof(int));

	return 0;
}

