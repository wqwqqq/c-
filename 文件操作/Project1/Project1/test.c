#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////int mian()
////{
////	FILE* pf = fopen("wangquanwu.txt","w");
////	if (pf == NULL)
////	{
////		printf("falie open file");
////	}
////	else
////	{
////		fputs("fopen example",pf);
////		fclose(pf);
////	}
////	return 0;
////}

#include <stdio.h>

//int main() {
//    FILE* fp;
//    char buffer[255];
//
//    // ���ļ�
//    fp = fopen("test.txt", "w");
//
//    // д�����ݵ��ļ���
//    fprintf(fp, "This is some data that we're writing to the file.\n");
//
//    // ���ļ�ָ���ƶ����ļ���ʼλ��
//    rewind(fp);
//
//    // ���ļ��ж�ȡ����
//    fgets(buffer, 255, fp);
//    printf("The data in the file is: %s\n", buffer);
//
//    // �ر��ļ�
//    fclose(fp);
//
//    return 0;
//}

//int main()
//{
//    FILE* fp = fopen("NIHAO.TXT","w");  //��һ���ļ���û�оʹ���
//    fclose(fp);
//    return 0;
//}
//***************fgetc,���ļ��ж�ȡһ���ַ�������һ��ascll��ֵ
//int main()
//{
//	FILE* fp;
//	char c;
//	fp = fopen("test.txt","r");//���ļ���ִ�ж�������
//	if (fp == NULL)		//����ǿ�ָ���ʾ��ʧ��
//	{
//		printf("���ļ�ʧ��\n");
//	}
//	while ((c = fgetc(fp)) != EOF)//ֱ���ҵ�EOF�ļ�������־λֹͣѭ��
//	{
//		printf("%c",c);
//	}
//	fclose(fp);					//ѭ������
//	return 0;
//}


///fputsдһ���ַ����ļ���   int fputs(int c FILE * stream);c��Ҫд����ַ�������stream��Ҫд����ļ���ַ������ֵ���ַ���ascll��ֵ
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");			//��һ���ʼ�
//	if (pf == NULL)								//�ж��Ƿ�򿪳ɹ�
//	{
//		printf("Faild to open file\n");
//		return 1;
//	}
//	int a = fputc('a',pf);						//д��һ������
//	if (a == EOF)								//д��ʧ�ܾͷ���EOF
//	{
//		printf("Faild to write char");
//		return 1;
//	}
//
//	fclose(pf);								//�ر��ļ�
//
//
//	return 0;
//}


//fgets������C�����������ļ����׼�����ȡһ���ַ����ĺ���
//str��Ҫ������ַ�����n������ȡ�ַ����ļ�ָ���Ĭ��������������ֵ��char*��ָ��
//char *fgets(char *str, int n, FILE *stream);


//int main()
//{
//    char str[100];              //����һ���ַ�����
//    printf("������һ���ַ���:\n");
//    if (fgets(str, sizeof(str), stdin) != NULL)//��ȡһ���ַ�������ȡʧ�ܲ���ȡ
//    {
//        printf("��������ַ�����:%s", str);
//    }
//    else
//    {
//        printf("��ȡʧ��\n");
//    }
//    
//	return 0;
//}


//int fputs(const char *str, FILE *stream);
//����ֵ��Ϊ�Ǹ���д��ɹ�������ֵ��EOFд��ʧ�ܻ����
//int main()
//{
//	char fp[100] = "abcdefg";
//	fputs(fp, stdout);//�ļ�д�룬��fp�����������д��stdout��׼����Ͼ�����ʾ��
//	return 0;
//}

//int fscanf(FILE* stream, const char* format, ...);  �ѵ�һ��������Ϊ��׼������stdin�����scanf�����ز����Ƕ�ȡ�����ݸ���

//

//int fprintf(FILE* stream,const char *a[].....)   ����ֵ��д�����ݵĸ������������������������Ǳ�׼������Ҫд�������


//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );

