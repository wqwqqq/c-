#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//	//strncmp�ַ����Ƚ�
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqwer";
//
//	int ret=strcmp(p1,p2);
//	printf("%d\n",ret);
//	return 0;
//}
//#include <assert.h>
//char* my_strstr(const char* p1,const char* p2)//����Ŀ�ĵĵ�ַ����Դͷ��ַ
//{
//	char* s1 = p1;							//��ַ��ֵ��S1
//	char* s2 = p2;							//��ַ��ֵ��S2
//	char* cur = p1;							//��ַ��ֵ��cur
//	if (*p2 == 0)							//���P2�ǿ��ַ�
//	{					
//		return (char*)p1;					//ֱ�Ӿͷ���P1
//	}
//	while (*cur)							//��cur�����ò�����0��ִ�У�����P1��û���ҵ�\0
//	{
//		s1 = cur;							//S1����cur
//		s2 = p2;							//S2����P2
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))	//	��P1�����ò�����0��P2�����ò�����0��P1P2���������
//		{
//			s1++;												//��ַ++
//			s2++;												//��ַ++
//		}
//		if (*s2 == '\0')
//		{
//			return cur;											//�ҵ��˾ͷ��ص�ַ
//		}
//		cur++;													//��ַ++
//	}
//	return NULL;												//�Ҳ������ؿ�ָ��
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
//		printf("�ַ���������\0");
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
//	strcpy(buff,arr);//��ʱ����һ�ݽ����鿽����buff
//	char* ret = NULL;
//	for (ret = strtok(arr, p);ret != NULL;ret = strtok(NULL, p))		//strtok�ǽ�����ֱ�Ӹı�
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
//			arr[i] = tolower(arr[i]);//����д�ַ���ΪСд�ַ�
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