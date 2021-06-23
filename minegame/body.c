#define _CRT_SECURE_NO_WARNINGS
#include "mine.h"

//初始化棋盘
void Initboard(char board[hangs][lies], int Hangs, int Lies,char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i <Hangs; i++) {
		for (j = 0; j < Lies; j++) {
			board[i][j] = set;
		}
	}
}

//打印棋盘
void Displayboard(char board[hangs][lies], int Hangs, int Lies) {
	int i = 0;
	int j = 0;
	for (i = 0; i <Lies-1; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <Hangs-1; i++) {
		printf("%d ", i);
		for (j = 1; j < Lies-1; j++) {
			
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//布雷
void Setmine(char board[hangs][lies], int Hang, int Lie) {
	int x = 0;
	int y = 0;
	int setm = setmine;
	while (setm) {
		x = rand() % Hang + 1;
		y = rand() % Lie+ 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			setm--;
		}
	}
}

//扫雷
void Findmines(char show[hangs][lies], char mine[hangs][lies], int Hang, int Lie) {
	int x = 0;
	int y = 0;
	int k = 0;
	int a = 0, b = 0;
	int setm = setmine;
	while (81 - setm) {

		printf("请输入：");
		scanf_s("%d%d", &x, &y);
		if (x > 0 && x <= Hang && y > 0 && y <= Lie) {
			if (mine[x][y] == '1') {
				printf("被炸死！\n");
				break;
			}
			else {
				k = findemine(mine, x, y);
				if (k == 0) {
					for (a = x - 1; a <= x + 1; a++) {
						for (b = y - 1; b<= y + 1; b++) {
							/*x = a;
							y = b;*/
							/*findemine(mine, x, y);*/
							show[a][b] = '0';
						}
					}
					Displayboard(show, hangs, lies);
					setm += 9;
				}
				else {
					show[x][y] = k + '0';
					Displayboard(show, hangs, lies);
					setm++;
				}

			}
		}
	}
	if (81 - setm == 0)
		printf("已通关\n");
}

//找坐标周围雷数
int findemine(char board[hangs][lies], int Hang, int Lie) {
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = Hang - 1; i <= Hang + 1; i++) {
		for (j = Lie - 1; j <= Lie + 1; j++) {
			if (board[i][j] == '1')
				count++;
		}
	}
	return count;
}