#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data,0,sizeof(ps->data));
	ps->size = 0;
}

static int FindByName(struct Contact* ps,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (0 == strcmp(name, ps->data[i].name))
		{
			return i;;
		}
	}
	return -1;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满\n");

	}
	else
	{
		printf("请输入名字>:");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄>:");
		scanf("%d",&(ps->data[ps->size].age));
		printf("请输入性别>:");
		scanf("%s",ps->data[ps->size].sex);
		printf("请输入电话>:");
		scanf("%s",ps->data[ps->size].tele);
		printf("请输入地址>:");
		scanf("%s",ps->data[ps->size].addr);
		
		ps->size++;
		printf("添加成功\n");
	}

}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		for (i = 0;i < ps->size;i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
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
	printf("请输入要删除人的名字:>");
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if (pos==-1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos;j <ps->size-1 ;j++)
		{
			ps->data[j] = ps->data[j+ 1];
		}
		ps->size--;
		printf("删除成功\n");
	}

}

void SercachContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入名字:>");
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	
		
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s",&name);
	int pos =FindByName(ps,name);
	if (pos == -1)
	{
		printf("你修改的名字不存再\n");
	}
	else
	{
		printf("请输入名字>:");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄>:");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别>:");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话>:");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址>:");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功\n");
	}
}

int cmp1(const void* a,const void* b)
{
	return strcmp(((struct Peoinfo*)a)->name, ((struct Peoinfo*)b)->name);
}
int cmp2(const void* a, const void* b)
{
	return strcmp(((struct Peoinfo*)a)->sex, ((struct Peoinfo*)b)->sex);
}
int cmp3(const void* a, const void* b)
{
	return strcmp(((struct Peoinfo*)a)->tele, ((struct Peoinfo*)b)->tele);
}
int cmp4(const void* a, const void* b)
{
	return strcmp(((struct Peoinfo*)a)->addr, ((struct Peoinfo*)b)->addr);
}

int cmp5(const void* a, const void* b)
{
	return (((struct Peoinfo*)a)->age-((struct Peoinfo*)b)->age);
}



void SortContact(struct Contact* ps)
{
	int input = 0;
	printf("请输入排序方法");
	printf("1.名字 2.性别 3.电话 4.地址 5.年龄:>");
	scanf("%d",&input);
	switch (input)
	{
	case 1:
		qsort(ps->data,ps->size,sizeof(struct Peoinfo),cmp1);
		break;
	case 2:
		qsort(ps->data, ps->size, sizeof(struct Peoinfo), cmp2);
		break;
	case 3:
		qsort(ps->data,ps->size,sizeof(struct Peoinfo),cmp3);
		break;
	case 4:
		qsort(ps->data,ps->size,sizeof(struct Peoinfo),cmp4);
		break;
	case 5:
		qsort(ps->data,ps->size,sizeof(struct Peoinfo),cmp5);
		break;

	}
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0;i < ps->size;i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr
		);
	}

}
