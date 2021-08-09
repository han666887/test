#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

//ջ��ʼ��
void StackInit(Stack* ps) {
	assert(ps);

	STDataType* p = (STDataType*)malloc(sizeof(STDataType)*2);
	if (p == NULL) {
		printf("p==NULL");
		exit(-1);
	}
	else {
		ps->p = p;
	}
	ps->top = 0;
	ps->capacity = 2;
}


//��ջ
void StackPush(Stack* ps,STDataType x) {
	assert(ps);

	if (ps->top == ps->capacity) {
		STDataType* p = (STDataType*)realloc(ps->p,sizeof(STDataType) * ps->capacity * 2);
		if (p == NULL) {
			printf("p==NULL");
			exit(-1);
		}
		else {
			ps->p = p;
			ps->capacity *= 2;
		}
	}
	ps->p[ps->top] = x;
	ps->top++;
}

//��ջ
void StackPop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}


//��ӡ
void StackPrint(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	STDataType i = ps->top;
	while (i) {
		printf("%d ", ps->p[i - 1]);
		i--;
	}
	printf("\n");
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps) {
	assert(ps);
	return ps->top == 0;
}

//��ȡջͷ
STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->p[ps->top - 1];
}

//��ջ����Ч��ЧԪ�ظ���
STDataType StackSize(Stack* ps) {
	assert(ps);
	return ps->top;
}

//����ջ
void StackDistory(Stack* ps) {
	assert(ps);
	free(ps->p);
	ps->p = NULL;
	ps->top = ps->capacity = 0;
}
