#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	printf("hello world\n");
//	return 0;
//}

//char 字符类型
//%d 打印10进制
//%s 打印字符串
//%c 打印字符
//%f打印浮点型

//int main()
//{
//	char ch = 'A';//字符类型
//	int age = 20;
//	printf("%d\n",age);
//	printf("%c\n",ch);
//	return 0;
//}
//
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n",sizeof(int));
//	printf("%d\n",sizeof(long));
//	printf("%d\n",sizeof(long long));
//	printf("%d\n",sizeof(float));
//	printf("%d\n",sizeof(double));
//	return 0;
//}

//int main()
//{
//	short age = 20;
//	double wight = 75.2;
//	printf("%lf\n",wight);
//	return 0;
//}

//类型加变量名加一个初始值，定义变量

//int num2 = 20;//全局变量
//
//int main()
//{
//	int num1 = 10;//局部变量
//	return 0;
//}

//int a = 100;
//
//int main()
//{
//	int a = 10;
//	printf("%d",a);//打印结果，局部优先，局部变量和全局变量尽量不要相同
//	return 0;
//}

//int main()
//{
//	int a = 10;//在c语言中变量要定义在代码块最前面
//	int b = 30;
//	scanf("%d%d",&a,&b);//输入函数
//	printf("%d",a+b);
//	return 0;
//}

//变量的作用域和生命周期
//局部变量的作用域是他所在的代码块
//全局变量的作用域是整个工程

//局部变量的生命周期是进入作用域申明周期开始，出作用域生命周期结束
//全局变量的周期是整个程序的生命周期

int main()
{
	int sum = 0;
	int num1 = 0;
	int num2 = 0;
	scanf("%d%d", &num1, &num2);
	sum = num1 + num2;
	printf("%d",sum);
	return 0;
}