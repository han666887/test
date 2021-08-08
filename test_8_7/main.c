#define _CRT_SECURE_NO_WARNINGS
#include "Dlist.h"



void Text1(ListNode* phead) {
	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);

	ListNode* pos=Find(phead, 2);
	ListInsert(pos, 5);
	ListPrint(phead);

    pos = Find(phead, 3);
	ListErase(pos);
	ListPrint(phead);

}
void Text2(ListNode* phead) {
	ListPushBack(phead, 4);
	ListPushBack(phead, 3);
	ListPushBack(phead, 2);
	ListPushBack(phead, 1);
	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

}
void Text3(ListNode* phead) {
	ListPushBack(phead, 4);
	ListPushBack(phead, 3);
	ListPushBack(phead, 2);
	ListPushBack(phead, 1);
	ListPrint(phead);

	ListDestory(phead);
	ListPrint(phead);
}
int main() {
	ListNode* phead = ListCreate();
	//Text1(phead);
	//Text2(phead);
	Text3(phead);


	free(phead);
	return 0;
}