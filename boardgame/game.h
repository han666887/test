#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  hang  3
#define  lie  3

//初始化棋盘
void Initboard(char board[hang][lie], int Hang, int Lie);
//打印棋盘
void Displayboard(char board[hang][lie], int Hang, int Lie);
//玩家
void Pleargame(char board[hang][lie], int Hang, int Lie);
//电脑
void Windowsgame(char board[hang][lie], int Hang, int Lie);
//游戏结束
char Win(char board[hang][lie], int Hang, int Lie);