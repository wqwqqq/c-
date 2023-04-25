#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//	//strncmp字符串比较
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqwer";
//
//	int ret=strcmp(p1,p2);
//	printf("%d\n",ret);
//	return 0;
//}
//#include <assert.h>
//char* my_strstr(const char* p1,const char* p2)//接收目的的地址，和源头地址
//{
//	char* s1 = p1;							//地址赋值给S1
//	char* s2 = p2;							//地址赋值给S2
//	char* cur = p1;							//地址赋值给cur
//	if (*p2 == 0)							//如果P2是空字符
//	{					
//		return (char*)p1;					//直接就返回P1
//	}
//	while (*cur)							//当cur解引用不等于0就执行，就是P1中没有找到\0
//	{
//		s1 = cur;							//S1等于cur
//		s2 = p2;							//S2等于P2
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))	//	当P1解引用不等于0，P2解引用不等于0，P1P2解引用相等
//		{
//			s1++;												//地址++
//			s2++;												//地址++
//		}
//		if (*s2 == '\0')
//		{
//			return cur;											//找到了就返回地址
//		}
//		cur++;													//地址++
//	}
//	return NULL;												//找不到返回空指针
//}
//
//int main()
//{
//	const char* p1 = "abbbbbcdefab";
//	const char* p2 = "bbc";
//	char* ret = my_strstr(p1,p2);
//
//	if (ret == NULL)
//	{
//		printf("字符串不存在\0");
//	}
//	else
//	{
//		printf("%s\n",ret);
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "123.234.876*fjg";
//	char* p = ".*";
//	char buff[1024] = { 0 };
//	strcpy(buff,arr);//零时拷贝一份将数组拷贝到buff
//	char* ret = NULL;
//	for (ret = strtok(arr, p);ret != NULL;ret = strtok(NULL, p))		//strtok是将数组直接改变
//	{
//		printf("%s\n",ret);
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "I AM WANGQUANWU";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);//将大写字符改为小写字符
//		}
//		i++;
//	}
//	printf("%s\n",arr);
//	return 0;
//}

void* my_memcpy(void* dest,const void* src,size_t num)
{
	void* a = dest;
	while (num--)
	{
		*(char* )dest = *(char* )src;
		++(char*)dest;
		++(char*)src;
	}
	return a;
}

int main()
{
	int i = 0;
	int arr1[] = {1,2,3,4,5};
	int arr2[5] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	
	for (i = 0;i < 5;i++)
	{
		printf("%d ",arr2[i]);
	}
	return 0;
}