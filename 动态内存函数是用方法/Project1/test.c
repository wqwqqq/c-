#define _CRT_SECURE_NO_WARNINGS 1

//��̬�ڴ溯���Ľ���
//malloc  ��   free����

/*void * mallco(size_t size)*/ //���������ǿ�ָ�룬ָ�򿪱ٿռ�λ�õ�ָ�룬�����ǿ��ٿռ�Ĵ�С��λ���ֽڣ����ٿռ�ʧ�ܷ��ص��ǿ�ָ��

//void free(void * ptr)			//�޷��أ�������ָ��ռ��ָ�룬�ͷŶ�̬���ٵ��ڴ棬ptr��Ҫָ����Ƕ�̬���ٵĿռ䣬ջ�Ϻ;�̬���Ŀռ䶼������free���ͷź�ָ����Ҫ��Ϊ��ָ��

#include <stdio.h>

//int main()
//{
//	int num = 0;
//	printf("������num��ֵ:>");
//	scanf("%d",&num);
//	//int arr[num] = { 0 };
//	int* ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//
//	/*if (ptr != NULL)*/
//	/*{*/
//		int i = 0;
//		for (i = 0;i < num;i++)
//		{
//			*(ptr + i)=i;
//			printf("%d ",*(ptr+1));
//		}
//
//		free(ptr);
//		ptr = NULL;
//
//	//}
//
//	return 0;
//}

//  calloc �������䶯̬�ڴ�
// void* calloc(size_t num,size_t size)  //����ֵ�ǿ��ٿռ�ĵ�ַָ�룬�����ǿ��ٵĸ�������С��size���ֽڣ������ٿռ��ֵ��ʼ��Ϊ0��

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int* p = (int*)calloc(10,sizeof(int));
//	if (p != NULL)
//	{
//		int i = 0;
//		for (i = 0;i < 10;i++)
//		{
//			p[i] = i;
//			printf("%d ",p[i]);
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc ��̬�ڴ�׷��
//void * realloc (void* ptr,size_t size);//����������ָ�򿪱ٿռ�λ�õ�ָ�룬����ʧ�ܷ��ؿ�ָ�룬������ָ��̬�ռ�ĵ�ַ������֮����´�С

//���ٿռ��������������һ��ԭ�ռ�������㹻��Ŀռ俪���¿ռ䣬
//�ڶ������ԭ�ռ����û���㹻��Ŀռ俪���¿ռ䣬����������λ�ÿ���һ�������Ŀռ䣬��ԭ�ռ�����ݿ������¿ռ��У����ͷŵ�ԭ�ռ䡣


//#include <stdio.h>
//
//int main()
//{
//	int* ptr = (int *)malloc(100);
//	int* p = (int*)realloc(ptr,1000);
//	if (p != NULL)
//	{
//		ptr = p;
//		free(ptr);
//		ptr = NULL;
//	}
//
//
//	return 0;
//}
//

//���ܶԿ�ָ���Ӧ�ò��������Կ��ٿռ��ʱ��ע���ж��Ƿ񿪱ٿռ�ɹ�

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("���ٿռ�ʧ��");
//		return 0;
//	}
//	for (i = 0;i < 12;i++)//��̬���ٵĿռ�Խ����ʻ�������⣬��������ʹ��
//	{
//		p[i] = i;
//		printf("%d ",p[i]);
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//�ͷŲ��Ƕ�̬���ٵ��ڴ棬�����ֱ�ӿ���
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//�ͷŲ���ָ��̬�洢����ʼλ�ô���
//	return 0;
//}

//�����ظ��ͷŶ�̬�洢�������ͷŻ��Գ��ڴ�й©

//int main()
//{
//	while (1)
//	{
//		int* p = (int*)malloc(40);
//	}
//	return 0;
//}

//void a(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void test(void)
//{
//	char* str = NULL;
//	a(&str);
//	strcpy(str, "hello world");
//	printf(str);
//
//}
//int main()
//{
//	test();
//	return 0;
//}

//char* GetMemor(void)
//{
//	char p[] = "hello world";
//	return p;
//
//}
//
//void test(void)
//{
//	char* str = NULL;
//	str = GetMemor();//���ص�������ĵ�ַ�����Ƿ��غ�����ᱻ���٣����ڷǷ�����
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}

//void GetMeory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void test(void)
//{
//
//	char* str = NULL;
//	GetMeory(&str,100);
//	strcpy(str,"hello ��ȫ��");
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
//
//void test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str,"hello wangquanwu");
//	free(str);//����Ŀռ��Ѿ����ͷŵ��ˣ������ٽ���ʹ��
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//
//	}
//
//}

//�������飬�ṹ���бش���������ǰ��Ҫ��һ����Ա����������Ľṹʹ��malloc�����������ж�̬���䣬���ҷ�����ڴ��СӦ�ô��ڽṹ��Ĵ�

typedef struct s				//����ṹ������s
{
	int i;
	int a[0];					//�������飬��malloc����ռ���Ըı��С

}s;								//�ṹ�����s�����λ�ö���Ľṹ�������ȫ�ֱ���

int main()
{
	s* p = NULL;
	printf("%d",sizeof(s));//��СΪ4

	p = (s*)malloc(sizeof(s)+100*sizeof(int));

	return 0;
}

