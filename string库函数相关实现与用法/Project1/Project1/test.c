#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <string.h>
//int FindNum(int p[3][3],int k, int row, int col)
//{
//	int x = 0;//��λ�������
//	int y = col - 1;//��λ�������
//	while (x <= row - 1 && y >= 0)//ѭ���Ĵ���
//	{
//		if (p[x][y] > k)//��ʾ��λ�������Ͻǵ����֣��������K�Ļ���һ�о�û��
//		{
//			y--;//�������һ��
//		}
//		else if (p[x][y] < k)//��ʾ��λ��������Ͻ����֣����С��K�Ļ�����һ�о�û��
//		{
//			x++;	//����һ��
//		}
//		else		//��������
//		{
//			return 1;//����1��
//		}
//		
//	}
//	return 0;		//	�Ҳ����ͷ���0
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 8;
//	int ret = FindNum(arr,k,3,3);
//	if (ret == 1)
//	{
//		printf("�ҵ���\n");
//	}
//	else
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}

//int main()
//{
//	int len = strlen("abcdef");		//���ַ�������\0������־
//	char arr[] = { 'a','b','c' };	//û��\0��ĳ����������
//	int a=strlen(arr);
//	printf("%d ",a);
//	printf("%d\n",len);
//	return 0;
//}

//int my_strlen(const char* str)		//�����ַ�����ַ
//{
//	int count = 0;					//��������
//	while (*str!='\0')				//�����ò�����0
//	{
//		count++;					//������++
//		str++;						//��ַ++
//	}
//	return count;					//���ؼ����Ĵ���
//}
//int main()
//{
//	int len = my_strlen("abcdefg");
//	printf("%d",len);
//	if (strlen("abc") - strlen("abcdefg") > 0)			//�⺯�з���ֵ���޷������͵ģ�����һ������0��Ҫע��
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
//	char* a = dest;				//���պ�����Ҫ����Ŀ�ĵص��׵�ַ
//	while (*src != 0)			
//	{
//		*dest = *src;			//��Ŀ�ĵص���Ԫ�ص�ַ����ҪCOPY����Ԫ�ص�ַ
//		dest++;
//		src++;
//
//	}
//	*dest = 0;					//�������\0�Ͳ��ٽ���ѭ�������Ի�Ҫ����0
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

//char* my_strcat(char* dest, const char* src)			//�ַ�������׷���ַ���\0��ʼ
//{
//	assert(dest&&src);										
//	char* a = dest;										
//	while (*src)
//	{
//		if (*dest)											//�ҵ�Ŀ�ĵ�λ�õ�\0
//		{
//			dest++;
//		}
//		else
//		{
//			while (*src)								//ѭ����\0
//			{
//				*dest = *src;							//�ҵ�\0���ִ���������\0λ�õ������滻��׷�ӵĵ�һ��Ԫ��
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

//int my_strcmp(const char* str1, const char* str2)//���������ַ�����ַ
//{
//	while (*str1 == *str2)//�ַ����ַ���Ⱦ�++���Ƚ���һ���ַ���
//	{						
//		if (*str1 == 0)
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)//���ھͷ���1
//	{
//		return 1;
//	}
//	else//����ͷ���-1
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