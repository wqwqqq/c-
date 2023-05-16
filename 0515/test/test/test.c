#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d",&a,&b);
//	printf("a+b=%d\n",a+b);
//	return 0;
//}


//字符串的结束标志是什么\0或者数字0，注意不是'0'，'0'对应的数值是48
//'0'是转义字符，
//'a''b''c'
//EOF是文件结束标志
//#include <string.h>
//int main()
//{
//	char arr[] = {'a','b','c',0};
//	printf("%d",strlen(arr));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	printf("%d",strlen("c:\test\121"));
//	return 0;
//}

//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	if (num1 > num2)
//	{
//		printf("较大值是num1 %d",num1);
//	}
//	else
//	{
//		printf("较大值是num2 %d",num2);
//	}
//	return 0;
//}

//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//
//}
//
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int max;
//	max = Max(num1,num2);
//	printf("max=%d\n",max);
//	return 0;
//}

//数组的下表是从0开始的
//单目操作符
int main()
{
	int a = 10;
	int arr[] = { 1,2,3,4,5,6 };
	printf("%d\n",sizeof(arr));//计算数组大小，单位是字节
	printf("%d\n",sizeof a);
	printf("%d\n",sizeof(arr)/sizeof(arr[0]));
	return 0;
}