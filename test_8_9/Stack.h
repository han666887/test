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

//初始化栈
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps,STDataType x);

//出栈
void StackPop(Stack* ps);

//判断栈是否为空
bool StackEmpty(Stack* ps);

//获取栈头
STDataType StackTop(Stack* ps);

//求栈内有效有效元素个数
STDataType StackSize(Stack* ps);

//销毁栈
void StackDistory(Stack* ps);

//打印
void StackPrint(Stack* ps);

