#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	printf("hello world\n");
//	return 0;
//}

//char �ַ�����
//%d ��ӡ10����
//%s ��ӡ�ַ���
//%c ��ӡ�ַ�
//%f��ӡ������

//int main()
//{
//	char ch = 'A';//�ַ�����
//	int age = 20;
//	printf("%d\n",age);
//	printf("%c\n",ch);
//	return 0;
//}
//
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n",sizeof(int));
//	printf("%d\n",sizeof(long));
//	printf("%d\n",sizeof(long long));
//	printf("%d\n",sizeof(float));
//	printf("%d\n",sizeof(double));
//	return 0;
//}

//int main()
//{
//	short age = 20;
//	double wight = 75.2;
//	printf("%lf\n",wight);
//	return 0;
//}

//���ͼӱ�������һ����ʼֵ���������

//int num2 = 20;//ȫ�ֱ���
//
//int main()
//{
//	int num1 = 10;//�ֲ�����
//	return 0;
//}

//int a = 100;
//
//int main()
//{
//	int a = 10;
//	printf("%d",a);//��ӡ������ֲ����ȣ��ֲ�������ȫ�ֱ���������Ҫ��ͬ
//	return 0;
//}

//int main()
//{
//	int a = 10;//��c�����б���Ҫ�����ڴ������ǰ��
//	int b = 30;
//	scanf("%d%d",&a,&b);//���뺯��
//	printf("%d",a+b);
//	return 0;
//}

//���������������������
//�ֲ��������������������ڵĴ����
//ȫ�ֱ���������������������

//�ֲ����������������ǽ����������������ڿ�ʼ�����������������ڽ���
//ȫ�ֱ����������������������������

int main()
{
	int sum = 0;
	int num1 = 0;
	int num2 = 0;
	scanf("%d%d", &num1, &num2);
	sum = num1 + num2;
	printf("%d",sum);
	return 0;
}