#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//数据文件，文件名，文件类型

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("text.txt","wangquanwu");
//	fwrite(&a,4,1,pf);
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf=fopen("test.txt","w");
//	fclose(pf);
//	pf=fopen("test","r");
//	
//	return 0;
//}

//fputc,文件输出流
//键盘&屏幕是标准流

//int main()
//{
//	FILE* pf=fopen("test.txt","w");
//	if (pf == NULL)
//	{
//		return;
//	}
//	fputc('b', pf);
//	fputc('i', pf);
//	fputc('w', pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//输入流
int main()
{	
	FILE* pf = fopen("test.txt","r");
	printf("%c",fgetc(pf));
	printf("%c", fgetc(pf));
	printf("%c",fgetc(pf));

	int ch = fgetc(stdin);
	fputc(ch,stdout);
	return 0;
}