#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////ѡ�����
//int main()
//{
//	int input = 0;
//	printf("����BIT\n");
//	printf("��Ҫ�ú�ѧϰ�𣿣�1/0��>:");
//	scanf("%d",&input);
//	if (input == 1)
//	{
//		printf("��offer\n");
//	}
//	else
//	{
//		printf("������\n");
//	}
//	return 0;
//}

//ѭ�����
//while do while for 
//int main()
//{
//	int line = 0;
//	printf("����bit\n");
//	while (line < 20000)
//	{
//	printf("��һ�д���:%d\n",line);
//	line++;
//
//	}
//	if (line >= 20000)
//	{
//	printf("�õ�һ����offer\n");
//	}
//
//	return 0;
//}

//����

//int ADD(int x, int y)//int�Ǻ����ķ������ͣ�ADD�Ǻ�������x y�Ǻ����Ĳ���
//{
//	int z = x + y;
//	return z;
//
//}
//
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int sum = 0;
//	sum = num1 + num2;
//	printf("sum=%d",sum);
//	return 0;
//}

//�����ʹ��
//һ����ͬ�������ݵļ���
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//	int i = 0;
//	//int arr[10];//���10��int���ݵ�����
//	char ch[20];
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0;i < 10;i++)
//	{
//	printf("%d\n", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 5 / 2;//ȡ
//	printf("%d",a);
//	return 0;
//}
//int main()
//{
//	//<<����
//	//<<���ƶ�
//	int a = 1;
//	a=a << 2;
//	printf("%d",a);
//	return 0;
//}

//int main()
//{
//	//��2���Ʋ�����
//	//&��λ��
//	//|��λ��
//	int a =3;
//	int b = 5;
//	int c = a ^ b;
//	printf("c=%d\n",c);
//
//}

//��ֵ��������
//int main()
//{
//	int a = 10;
//	a = 20;
//	a = a + 20;
//	a += 20;
//	a -= 10;
//	//
//
//}

//��Ŀ��������
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a + b;//˫Ŀ��������
//	//
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	printf("%d\n",sizeof(a));
//	return 0;
//}

int main()
{
	int arr[10];
	printf("%d\n",sizeof(arr)/sizeof(arr[0]));
	return 0;
}