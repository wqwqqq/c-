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
//	//5��Щ�������泣��
//
//	//const�����ԣ����α��������εĳ��������ܸı�
//	//int num = 4;
//	//printf("%d\n",num);
//	//num = 5;
//	//printf("%d\n",num);
//
//	//int n = 10;
//	//int arr[n] = {0};//����ֻ����һ����������const����n���Ǳ���
//	return 0;
//}

////#define ��ʶ������ĳ���
//#define MAX 10
//int main()
//{
//	int arr[MAX] = {0};//������û������ģ��൱���滻��
//	printf("MAX=%d ",MAX);
//	return 0;
//}

//enumö�ٳ���,һһ�оٵ���˼
//�Ա���Ů
//���� 1 2 3 4 5 6 7

//typedef enum Sex   //enum Sex ��ʾö������,ʹ��typedef�ض���ö������
//{
//	male,//
//	female,
//	secret
//}Sex;
//
//int main()
//{
//	enum Sex s = male;//����sexö�����ͱ���S��ȡֵֻ����ö���е�ֵ
//	Sex a = female;
//	printf("%d%d",s,a);
//	return 0;
//}

//�ַ�������hello world!��,������˫�����������ĳ�Ϊ�ַ�����Ĭ�Ͻ�����־λ\0�����ַ���������־�����ַ�������
//int main()
//{
//	//"ABCDEF";
//	//"HELLO WORLD";//�����ַ�����
//
//	char arr[] = "abcd";//�ַ���Ĭ�Ϻ�����\0
//	char arr2[] = {'a','b','c'};//���������û�н�����־��\0��
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