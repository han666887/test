#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode {
	struct ListNode* next;
	struct ListNode* prev;
	int val;
}ListNode;

//创建头节点
ListNode* ListCreate();

//打印
void ListPrint(ListNode* phead);

//头插
void ListPushFront(ListNode* phead, int x);

//头删
void ListPopFront(ListNode* phead);

//尾插
void ListPushBack(ListNode* phead,int x);

//尾删
void ListPopBack(ListNode* phead);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, int x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);

//寻找
ListNode*  Find(ListNode* phead,int x);

// 双向链表销毁
void ListDestory(ListNode* plist);