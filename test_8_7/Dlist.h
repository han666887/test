#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode {
	struct ListNode* next;
	struct ListNode* prev;
	int val;
}ListNode;

//����ͷ�ڵ�
ListNode* ListCreate();

//��ӡ
void ListPrint(ListNode* phead);

//ͷ��
void ListPushFront(ListNode* phead, int x);

//ͷɾ
void ListPopFront(ListNode* phead);

//β��
void ListPushBack(ListNode* phead,int x);

//βɾ
void ListPopBack(ListNode* phead);

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, int x);

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);

//Ѱ��
ListNode*  Find(ListNode* phead,int x);

// ˫����������
void ListDestory(ListNode* plist);