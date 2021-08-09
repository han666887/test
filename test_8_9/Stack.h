#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int STDataType;

typedef struct Stack {
	STDataType* p;
	STDataType top;
	STDataType capacity;
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps,STDataType x);

//��ջ
void StackPop(Stack* ps);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);

//��ȡջͷ
STDataType StackTop(Stack* ps);

//��ջ����Ч��ЧԪ�ظ���
STDataType StackSize(Stack* ps);

//����ջ
void StackDistory(Stack* ps);

//��ӡ
void StackPrint(Stack* ps);

