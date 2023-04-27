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
//    // 打开文件
//    fp = fopen("test.txt", "w");
//
//    // 写入数据到文件中
//    fprintf(fp, "This is some data that we're writing to the file.\n");
//
//    // 将文件指针移动到文件起始位置
//    rewind(fp);
//
//    // 从文件中读取数据
//    fgets(buffer, 255, fp);
//    printf("The data in the file is: %s\n", buffer);
//
//    // 关闭文件
//    fclose(fp);
//
//    return 0;
//}

//int main()
//{
//    FILE* fp = fopen("NIHAO.TXT","w");  //打开一个文件，没有就创建
//    fclose(fp);
//    return 0;
//}
//***************fgetc,从文件中读取一个字符并返回一个ascll码值
//int main()
//{
//	FILE* fp;
//	char c;
//	fp = fopen("test.txt","r");//打开文件，执行读的命令
//	if (fp == NULL)		//如果是空指针表示打开失败
//	{
//		printf("打开文件失败\n");
//	}
//	while ((c = fgetc(fp)) != EOF)//直到找到EOF文件结束标志位停止循环
//	{
//		printf("%c",c);
//	}
//	fclose(fp);					//循环结束
//	return 0;
//}


///fputs写一个字符到文件中   int fputs(int c FILE * stream);c是要写入的字符，参数stream是要写入的文件地址，返回值是字符的ascll码值
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");			//打开一个问价
//	if (pf == NULL)								//判断是否打开成功
//	{
//		printf("Faild to open file\n");
//		return 1;
//	}
//	int a = fputc('a',pf);						//写入一个数字
//	if (a == EOF)								//写入失败就返回EOF
//	{
//		printf("Faild to write char");
//		return 1;
//	}
//
//	fclose(pf);								//关闭文件
//
//
//	return 0;
//}


//fgets函数是C语言中用于文件或标准输入读取一行字符串的函数
//str是要输入的字符串，n是最大读取字符，文件指针或默认数据流，返回值是char*的指针
//char *fgets(char *str, int n, FILE *stream);


//int main()
//{
//    char str[100];              //定义一个字符数组
//    printf("请输入一行字符串:\n");
//    if (fgets(str, sizeof(str), stdin) != NULL)//读取一行字符串，读取失败不读取
//    {
//        printf("你输入的字符串是:%s", str);
//    }
//    else
//    {
//        printf("读取失败\n");
//    }
//    
//	return 0;
//}


//int fputs(const char *str, FILE *stream);
//返回值是为非负数写入成功，返回值是EOF写入失败或错误
//int main()
//{
//	char fp[100] = "abcdefg";
//	fputs(fp, stdout);//文件写入，将fp数组里的内容写到stdout标准输出上就是显示屏
//	return 0;
//}

//int fscanf(FILE* stream, const char* format, ...);  把第一个参数改为标准输入流stdin相等于scanf，返回参数是读取的数据个项

//

//int fprintf(FILE* stream,const char *a[].....)   返回值是写入数据的个数，参数是数据流（可以是标准流），要写入的数据


//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );

