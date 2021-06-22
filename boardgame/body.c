#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//棋盘初始化
void Initboard(char board[hang][lie], int Hang, int Lie)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Hang; i++) {
		for (j = 0; j < Lie; j++) {
			board[i][j] = ' ';
		}
	}

}

//打印棋盘
void Displayboard(char board[hang][lie], int Hang, int Lie) {
	int i = 0;
	int j = 0;
	for (i = 0; i < Hang; i++) {
		for (j = 0; j < Lie; j++) {
			printf(" %c ", board[i][j]);
			if(j<Lie-1)
				printf("|");
		}
		printf("\n");
		if (i < Hang - 1) {
			for (j = 0; j < Lie; j++) {
				printf("---");
				if (j < Lie - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}

//玩家
void Pleargame(char board[hang][lie], int Hang, int Lie) {
	int x = 0;
	int y = 0;
	while(1){
		printf("请玩家输入:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= Hang && y >= 1 && y <= Lie) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("该处已被占,请重新输入:");
			}
		}
		else {
			printf("非法坐标请从新输入\n");
		}	
	}
	
}

//电脑下
void Windowsgame(char board[hang][lie], int Hang, int Lie) {
	printf("请等待电脑输入\n");
	while (1) {
		int x = rand()%Hang;
		int y = rand()%Lie;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}	
}

//判断赢家
char Win(char board[hang][lie], int Hang, int Lie) {
	int i = 0, j = 0;
	for (i = 0; i <= Hang; i++) {
			if (board[i][0] == board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
				return board[i][j];	
	}
	for (i = 0; i <= Lie; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[i][j];
	}
	for (i = 0; i <= Hang; i++) {
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
			return board[i][j];
	}
}