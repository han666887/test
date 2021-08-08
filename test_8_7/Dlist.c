#define _CRT_SECURE_NO_WARNINGS
#include "Dlist.h"

//����ͷ�ڵ�
ListNode* ListCreate() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	assert(head);
	head->next = head;
	head->prev = head;
	return head;
}

//��ӡ
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

//ͷ��
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

//ͷɾ
void ListPopFront(ListNode* phead) {
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->next;
	ListNode* next = tail->next;
	free(tail);
	phead->next = next;
	next->prev = phead;
}

//β��
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

//βɾ
void ListPopBack(ListNode* phead) {
	assert(phead);

	ListNode* back = phead->prev;
	ListNode* next = back->prev;
	free(back);
	phead->prev = next;
	next->next = phead;
}



//Ѱ��
ListNode* Find(ListNode* phead,int x) {
	assert(phead);
	ListNode* next = phead->next;
	while (next->val != x&&next!=phead) {
		next = next->next;
	}
	return next;
}

// ˫��������pos��ǰ����в���
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
//ɾ��˫������ĳ�����
void ListErase(ListNode* pos) {
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}


//��������
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
