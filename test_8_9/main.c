#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"



void Test1(Stack* pst) {
	StackInit(pst);
	StackPush(pst,1);
	StackPush(pst, 2);
	StackPush(pst, 3);
	StackPush(pst, 4);
	StackPush(pst, 5);
	StackPrint(pst);

	StackPop(pst);
	StackPop(pst);
	StackPop(pst);
	StackPrint(pst);

	STDataType s=StackTop(pst);
	printf("%d\n", s);

	STDataType a= StackEmpty(pst);
	printf("%d\n", a);

	STDataType x=StackSize(pst);
	printf("%d\n", x);

	StackDistory(pst);
}




int main() {
	Stack st;
	Test1(&st);
	return 0;
}