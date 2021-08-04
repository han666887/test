#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>

typedef struct PeoInfo {
	char stunum[10];
	char name[10];
	int  age;
	char sxe[3];
	char tell[12];
	char QQ[10];
} PeoInfo;

//typedef struct Contact {
//	PeoInfo data[1000];
//	int sz;
//}Contact;

typedef struct Contact {
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;

//增加信息
void AddInfor(Contact* pc);

//查找
int Search(Contact* pc);

//删除
void DelInfor(Contact* pc);

//打印
void ShowInfor(Contact* pc);

//修改
void ModifyInfor(Contact* pc);

//排序
void SortInfor(Contact* pc);
//初始化
void InitContact(Contact* pc);

//保存信息
void SaveInfor(Contact* pc);