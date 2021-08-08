#define _CRT_SECURE_NO_WARNINGS
#include "Dlist.h"

//创建头节点
ListNode* ListCreate() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	assert(head);
	head->next = head;
	head->prev = head;
	return head;
}

//打印
void ListPrint(ListNode* phead) {
	assert(phead);

	ListNode* next = phead->next;
	if (next->next == phead) {
		printf("NULL");
	}
	else {
		while (next!=phead) {
			printf("%d ", next->val);
			next = next->next;
		}
	}
	printf("\n");
}

//头插
void ListPushFront(ListNode* phead, int x) {
	assert(phead);

	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;

	if (phead->next == phead) {
		phead->next = newnode;
		phead->prev = newnode;
		newnode->next = phead;
		newnode->prev = phead;

	}
	else {
		ListNode* tail = phead->next;
		phead->next = newnode;
		newnode->next = tail;
		tail->prev = newnode;
		newnode->prev = phead;
	}
}

//头删
void ListPopFront(ListNode* phead) {
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->next;
	ListNode* next = tail->next;
	free(tail);
	phead->next = next;
	next->prev = phead;
}

//尾插
void ListPushBack(ListNode* phead,int x) {
	assert(phead);

	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;

	ListNode* back = phead->prev;
	phead->prev = newnode;
	newnode->next = phead;
	back->next = newnode;
	newnode->prev = back;
}

//尾删
void ListPopBack(ListNode* phead) {
	assert(phead);

	ListNode* back = phead->prev;
	ListNode* next = back->prev;
	free(back);
	phead->prev = next;
	next->next = phead;
}



//寻找
ListNode* Find(ListNode* phead,int x) {
	assert(phead);
	ListNode* next = phead->next;
	while (next->val != x&&next!=phead) {
		next = next->next;
	}
	return next;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, int x) {
	assert(pos);

	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;

	ListNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;

}
//删除双向链表某个结点
void ListErase(ListNode* pos) {
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}


//销毁链表
void ListDestory(ListNode* plist) {
	assert(plist);

	ListNode* tail = plist->next;
	ListNode* next =NULL;
	while (tail != plist) {
		tail = plist->next;
		next = tail->next;
		free(tail);
		plist->next = next;
		next->prev = plist;
		tail = next;
	}
}
