#define _CRT_SECURE_NO_WARNINGS 1
//��ź��ѵ���Ϣ�����֣��绰���Ա�סַ������
//���Ӻ�����Ϣ
//ɾ���ƶ����ֺ�����Ϣ
//���Һ�����Ϣ
//�޸ĺ�����Ϣ
//��ӡ������Ϣ

#include "contact.h"
#include <string.h>

void InitContact(struct Contact* ps)
{
	memset(ps->data,0,sizeof(ps->data));//�ڴ����ã���psָ���data�������������Ϊ0�������������С���ֽ�
	ps->size = 0;						//��������Ϊ0
}

void AddContact(struct Contact* ps)
{
	if (ps->size==MAX)			//����������1000����ʾ�Ѿ�����
	{
		printf("ͨѶ¼�Ѿ������޷�����");		//�޷����
	}
	else									//������������
	
	{
		printf("����������:>");				
		scanf("%s",ps->data[ps->size].name);		//psָ������飬�����±�Ϊpsָ��ĸ������������ǽṹ���Ա.name��ʾ�������е�name��Ա
		printf("����������>:");
		scanf("%d",&(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s",ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s",ps->data[ps->size].tele);
		printf("������סַ:>");
		scanf("%s",ps->data[ps->size].addr);

		(ps->size)++;								//��������ݺ�����++
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct Contact* ps)				//��ʾ��ŵ�����
{
	if (ps->size==0)								//�ṹ�����Ա��sizeΪ���ʾû�д��
	{
		printf("ͨѶ¼Ϊ��\n");

	}
	else
	{
														//�������ʾ��Ӧ����
	}
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "����", "����", "�Ա�", "�绰", "סַ");	//���ֵ绰�Ա�绰סַע�������t��
		for (i = 0;i < ps->size;i++)															//��ʾsize��������ͨѶ¼
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",										//��ʾһ��ͨѶ¼������
					ps->data[i].name,
					ps->data[i].age,
					ps->data[i].sex,
					ps->data[i].tele,
					ps->data[i].addr
				);

		}
	}

}

static int FindByname(struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (0 == memcmp(ps->data[i].name, name,MAX_NAME));
		{
			return i;
		}

	}

	return -1;
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ������:>");
	scanf("%s",name);
	// ����Ҫɾ��������ʲôλ��
	//ɾ��
	int pos = FindByname(ps, name);
	if (pos==-1)
	{
		printf("Ҫɾ�������ֲ�����\n");
	}

	else
	{
		int j = 0;
		for (j = pos;j <ps->size-1;j++)
		{
			ps->data[j] = ps->data[j + 1];

		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void Searcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�����:>");
	scanf("%s",name);
	int pos = FindByname(ps, name);
		if (pos == -1)
		{
			printf("�Ҳ�������\n");
		}
		else
		{
			printf("�ҵ���\n");
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "����", "����", "�Ա�", "�绰", "סַ");	//���ֵ绰�Ա�绰סַע�������t��
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",										//��ʾһ��ͨѶ¼������
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr
			);

		}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ�λ��\n");
	scanf("%s",name);
	int pos=FindByname(ps,name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ����ֲ�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);		//psָ������飬�����±�Ϊpsָ��ĸ������������ǽṹ���Ա.name��ʾ�������е�name��Ա
		printf("����������>:");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("������סַ:>");
		scanf("%s", ps->data[pos].addr);

		printf(" �޸ĳɹ�\n");

	}

}


void SortContact(struct Contact* ps)
{


}