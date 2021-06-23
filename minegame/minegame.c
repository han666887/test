#define _CRT_SECURE_NO_WARNINGS
#include "mine.h"

//打印菜单
void mune() {
	printf("********************\n");
	printf("******1. play  *****\n");
	printf("******2. exit  *****\n");
	printf("********************\n");
}

//玩游戏
void game() {
	//两个二维数组
	char mine[hangs][lies] = { 0 };
	char show[hangs][lies] = { 0 };
	//初始化棋盘
	Initboard(mine, hangs, lies,'0');
	Initboard(show, hangs, lies,'*');
	//打印棋盘
	Displayboard(show, hangs, lies);
	//Displayboard(mine, hangs, lies);
	//布雷
	Setmine(mine, hang, lie);
	Displayboard(mine, hangs, lies);
	//扫雷
	Findmines(show,mine, hang, lie);


}

int main()
{
	int input = 0;
	do {
		mune();
		srand((unsigned int)time(NULL));
		scanf_s("%d", &input);
		switch(input){
		case 1:
			game();
			break;
		case 2:
			break;
		case 3:
			printf("输入错误，请从新输入：\n");
			break;
		}
	} while (input!=2);
	return 0;
}