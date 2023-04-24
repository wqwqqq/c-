#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <string.h>
//int FindNum(int p[3][3],int k, int row, int col)
//{
//	int x = 0;//二位数组的行
//	int y = col - 1;//二位数组的列
//	while (x <= row - 1 && y >= 0)//循环的次数
//	{
//		if (p[x][y] > k)//表示二位数组右上角的数字，如果大于K的话这一列就没有
//		{
//			y--;//数组减少一列
//		}
//		else if (p[x][y] < k)//表示二位数组的右上角数字，如果小于K的话，这一行就没有
//		{
//			x++;	//增加一行
//		}
//		else		//否则就相等
//		{
//			return 1;//返回1；
//		}
//		
//	}
//	return 0;		//	找不到就返回0
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 8;
//	int ret = FindNum(arr,k,3,3);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

//int main()
//{
//	int len = strlen("abcdef");		//求字符串长度\0结束标志
//	char arr[] = { 'a','b','c' };	//没有\0求的长度是随机数
//	int a=strlen(arr);
//	printf("%d ",a);
//	printf("%d\n",len);
//	return 0;
//}

//int my_strlen(const char* str)		//接收字符串地址
//{
//	int count = 0;					//计数变量
//	while (*str!='\0')				//解引用不等于0
//	{
//		count++;					//计数就++
//		str++;						//地址++
//	}
//	return count;					//返回计数的次数
//}
//int main()
//{
//	int len = my_strlen("abcdefg");
//	printf("%d",len);
//	if (strlen("abc") - strlen("abcdefg") > 0)			//库函中返回值是无符号类型的，所以一定大于0需要注意
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//
//}
#include <assert.h>

//char*  my_strcyp(char* dest,const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* a = dest;				//接收后面需要返回目的地的首地址
//	while (*src != 0)			
//	{
//		*dest = *src;			//将目的地的首元素地址换成要COPY的首元素地址
//		dest++;
//		src++;
//
//	}
//	*dest = 0;					//上面等于\0就不再进入循环，所以还要等于0
//	return a;
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "bit";
//
//	my_strcyp(arr1, arr2);
//	printf("%s\n",arr1);
//
//	return 0;
//}

//char* my_strcat(char* dest, const char* src)			//字符串后面追加字符从\0开始
//{
//	assert(dest&&src);										
//	char* a = dest;										
//	while (*src)
//	{
//		if (*dest)											//找到目的地位置的\0
//		{
//			dest++;
//		}
//		else
//		{
//			while (*src)								//循环到\0
//			{
//				*dest = *src;							//找到\0后就执行这个，将\0位置的数，替换成追加的第一个元素
//				dest++;
//				src++;
//			}
//			*dest = 0;
//
//		}
//
//	}
//	return a;
//}
//
//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	my_strcat(arr1,arr2);
//	printf("%s\n",arr1);
//	return 0;
//}

//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "sqwer";
//
//	int ret = strcmp(p1, p2);
//	printf("%d\n", ret);
//	return 0;
//}

//int my_strcmp(const char* str1, const char* str2)//传递连个字符串地址
//{
//	while (*str1 == *str2)//字符串字符相等就++，比较下一个字符串
//	{						
//		if (*str1 == 0)
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)//大于就返回1
//	{
//		return 1;
//	}
//	else//否则就返回-1
//	{
//		return -1;
//	}
//
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "abbew";
//	int ret = my_strcmp(p1,p2);
//	printf("ret=%d\n",ret);
//	return 0;
//}
//char* my_strncpy(char* a, char* b, int c)
//{
//	char* d = a;
//	int e = c-1 ;
//	while (e--)
//	{
//		*a = *b;
//		a++;
//		b++;
//		if (*b == 0)
//		{
//			while (e)
//			{
//				e--;
//				a++;
//				*a = 0;
//			}
//		}
//	}
//
//}
//int main()
//{
//	char arr1[10] = "abc";
//	char arr2[] = "hello";
//	my_strncpy(arr1,arr2,10);
//	printf("%s\n",arr1);
//	return 0;
//}
////