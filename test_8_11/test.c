#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QDataType;

typedef struct QListNode {
    struct QListNode* next;
    QDataType x;
}QNode;

typedef struct Queue {
    QNode* front;
    QNode* rear;
}Queue;

typedef struct {
    Queue q;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (p == NULL) {
        printf("p==NULL");
        exit(-1);
    }
    else {
        MyCircularQueue* obj = p;
        QNode* head = (QNode*)malloc(sizeof(QNode));
        QNode* cur = head;

        while (k) {
            QNode* newnode = (QNode*)malloc(sizeof(QNode));
            cur->next = newnode;
            cur = cur->next;
            k--;
        }
        cur->next = head;
        obj->q.front = obj->q.rear = head->next;
        return obj;
    }
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if (obj->q.rear->next != obj->q.front) {
        obj->q.rear->x = value;
        obj->q.rear = obj->q.rear->next;
        return true;
    }
    else {
        return false;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    QNode* cur = obj->q.front;
    if (obj->q.rear == obj->q.front) {
        return false;
    }
    else {
        obj->q.front = obj->q.front->next;
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (obj->q.rear == obj->q.front) {
        return -1;
    }
    else {
        return obj->q.front->x;
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (obj->q.rear == obj->q.front) {
        return -1;
    }
    else {
        QNode* cur = obj->q.front;
        while (1) {
            if (cur->next == obj->q.rear) {
                return cur->x;
            }
            else {
                cur = cur->next;
            }
        }
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    if (obj->q.rear == obj->q.front) {
        return true;
    }
    else {
        return false;
    }
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    if (obj->q.rear->next == obj->q.front) {
        return true;
    }
    else {
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj);
}

int main() {

    MyCircularQueue* obj = myCircularQueueCreate(8);
    myCircularQueueEnQueue( obj,  3);
    myCircularQueueEnQueue(obj, 9);
    myCircularQueueEnQueue( obj,5);
    myCircularQueueEnQueue( obj, 0);
    myCircularQueueDeQueue( obj);
    myCircularQueueDeQueue(obj);
    myCircularQueueIsEmpty(obj);
    myCircularQueueIsEmpty(obj);
    int x1=myCircularQueueRear(obj);
   int x2= myCircularQueueRear( obj);
   printf("%d %d", x1, x2);
    myCircularQueueDeQueue(obj);
    return 0;
}