#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////选择语句
//int main()
//{
//	int input = 0;
//	printf("加入BIT\n");
//	printf("你要好好学习吗？（1/0）>:");
//	scanf("%d",&input);
//	if (input == 1)
//	{
//		printf("好offer\n");
//	}
//	else
//	{
//		printf("卖红薯\n");
//	}
//	return 0;
//}

//循环语句
//while do while for 
//int main()
//{
//	int line = 0;
//	printf("加入bit\n");
//	while (line < 20000)
//	{
//	printf("敲一行代码:%d\n",line);
//	line++;
//
//	}
//	if (line >= 20000)
//	{
//	printf("拿到一个好offer\n");
//	}
//
//	return 0;
//}

//函数

//int ADD(int x, int y)//int是函数的返回类型，ADD是函数名，x y是函数的参数
//{
//	int z = x + y;
//	return z;
//
//}
//
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int sum = 0;
//	sum = num1 + num2;
//	printf("sum=%d",sum);
//	return 0;
//}

//数组的使用
//一组相同类型数据的集合
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//	int i = 0;
//	//int arr[10];//存放10个int数据的数组
//	char ch[20];
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0;i < 10;i++)
//	{
//	printf("%d\n", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 5 / 2;//取
//	printf("%d",a);
//	return 0;
//}
//int main()
//{
//	//<<左移
//	//<<右移动
//	int a = 1;
//	a=a << 2;
//	printf("%d",a);
//	return 0;
//}

//int main()
//{
//	//（2进制操作）
//	//&按位与
//	//|按位或
//	int a =3;
//	int b = 5;
//	int c = a ^ b;
//	printf("c=%d\n",c);
//
//}

//赋值操作符，
//int main()
//{
//	int a = 10;
//	a = 20;
//	a = a + 20;
//	a += 20;
//	a -= 10;
//	//
//
//}

//单目操作符号
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a + b;//双目操作符号
//	//
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	printf("%d\n",sizeof(a));
//	return 0;
//}

int main()
{
	int arr[10];
	printf("%d\n",sizeof(arr)/sizeof(arr[0]));
	return 0;
}