#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_SEX 5

struct PeoInfo			//定义结构体，包含名字，年龄，性别，地址，电话
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
	char tele[MAX_TELE];
};

struct Contact		//定义结构体，里面包含结构体数组，和数量
{
	struct PeoInfo data[MAX];
	int size;
};


enum				//定义枚举常量
{
	EXIT,
	ADD,DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT

};

//**************函数声明部分*************************************************************

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);	//删除指定联系人
void Searcontact(struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(struct Contact* ps);