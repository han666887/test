#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//函数回调方法
//void mune() {
//	printf("*************************\n");
//	printf("*****1.Add   2.Sub ******\n");
//	printf("*****3.Mul   4.Div ******\n");
//	printf("********* 0.esit   ******\n");
//	printf("*************************\n");
//}
//
//void Add(int x, int y) {
//	int sum = x + y;
//	printf("%d\n", sum);
//}
//void Sub(int x, int y) {
//	int sum = x - y;
//	printf("%d\n", sum);
//}
//void Mul(int x, int y) {
//	int sum = x * y;
//	printf("%d\n", sum);
//}
//void Div(int x, int y) {
//	int sum = x / y;
//	printf("%d\n", sum);
//}
//
//void clse(void(*pf)(int x,int y)) {
//	int a = 0, b = 0;
//	printf("请输入数据：");
//	scanf("%d%d", &a, &b);
//	(*pf)(a, b);
//}
//
//int main() {
//	mune();
//	int input = 0;
//	do {
//		int a = 0, b = 0;
//		printf("请输入：");
//		scanf("%d", &input);
//		switch (input) {
//		case 1:
//			clse(Add);
//			break;
//		case 2:
//			clse(Sub);
//			break;
//		case 3:
//			clse(Mul);
//			break;
//		case 4:
//			clse(Div);
//			break;
//		case 0:
//			break;
//		}
//	} while (input);
//
//	return 0;
//}




//函数指针数组方法
//void mune() {
//	printf("*************************\n");
//	printf("*****1.Add   2.Sub ******\n");
//	printf("*****3.Mul   4.Div ******\n");
//	printf("********* 0.esit   ******\n");
//	printf("*************************\n");
//}
//
//void Add(int x, int y) {
//	int sum = x + y;
//	printf("%d\n", sum);
//}
//void Sub(int x, int y) {
//	int sum = x - y;
//	printf("%d\n", sum);
//}
//void Mul(int x, int y) {
//	int sum = x * y;
//	printf("%d\n", sum);
//}
//void Div(int x, int y) {
//	int sum = x / y;
//	printf("%d\n", sum);
//}
//
//int main() {
//	mune();
//	int input = 0;
//	do {
//		int a = 0, b = 0;
//		printf("请输入：");
//		scanf("%d", &input);
//		void(*pfArr[5])(int, int) = { Add,Sub,Mul,Div };
//		if (input == 0) {
//			break;
//		}
//		else if (input >= 0 && input <= 4) {
//			printf("请输入数据：");
//			scanf("%d%d", &a, &b);
//			pfArr[input - 1](a, b);
//		}
//		else {
//			printf("输入错误");
//			continue;
//		}
//	} while (input);
//
//	return 0;
//}


//比较撮的方法
//void mune() {
//	printf("*************************\n");
//	printf("*****1.Add   2.Sub ******\n");
//	printf("*****3.Mul   4.Div ******\n");
//	printf("********* 0.esit   ******\n");
//	printf("*************************\n");
//}
//
//void Add(int x, int y) {
//	int sum = x + y;
//	printf("%d\n", sum);
//}
//void Sub(int x, int y) {
//	int sum = x - y;
//	printf("%d\n", sum);
//}
//void Mul(int x, int y) {
//	int sum = x * y;
//	printf("%d\n", sum);
//}
//void Div(int x, int y) {
//	int sum = x / y;
//	printf("%d\n", sum);
//}
//
//int main() {
//	mune();
//	int input = 0;
//	do {
//		int a = 0, b = 0;
//		printf("请输入：");
//		scanf("%d", &input);
//
//		switch(input){
//		case 1:
//			printf("请输入数据：");
//			scanf("%d%d", &a, &b);
//			Add(a, b);
//			break;
//		case 2:
//			printf("请输入数据：");
//			scanf("%d%d", &a, &b);
//			Sub(a, b);
//			break;
//		case 3:
//			printf("请输入数据：");
//			scanf("%d%d", &a, &b);
//			Mul(a, b);
//			break;
//		case 4:
//			printf("请输入数据：");
//			scanf("%d%d", &a, &b);
//			Div(a, b);
//			break;
//		case 0:
//			break;
//
//		}
//	} while (input);
//
//	return 0;
//}