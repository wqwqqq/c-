#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//extern int Add(int x, int y);			//�ⲿ�����ɵ��ú���
//int main()
//{
//	int a = 10;							//��������a	
//	int b = 20;
//	int c = Add(a,b);					//ʹ�ú���
//	printf("%d \n",c);
//	return 0;
//}
//
//#define MAX 100					//Ԥ���룬û�н��б���ɽ�MAX�滻Ϊ100��ֻ���滻���μӼ���
//
////Ԥ�������
//
//
////int main()
////{
////	printf("%s\n",__FILE__);
////	printf("%d\n",__LINE__);
////	printf("%s\n",__DATE__);
////	printf("%s\n",__TIME__);
////	//д��־
////	int i = 0;
////	int arr[10];
////	FILE* pf = fopen("textd.txt","w");
////	for (i = 0;i < 10;i++)
////	{
////		arr[i]=i;
////		fprintf(pf, "flie:%s\n line:%d\n time:%s\n date:%s\n", __FILE__, __LINE__, __TIME__, __DATE__);
////	}
////	return 0;
////}
//
////#define ���Զ����ʶ��Ҳ���Զ����
////#include
////#��ͷ����Ԥ����ָ��
//
////#define MAX 100   //�������ж��������������������
////int main()
////{
////	printf("%d\n",MAX);
////	return 0;
////}
//
////#define reg register  //�����ؼ���
////
////#define do_forever for(;;)
////
////int main()
////{
////	do_forever;
////	return 0;
////}
//
////#define ����Ѳ����������ı���
//

#define SQUARE(X) X*X

//int main()
//{
//	int a = SQUARE(5+1);
//	printf("%d\n",a);//���ʱ�����11��5+1��ֱ���滻���������У������ʱ����㣬�����ʱ����Ҫ��x����������ҲҪ�������������
//	return 0;
//}
////�ַ����е����ݲ��ᱻ�滻

//#define PRINT(X) printf("the value of "#X" is %d\n",X)			//��#X�滻Ϊ�ַ������������������������
//int main()
//{
//	int A = 20;
//	int B = 30;
//	PRINT(A);
//	PRINT(B);
//	return 0;
//}

//##��ʹ�÷�����

//#define CAT(X,Y) X##Y
//int main()
//{
//	int class = 2019;
//	printf("%d\n", class);
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	int b = a + 1;
//	int b = ++a;
//	return 0;
//}

//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int c= MAX(a,b);
//	printf("%d\n",c);
//	return 0;
//}
//
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	printf("a=%d\n",a);
//	printf("b=%d\n",b);
//	printf("max=%d\n",max);
//	return 0;
//}//��Ĳ������滻��ȥ��������м���
//
//int main()
//{
//
//	return 0;
//}
//
//int Max(int x, int y)
//{
//
//	return(x > y ? x : y);
//}

//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//
//int main()
//{
//	float c = 3.0f;
//	float b = 4.0f;
//	float a = MAX(b,c);
//
//	printf("%f\n",a);
//	return 0;
//}

#define test(x,y) printf("test\n")

int mian()
{
	int a = 0; 
	int b = 0;
	test(a, c);
	return 0;
}
#define SIZEOF(type) sizeof(type)						//�滻���ͣ�����������

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));			//����10�����οռ��С

}

#define MALLOC(SIZE,TYPE) (TYPE*)malloc(SIZE,sizeof(TYPE))

//���ǲ����Ե��Եģ�Ҳ�����Եݹ�

//