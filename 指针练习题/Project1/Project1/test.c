#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int is_left_move(char* str1,char* str2)
//{
//	//strcat字符串追加
//	int len = strlen(str1);
//	int len2 = strlen(str2);
//	if (len != len2)
//		return 0;
//	strncat(str1, str1, len);
//	char* ret=strstr(str1, str2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	char arr[30] = "abcdef";
//	char arr2[] = "cdefa";
//	int ret = is_left_move(arr,arr2);
//	if (ret == 1)
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}

//int main()
//{
//	char arr1[30] = "abc";
//	char arr2[] = "def";
//	strcat(arr1, arr2);
//	printf("%s",arr1);
//	return 0;
//}

// 1 2 3
// 4 5 6
// 7 8 9
//直接比较左上角的数字与要找到的数对比

//int FindNum(int arr[3][3], int k, int h, int l)
//{
//	int x = 0;
//	while (l >= 0 && x<=l-1)
//	{
//		if (arr[x][l - 1] < k)
//		{
//			x++;
//		}
//		else if (arr[h - 1][l - 1] > k)
//		{
//			l--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3}, {4,5,6},{7,8,9} };
//	int k = 71;
//	int ret = FindNum(arr,k,3,3);
//	if (ret)
//	{
//		printf("找到了");
//	}
//	else
//	{
//		printf("找不到");
//	}
//	return 0;
//}

//实现strlen函数

//int my_strlen(const char* arr)
//{
//	int count = 0;
//	while (*arr)
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//
//int my_strlen2(const char* arr)
//{
//	if (*arr)
//	{
//		return 1 + my_strlen2(arr + 1);
//	}
//	return 0;
//}
//
//
//int main()
//{
//	char arr[] = "abcdef";
//	int m=my_strlen2(arr);
//	printf("%d",m);
//	return 0;
//}
/******************************************/

//char* my_strcpy(char* arr1,const char* arr2)
//{
//	char* p = arr1;
//	while (*arr2)
//	{
//		*arr1 = *arr2;
//		arr1++;
//		arr2++;
//	}
//	*arr1 = 0;
//	return p;
//}
//
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//
//	my_strcpy(arr1,arr2);
//	printf("%s",arr1);
//	
//	return 0;
//}
/**********************************************/

char* my_strcat(char* arr1, char* arr2)
{
	char* p = arr1;
	while (*arr1)
	{
		arr1++;
	}
	while (*arr2)
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = 0;
	return p;
}

int main()
{
	char arr[20] = "abcdef";
	char arr2[] = "quan";
	
	my_strcat(arr,arr2);
	printf("%s",arr);
	return 0;
}