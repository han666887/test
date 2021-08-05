#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    else {
        struct ListNode* cur = head,* Next=cur->next;
        struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
        newhead->next = NULL;
        struct ListNode* newcur = newhead, * newnext = newcur->next;
        while (cur) {
            newcur = newhead;
            while (1) {
                newnext = newcur->next;
                Next = cur->next;
                if (newnext == NULL) {
                    newcur->next = cur;
                    cur->next = newnext;
                    cur = Next;
                    break;
                }
                else {
                    if (newnext->val < cur->val) {
                        newcur = newnext;
                    }
                    else {
                        newcur->next = cur;
                        cur->next = newnext;
                        cur = Next;
                        break;
                    }

                }
            }
        }
        struct ListNode* next = newhead->next;
        free(newhead);
        return next;
    }

}

int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* next1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* next2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* next3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 4;
    next1->val = 2;
    next2->val = 1;
    next3->val = 3;
    head->next = next1;
    next1->next = next2;
    next2->next = next3;
    next3->next = NULL;
    insertionSortList(head);
    free(head);
    free(next1);
    free(next2);
    free(next3);
    return 0;
}