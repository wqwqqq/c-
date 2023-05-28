#pragma once
//1.存放1000个好友信息
//名字
//电话
//性别
//住址
//年龄
//2.增加好友信息
//3.删除好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

struct Peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct Peoinfo data[MAX];
	int size;
};


void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SercachContact(struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(struct Contact* ps);