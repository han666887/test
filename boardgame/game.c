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
	Initboard(board, hang, lie);//��ʼ������
	Displayboard(board, hang, lie);//��ӡ����
	char set = 0;
	while (1) {
		Pleargame(board, hang, lie);//���
		Displayboard(board, hang, lie);//���´�ӡ����
		set=Win(board, hang, lie);
		if (set == '*') {
			printf("���Ӯ\n");
			break;
		}
		else if (set == '#') {
			printf("����Ӯ\n");
			break;
		}
		Windowsgame(board, hang, lie);//����
		Displayboard(board, hang, lie);//���´�ӡ����
		set=Win(board,hang,lie);
		if (set == '*') {
			printf("���Ӯ\n");
			break;
		}
		else if (set == '#') {
			printf("����Ӯ\n");
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
			game();//����Ϸ
			break;
		case 2:
			break;
		case 3:
			printf("�������\n");
			break;
		}
	} while (k);
	return 0;
}