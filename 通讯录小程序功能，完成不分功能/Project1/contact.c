#define _CRT_SECURE_NO_WARNINGS 1
//存放好友的信息，名字，电话，性别，住址，年龄
//增加好友信息
//删除制定名字好有信息
//查找好有信息
//修改好有信息
//打印好有信息

#include "contact.h"
#include <string.h>

void InitContact(struct Contact* ps)
{
	memset(ps->data,0,sizeof(ps->data));//内存设置，将ps指向的data数组的内容设置为0，设置数组里大小的字节
	ps->size = 0;						//数量设置为0
}

void AddContact(struct Contact* ps)
{
	if (ps->size==MAX)			//当数量等于1000，表示已经满了
	{
		printf("通讯录已经满，无法增加");		//无法添加
	}
	else									//否则就添加数据
	
	{
		printf("请输入名字:>");				
		scanf("%s",ps->data[ps->size].name);		//ps指向的数组，数组下标为ps指向的个数，数组里是结构体成员.name表示访问其中的name成员
		printf("请输入年龄>:");
		scanf("%d",&(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[ps->size].tele);
		printf("请输入住址:>");
		scanf("%s",ps->data[ps->size].addr);

		(ps->size)++;								//添加完数据后，数量++
		printf("添加成功\n");
	}
}

void ShowContact(struct Contact* ps)				//显示存放的名单
{
	if (ps->size==0)								//结构体里成员，size为零表示没有存放
	{
		printf("通讯录为空\n");

	}
	else
	{
														//否则就显示相应数据
	}
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "名字", "年龄", "性别", "电话", "住址");	//名字电话性别电话住址注意对齐用t，
		for (i = 0;i < ps->size;i++)															//显示size个数量的通讯录
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",										//显示一个通讯录的数量
					ps->data[i].name,
					ps->data[i].age,
					ps->data[i].sex,
					ps->data[i].tele,
					ps->data[i].addr
				);

		}
	}

}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删的名字:>");
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (0 == strcmp(ps->data[i].name, name));

	}

}