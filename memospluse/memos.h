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

//������Ϣ
void AddInfor(Contact* pc);

//����
int Search(Contact* pc);

//ɾ��
void DelInfor(Contact* pc);

//��ӡ
void ShowInfor(Contact* pc);

//�޸�
void ModifyInfor(Contact* pc);

//����
void SortInfor(Contact* pc);
//��ʼ��
void InitContact(Contact* pc);

//������Ϣ
void SaveInfor(Contact* pc);