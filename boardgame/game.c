#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void mune()
{
	
	printf("***********************\n");
	printf("******1. play *********\n");
	printf("******2. exit *********\n");
	printf("***********************\n");
	
}

void game() {
	char board[hang][lie] = { 0 };
	Initboard(board, hang, lie);//初始化棋盘
	Displayboard(board, hang, lie);//打印棋盘
	char set = 0;
	while (1) {
		Pleargame(board, hang, lie);//玩家
		Displayboard(board, hang, lie);//从新打印棋盘
		set=Win(board, hang, lie);
		if (set == '*') {
			printf("玩家赢\n");
			break;
		}
		else if (set == '#') {
			printf("电脑赢\n");
			break;
		}
		Windowsgame(board, hang, lie);//电脑
		Displayboard(board, hang, lie);//从新打印棋盘
		set=Win(board,hang,lie);
		if (set == '*') {
			printf("玩家赢\n");
			break;
		}
		else if (set == '#') {
			printf("电脑赢\n");
			break;
		}
	}
}
int main()
{
	int k = 0;
	do {
		mune();
		scanf("%d", &k);
		srand((unsigned int)time(NULL));
		switch (k) {
		case 1:
			game();//玩游戏
			break;
		case 2:
			break;
		case 3:
			printf("输入错误\n");
			break;
		}
	} while (k);
	return 0;
}