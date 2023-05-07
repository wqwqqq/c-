#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	scanf("%d%d",&num1,&num2);
//	sum = num1 + num2;
//	printf("%d\n",sum);
//	return 0;
//}

//int main()
//{
//	//3
//	//4
//	//5这些都是字面常量
//
//	//const长属性，修饰变量，修饰的常变量不能改变
//	//int num = 4;
//	//printf("%d\n",num);
//	//num = 5;
//	//printf("%d\n",num);
//
//	//int n = 10;
//	//int arr[n] = {0};//报错，只能是一个常量，加const修饰n还是报错
//	return 0;
//}

////#define 标识符定义的常量
//#define MAX 10
//int main()
//{
//	int arr[MAX] = {0};//这里是没有问题的，相当于替换掉
//	printf("MAX=%d ",MAX);
//	return 0;
//}

//enum枚举常量,一一列举的意思
//性别，男女
//星期 1 2 3 4 5 6 7

//typedef enum Sex   //enum Sex 表示枚举类型,使用typedef重定义枚举类型
//{
//	male,//
//	female,
//	secret
//}Sex;
//
//int main()
//{
//	enum Sex s = male;//定义sex枚举类型变量S，取值只能是枚举中的值
//	Sex a = female;
//	printf("%d%d",s,a);
//	return 0;
//}

//字符串，“hello world!”,这种由双引号引起来的称为字符串，默认结束标志位\0，是字符串结束标志不算字符串内容
//int main()
//{
//	//"ABCDEF";
//	//"HELLO WORLD";//都是字符串，
//
//	char arr[] = "abcd";//字符串默认后面有\0
//	char arr2[] = {'a','b','c'};//这个里面是没有结束标志的\0，
//	printf("%s\n",arr);
//	printf("%s\n",arr2);
//	return 0;
//}
#include <string.h>
int main()
{
	char arr1[] = "abc";
	char arr2[] = { 'q','b' };
	printf("%d\n",strlen(arr1));
	printf("%d\n",strlen(arr2));
	return 0;
}