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
		printf("ͨѶ¼����\n");

	}
	else
	{
		printf("����������>:");
		scanf("%s", ps->data[ps->size].name);
		printf("����������>:");
		scanf("%d",&(ps->data[ps->size].age));
		printf("�������Ա�>:");
		scanf("%s",ps->data[ps->size].sex);
		printf("������绰>:");
		scanf("%s",ps->data[ps->size].tele);
		printf("�������ַ>:");
		scanf("%s",ps->data[ps->size].addr);
		
		ps->size++;
		printf("��ӳɹ�\n");
	}

}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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
	printf("������Ҫɾ���˵�����:>");
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if (pos==-1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos;j <ps->size-1 ;j++)
		{
			ps->data[j] = ps->data[j+ 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}

}

void SercachContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����������:>");
	scanf("%s",name);
	int pos = FindByName(ps,name);
	if (pos == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	
		
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
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s",&name);
	int pos =FindByName(ps,name);
	if (pos == -1)
	{
		printf("���޸ĵ����ֲ�����\n");
	}
	else
	{
		printf("����������>:");
		scanf("%s", ps->data[pos].name);
		printf("����������>:");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�>:");
		scanf("%s", ps->data[pos].sex);
		printf("������绰>:");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ>:");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ�\n");
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
	printf("���������򷽷�");
	printf("1.���� 2.�Ա� 3.�绰 4.��ַ 5.����:>");
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
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
