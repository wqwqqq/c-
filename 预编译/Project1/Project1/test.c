#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//extern int Add(int x, int y);			//外部申明可调用函数
//int main()
//{
//	int a = 10;							//定义整形a	
//	int b = 20;
//	int c = Add(a,b);					//使用函数
//	printf("%d \n",c);
//	return 0;
//}
//
//#define MAX 100					//预编译，没有进行编译成将MAX替换为100，只是替换不参加计算
//
////预编译符号
//
//
////int main()
////{
////	printf("%s\n",__FILE__);
////	printf("%d\n",__LINE__);
////	printf("%s\n",__DATE__);
////	printf("%s\n",__TIME__);
////	//写日志
////	int i = 0;
////	int arr[10];
////	FILE* pf = fopen("textd.txt","w");
////	for (i = 0;i < 10;i++)
////	{
////		arr[i]=i;
////		fprintf(pf, "flie:%s\n line:%d\n time:%s\n date:%s\n", __FILE__, __LINE__, __TIME__, __DATE__);
////	}
////	return 0;
////}
//
////#define 可以定义标识，也可以定义宏
////#include
////#开头都叫预处理指令
//
////#define MAX 100   //后面所有东西都可以是替代的内容
////int main()
////{
////	printf("%d\n",MAX);
////	return 0;
////}
//
////#define reg register  //创建关键字
////
////#define do_forever for(;;)
////
////int main()
////{
////	do_forever;
////	return 0;
////}
//
////#define 允许把参数定义在文本中
//

#define SQUARE(X) X*X

//int main()
//{
//	int a = SQUARE(5+1);
//	printf("%d\n",a);//这个时候答案是11，5+1是直接替换不进行运行，编译的时候计算，编译的时候需要将x括起来整体也要括起来避免错误
//	return 0;
//}
////字符串中的内容不会被替换

//#define PRINT(X) printf("the value of "#X" is %d\n",X)			//将#X替换为字符，宏可以做到，函数做不到
//int main()
//{
//	int A = 20;
//	int B = 30;
//	PRINT(A);
//	PRINT(B);
//	return 0;
//}

//##的使用方法，

//#define CAT(X,Y) X##Y
//int main()
//{
//	int class = 2019;
//	printf("%d\n", class);
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	int b = a + 1;
//	int b = ++a;
//	return 0;
//}

//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int c= MAX(a,b);
//	printf("%d\n",c);
//	return 0;
//}
//
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	printf("a=%d\n",a);
//	printf("b=%d\n",b);
//	printf("max=%d\n",max);
//	return 0;
//}//宏的参数是替换进去，不会进行计算
//
//int main()
//{
//
//	return 0;
//}
//
//int Max(int x, int y)
//{
//
//	return(x > y ? x : y);
//}

//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//
//int main()
//{
//	float c = 3.0f;
//	float b = 4.0f;
//	float a = MAX(b,c);
//
//	printf("%f\n",a);
//	return 0;
//}

#define test(x,y) printf("test\n")

int mian()
{
	int a = 0; 
	int b = 0;
	test(a, c);
	return 0;
}
#define SIZEOF(type) sizeof(type)						//替换类型，函数做不到

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));			//开辟10个整形空间大小

}

#define MALLOC(SIZE,TYPE) (TYPE*)malloc(SIZE,sizeof(TYPE))

//宏是不可以调试的，也不可以递归

//