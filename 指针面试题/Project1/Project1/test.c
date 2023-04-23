#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };  //字符指针数组
//	char** cp[] = {c+3,c+2,c+1,c};                  //字符指针数组的数组
//	char*** cpp = cp;								//地址
//	printf("%s\n",**++cpp);							//先++在使用，首元素地址++
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n",*cpp[-2]+3);
//	printf("%s\n",*cpp[-1][-1]+1);
//
//	return 0;
//}

//int main()
//{
//	unsigned long p[] = { 6,7,8,9,10 };  //整形素组
//	unsigned long* pa = p;				//数组指针
//	*(pa + 3) += 3;						//解引用的值加等于3，就是12
//	printf("%d,%d\n",*pa,*(pa+3));		//数组名就是元素首地址
//		return 0;
//}

//#include <string.h>
//
//void reverse(char* p, int sz)   //传过来的是数组名是数组首元数地址，所以用数组指针接受
//{
//	int len = strlen(p);			//求数组的长度
//	char* left = p;					//数组的坐下标地址
//	char* right = p + len - 1;		//数组的右下表地址
//	while (left < right)				//下面数组元素实现交换位置
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()		
//{
//	char arr[256] = { 0 };			//定义一个字符数组
//	scanf("%s",arr);				//获取数组内容
//	int sz = sizeof(arr) / sizeof(arr[0]);	//求数组的元素个数
//	reverse(arr,sz);
//	printf("%s\n",arr);
//	return 0;
//}

int main()
{
	int a = 0;
	int n = 0;
	scanf("%d%d",&a,&n);//获取两个值
	int i = 0;
	int sum = 0;
	int ret = 0;
	for (i = 0;i < n;i++)//循环求出a+aa+aaa,n个
	{
		ret = ret * 10 + a;
		sum += ret;

	}
	printf("%d\n",sum);
	return 0;
}
#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0;i < 100000;i++)   //获得i从0到100000的数值
//	{
//		int n = 1;
//		int tem = i;
//		int sum = 0;
//		while (tem/= 10)			//求出i的位数
//		{
//			n++;
//		}
//		tem = i;					//把i的值赋给tem
//		while (tem)					//求结果
//		{
//			sum += (int)pow(tem % 10, n);
//			tem /= 10;
//		}
//		if (i == sum)//判断是否相等
//		{
//			printf("%d ",i);相等就输出i
//		}
//	}
//	return 0;
//}