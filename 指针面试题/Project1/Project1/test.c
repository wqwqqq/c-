#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };  //�ַ�ָ������
//	char** cp[] = {c+3,c+2,c+1,c};                  //�ַ�ָ�����������
//	char*** cpp = cp;								//��ַ
//	printf("%s\n",**++cpp);							//��++��ʹ�ã���Ԫ�ص�ַ++
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n",*cpp[-2]+3);
//	printf("%s\n",*cpp[-1][-1]+1);
//
//	return 0;
//}

//int main()
//{
//	unsigned long p[] = { 6,7,8,9,10 };  //��������
//	unsigned long* pa = p;				//����ָ��
//	*(pa + 3) += 3;						//�����õ�ֵ�ӵ���3������12
//	printf("%d,%d\n",*pa,*(pa+3));		//����������Ԫ���׵�ַ
//		return 0;
//}

//#include <string.h>
//
//void reverse(char* p, int sz)   //������������������������Ԫ����ַ������������ָ�����
//{
//	int len = strlen(p);			//������ĳ���
//	char* left = p;					//��������±��ַ
//	char* right = p + len - 1;		//��������±��ַ
//	while (left < right)				//��������Ԫ��ʵ�ֽ���λ��
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()		
//{
//	char arr[256] = { 0 };			//����һ���ַ�����
//	scanf("%s",arr);				//��ȡ��������
//	int sz = sizeof(arr) / sizeof(arr[0]);	//�������Ԫ�ظ���
//	reverse(arr,sz);
//	printf("%s\n",arr);
//	return 0;
//}

int main()
{
	int a = 0;
	int n = 0;
	scanf("%d%d",&a,&n);//��ȡ����ֵ
	int i = 0;
	int sum = 0;
	int ret = 0;
	for (i = 0;i < n;i++)//ѭ�����a+aa+aaa,n��
	{
		ret = ret * 10 + a;
		sum += ret;

	}
	printf("%d\n",sum);
	return 0;
}
#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0;i < 100000;i++)   //���i��0��100000����ֵ
//	{
//		int n = 1;
//		int tem = i;
//		int sum = 0;
//		while (tem/= 10)			//���i��λ��
//		{
//			n++;
//		}
//		tem = i;					//��i��ֵ����tem
//		while (tem)					//����
//		{
//			sum += (int)pow(tem % 10, n);
//			tem /= 10;
//		}
//		if (i == sum)//�ж��Ƿ����
//		{
//			printf("%d ",i);��Ⱦ����i
//		}
//	}
//	return 0;
//}