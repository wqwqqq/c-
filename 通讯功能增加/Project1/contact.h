#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_SEX 5

struct PeoInfo			//����ṹ�壬�������֣����䣬�Ա𣬵�ַ���绰
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
	char tele[MAX_TELE];
};

struct Contact		//����ṹ�壬��������ṹ�����飬������
{
	struct PeoInfo data[MAX];
	int size;
};


enum				//����ö�ٳ���
{
	EXIT,
	ADD,DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT

};

//**************������������*************************************************************

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);	//ɾ��ָ����ϵ��
void Searcontact(struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(struct Contact* ps);